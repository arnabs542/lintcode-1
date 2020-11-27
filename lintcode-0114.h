#ifndef __LINTCODE_0114__
#define __LINTCODE_0114__

#include "data-types.h"

/*@114. Unique Paths
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?

Example 1:
    Input: n = 1, m = 3
    Output: 1
    Explanation: Only one path to target position.

Example 2:
    Input:  n = 3, m = 3
    Output: 6
    Explanation:
        D : Down
        R : Right
        1) DDRR
        2) DRDR
        3) DRRD
        4) RRDD
        5) RDRD
        6) RDDR
Notice
    m and n will be at most 100.
    The answer is guaranteed to be in the range of 32-bit integers
*/
class Solution114DP 
{
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) 
    {
        // write your code here

        //state: dp[i][j]: from (0, 0) to (m, n) paths.
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        // initialize: the first column, the first row.
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // functions: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        //answer
        return dp[m - 1][n - 1];

    }
};

#endif
