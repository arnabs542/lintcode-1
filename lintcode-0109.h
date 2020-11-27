#ifndef __LINTCODE_0109__
#define __LINTCODE_0109__

#include "data-types.h"

/*@109. Triangle
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.

Example 1:
    Input the following triangle:
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    Output: 11
    Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Example 2:
    Input the following triangle:
    [
         [2],
        [3,2],
       [6,5,7],
      [4,4,8,1]
    ]
    Output: 12
    Explanation: The minimum path sum from top to bottom is 12 (i.e., 2 + 2 + 7 + 1 = 12).
Notice
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution109Traverse 
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        minimum = INT_MAX;

        traverse(triangle, 0, 0, 0);
        return minimum;
    }

    void traverse(std::vector<std::vector<int>>& triangle, int x, int y, int pathSum) 
    {
        if (x == triangle.size()) {
            minimum = std::min(minimum, pathSum);
            return;
        }

        traverse(triangle, x + 1, y, pathSum + triangle[x][y]);
        traverse(triangle, x + 1, y + 1, pathSum + triangle[x][y]);
    }

private:
    int minimum;
};

class Solution109DivideConquer 
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        // write your code here
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        return divideConquer(triangle, 0, 0);
    }

    int divideConquer(std::vector<std::vector<int>>& triangle, int x, int y) 
    {
        if (x == triangle.size()) {
            return 0;
        }

        int leftMini = divideConquer(triangle, x + 1, y);
        int rightMin = divideConquer(triangle, x + 1, y + 1);

        return std::min(leftMini, rightMin) + triangle[x][y];
    }
};

class Solution109Memoization 
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        // write your code here
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        std::unordered_map<int, int> memo;
        return divideConquer(triangle, 0, 0, memo);
    }

    int divideConquer(std::vector<std::vector<int>>& triangle, int x, int y, std::unordered_map<int, int>& memo) 
    {
        if (x == triangle.size()) {
            return 0;
        }

        if (memo.count(x * triangle[x].size() + y)) {
            return memo[x * triangle[x].size() + y];
        }

        int leftMini = divideConquer(triangle, x + 1, y, memo);
        int rightMin = divideConquer(triangle, x + 1, y + 1, memo);
        memo[x * triangle[x].size() + y] = std::min(leftMini, rightMin) + triangle[x][y];

        return memo[x * triangle[x].size() + y];
    }
};

class Solution109DPButtomToTop 
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        int n = triangle.size();

        //state: dp[i][j]: the shorest from i, j to buttom.
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        //initialize: the last row.
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        // fuction: from buttom to top. 
        //dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j].
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        //answer
        return dp[0][0];
    }
};

class Solution109DPTopToButtom 
{
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(std::vector<std::vector<int>>& triangle) 
    {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }

        int n = triangle.size();

        //state: dp[i][j]: the shorest from i, j to buttom.
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        //initialize: the last row.
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }

        // fuction: from buttom to top. 
        //dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j].
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }

        //answer
        return *(std::min_element(dp[n - 1].begin(), dp[n - 1].end()));
    }
};

#endif
