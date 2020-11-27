#ifndef __LINTCODE_0603__
#define __LINTCODE_0603__

#include "data-types.h"

/*@603. Largest Divisible Subset
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

Example 1:
    Input: nums =  [1,2,3],
    Output: [1,2] or [1,3]

Example 2:
    Input: nums = [1,2,4,8],
    Output: [1,2,4,8]
Notice
    If there are multiple solutions, return any subset is fine.
    1 \leq len(nums) \leq 500001<=len(nums)<=50000
*/
class Solution603DP 
{
public:
    /**
     * @param nums a set of distinct positive integers
     * @return the largest subset
     */
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::unordered_map<int, int> dp;
        std::unordered_map<int, int> prev;

        for (int i = 0; i < n; i++) {
            dp[nums[i]] = 1;
            prev[nums[i]] = -1;
        }

        int lastNum = nums[0];
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int factor : getFactors(num)) {
                if (!dp.count(factor)) {
                    continue;
                }

                if (dp[num] < dp[factor] + 1) {
                    dp[num] = dp[factor] + 1;
                    prev[num] = factor;
                }
            }
            if (dp[num] > dp[lastNum]) {
                lastNum = num;
            }
        }

        return getPath(prev, lastNum);
    }

    std::vector<int> getPath(std::unordered_map<int, int>& prev, int lastNum) {
        std::vector<int> path;

        while (lastNum != -1) {
            path.push_back(lastNum);
            lastNum = prev[lastNum];
        }
        std::reverse(path.begin(), path.end());
        return path;
    }

    std::vector<int> getFactors(int num) {
        std::vector<int> factors;

        if (num == 1) {
            return factors;
        }

        int factor = 1;
        while (factor * factor <= num) {
            if (num % factor == 0) {
                factors.push_back(factor);
                if (factor != 1 && num / factor != factor) {
                    factors.push_back(num / factor);
                }
            }
            factor++;
        }

        return factors;
    }
};


#endif

