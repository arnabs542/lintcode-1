#ifndef __LINTCODE_0115__
#define __LINTCODE_0115__

#include "data-types.h"


/*@115. Unique Paths II
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example 1:
    Input: [[0]]
    Output: 1

Example 2:
    Input:  [[0,0,0],[0,1,0],[0,0,0]]
    Output: 2
    Explanation:
    Only 2 different path.

Notice
    m and n will be at most 100.
*/
class Solution115DP 
{
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) 
    {
        // write your code here
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            if (obstacleGrid[i][0]) {
                break;
            }
            dp[i][0] = 1;
        }

        for (int i = 0; i < col; i++) {
            if (obstacleGrid[0][i]) {
                break;
            }
            dp[0][i] = 1;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j]) {
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};

#endif

