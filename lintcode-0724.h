#ifndef __LINTCODE_0724__
#define __LINTCODE_0724__

#include "data-types.h"

/*@724. Minimum Partition
Given a set of positive integers,
write a function to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example1
    Input: nums = [1, 6, 11, 5]
    Output: 1
    Explanation:
        Subset1 = [1, 5, 6], sum of Subset1 = 12
        Subset2 = [11], sum of Subset2 = 11
        abs(11 - 12) = 1

Example2
    Input: nums = [1, 2, 3, 4]
    Output: 0
    Explanation:
        Subset1 = [1, 4], sum of Subset1 = 5
        Subset2 = [2, 3], sum of Subset2 = 5
        abs(5 - 5) = 0
*/
class Solution724DP 
{
public:
    /**
     * @param nums: the given array
     * @return: the minimum difference between their sums
     */
    int findMin(std::vector<int>& nums) 
    {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        int sum = 0;
        for (auto e : nums) {
            sum += e;
        }

        std::vector<int> dp(sum / 2 + 1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = sum / 2; j >= nums[i]; j--) {
                if (dp[j - nums[i]] + nums[i] > dp[j]) {
                    dp[j] = dp[j - nums[i]] + nums[i];
                }
                else {
                    dp[j] = dp[j];   //???
                }
            }
        }
        return abs(sum - 2 * dp[sum / 2]);
    }
};

#endif

