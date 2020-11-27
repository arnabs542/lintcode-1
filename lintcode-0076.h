#ifndef __LINTCODE_0076__
#define __LINTCODE_0076__

#include "data-types.h"

/*@@76. Longest Increasing Subsequence
Given a sequence of integers, find the longest increasing subsequence (LIS).
You code should return the length of the LIS.

Example 1:
    Input:  [5,4,1,2,3]
    Output:  3
    Explanation: LIS is [1,2,3]

Example 2:
    Input: [4,2,4,5,3,7]
    Output:  4
    Explanation: LIS is [2,4,5,7]

Challenge
    Time complexity O(n^2) or O(nlogn)

Clarification
    What's the definition of longest increasing subsequence?

The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order,
lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.
*/
class Solution76DP 
{
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::vector<int> dp(nums.size());
        int ans = 1;
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > dp[ans]) {
                ans++;
                dp[ans] = nums[i];
            }
            else {
                int left = 1;
                int right = ans;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (nums[i] <= dp[mid]) {
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                int j = left - 1;
                dp[j + 1] = std::min(nums[i], dp[j + 1]);
            }
        }

        return ans;
    }
};


#endif

