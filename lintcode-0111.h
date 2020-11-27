#ifndef __LINTCODE_0111__
#define __LINTCODE_0111__

#include "data-types.h"

/*@111. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
    Input:  n = 3
    Output: 3

    Explanation:
    1) 1, 1, 1
    2) 1, 2
    3) 2, 1
    total 3.

Example 2:
    Input:  n = 1
    Output: 1

    Explanation:
    only 1 way.
*/
class Solution111DP 
{
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        std::vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


#endif

