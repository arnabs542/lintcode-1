#ifndef __LINTCODE_0563__
#define __LINTCODE_0563__

#include "data-types.h"

/*@563. Backpack V
Given n items with size nums[i] which an integer array and all positive numbers. 
An integer target denotes the size of a backpack. Find the number of possible fill the backpack.
Each item may only be used once

Given candidate items [1,2,3,3,7] and target 7,
A solution set is:
    [7]
    [1, 3, 3]
return 2
*/
class Solution563DP 
{
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(std::vector<int>& nums, int target) 
    {
        if (nums.empty() || target <= 0) {
            return 0;
        }

        int n = nums.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

#endif

