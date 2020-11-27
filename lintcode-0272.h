#ifndef __LINTCODE_0272__
#define __LINTCODE_0272__

#include "data-types.h"

/*@272. Climbing Stairs II
A child is running up a staircase with n steps, and can hop either 1 step, 2 steps, or 3 steps at a time.
Implement a method to count how many possible ways the child can run up the stairs.

Example
Example 1:
    Input: 3
    Output: 4
    Explanation: 1 + 1 + 1 = 2 + 1 = 1 + 2 = 3 = 3 , there are 4 ways.

Example 2:
    Input: 4
    Output: 7
    Explanation: 1 + 1 + 1 + 1 = 1 + 1 + 2 = 1 + 2 + 1 = 2 + 1 + 1 = 2 + 2 = 1 + 3 = 3 + 1 = 4 , there are 7 ways.

Clarification
    For n=0, we think the answer is 1.
*/
class Solution272Memoization 
{
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n)
    {
        if (n <= 0) {
            return 1;
        }

        std::unordered_map<int, int> keyToSteps;

        return dfs(n, keyToSteps);
    }

    int dfs(int i, std::unordered_map<int, int>& memo)
    {
        //if (i == 0 || i == 1) {
        if (i <= 1) {
            return 1;
        }

        if (i == 2) {
            return 2;
        }

        if (memo.count(i)) {
            return memo[i];
        }

        int num = dfs(i - 1, memo) + dfs(i - 2, memo) + dfs(i - 3, memo);
        memo[i] = num;

        return num;
    }
};


class Solution272DP 
{
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n)
    {
        if (n <= 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        //state:
        std::vector<int> dp(n + 1);

        //initialize:
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        //function:
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};

class Solution272LoopDP 
{
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n)
    {
        if (n <= 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int a = 1, b = 1, c = 2;
        for (int i = 3; i < n + 1; i++) {
            int next = a + b + c;
            a = b;
            b = c;
            c = next;
        }
        return c;
    }
};



#endif

