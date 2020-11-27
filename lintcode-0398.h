#ifndef __LINTCODE_0398__
#define __LINTCODE_0398__

#include "data-types.h"

/*@398. Longest Continuous Increasing Subsequence II
Given an integer matrix. Find the longest increasing continuous subsequence in this matrix and return the length of it.
The longest increasing continuous subsequence here can start at any position and go up/down/left/right.

Example 1:
    Input:
        [
          [1, 2, 3, 4, 5],
          [16,17,24,23,6],
          [15,18,25,22,7],
          [14,19,20,21,8],
          [13,12,11,10,9]
        ]
    Output: 25
    Explanation: 1 -> 2 -> 3 -> 4 -> 5 -> ... -> 25 (Spiral from outside to inside.)

Example 2:
    Input:
        [
          [1, 2],
          [5, 3]
        ]
    Output: 4
    Explanation: 1 -> 2 -> 3 -> 5

Challenge
    Assume that it is a N x M matrix. Solve this problem in O(NM) time and memory.
*/
class Solution398MemoizationDFS 
{
public:
    /**
     * @param matrix: A 2D-array of integers
     * @return: an integer
     */
    int longestContinuousIncreasingSubsequence2(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        std::unordered_map<int, int> memo;
        int longest = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest = std::max(longest, dfs(matrix, memo, i, j));
            }
        }

        return longest;
    }

    int dfs(std::vector<std::vector<int>>& matrix, std::unordered_map<int, int>& memo, int x, int y) {
        int idx = matrix[0].size() * x + y;
        if (memo.count(idx)) {
            return memo[idx];
        }

        int longest = 1;
        std::vector<std::pair<int, int>> delta = { {1,0}, {0,-1},{-1, 0},{0,1} };

        for (auto p : delta) {
            int deltaX = p.first + x;
            int deltaY = p.second + y;

            if (!inside(matrix, deltaX, deltaY) || matrix[deltaX][deltaY] <= matrix[x][y]) {
                continue;
            }
            longest = std::max(longest, dfs(matrix, memo, deltaX, deltaY) + 1);
        }

        memo[idx] = longest;

        return longest;
    }

    bool inside(std::vector<std::vector<int>>& matrix, int x, int y) {

        if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) {
            return false;
        }
        return true;
    }
};

#endif

