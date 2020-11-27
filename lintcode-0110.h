#ifndef __LINTCODE_0110__
#define __LINTCODE_0110__

#include "data-types.h"

/*@110. Minimum Path Sum
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Example 1:
    Input:  [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation:  Path is: 1 -> 3 -> 1 -> 1 -> 1

Example 2:
    Input:  [[1,3,2]]
    Output: 6
    Explanation:  Path is: 1 -> 3 -> 2

Notice
    You can only go right or down in the path..
*/
class Solution110 
{
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(std::vector<std::vector<int>>& grid) {

        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size(), col = grid[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(col));

        dp[0][0] = grid[0][0];
        for (int i = 1; i < row; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        for (int j = 1; j < col; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};


#endif

