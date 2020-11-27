#ifndef __LINTCODE_0630__
#define __LINTCODE_0630__

#include "data-types.h"

/*@630. Knight Shortest Path II
Given a knight in a chessboard n * m (a binary matrix with 0 as empty and 1 as barrier).
the knight initialze position is (0, 0) and he wants to reach position (n - 1, m - 1), Knight can only be from left to right.
Find the shortest path to the destination position, return the length of the route. Return -1 if knight can not reached.

Example 1:
    Input:[[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    Output: 3
    Explanation: [0,0]->[2,1]->[0,2]->[2,3]

Example 2:
    Input: [[0,1,0],[0,0,1],[0,0,0]]
    Output: -1

Clarification
    If the knight is at (x, y), he can get to the following positions in one step:
    (x + 1, y + 2)
    (x - 1, y + 2)
    (x + 2, y + 1)
    (x - 2, y + 1)
*/
class Solution630BFS2 
{
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(std::vector<std::vector<bool>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int n = grid.size(), m = grid[0].size();

        if (grid[n - 1][m - 1]) {
            return -1;
        }

        std::queue<std::pair<int, int>> forwardQue;
        std::unordered_set<int> forwardSet;
        std::queue<std::pair<int, int>> backwordQue;
        std::unordered_set<int> backwordSet;

        forwardQue.push({ 0, 0 });
        forwardSet.insert(0);
        backwordQue.push({ n - 1, m - 1 });
        backwordSet.insert((n - 1) * m + (m - 1));

        int distance = 0;
        while (!forwardQue.empty() && !backwordQue.empty()) {

            distance++;
            if (extendQueue(grid, forwardQue, forwardSet, backwordSet, true)) {
                return distance;
            }

            distance++;
            if (extendQueue(grid, backwordQue, backwordSet, forwardSet, false)) {
                return distance;
            }
        }

        return -1;
    }

private:
    std::vector<std::pair<int, int>> forwardDirection = { {1, 2}, {-1, 2}, {2, 1}, {-2, 1} };
    std::vector<std::pair<int, int>> backwardDirection = { {-1, -2}, {1, -2}, {-2, -1}, {2, -1} };

    bool extendQueue(std::vector<std::vector<bool>>& grid, std::queue<std::pair<int, int>>& q,
        std::unordered_set<int>& visited, std::unordered_set<int>& oppositeVisited, bool isForward) 
    {

        int size = q.size();
        for (int i = 0; i < size; i++) {
            std::pair<int, int> delta = q.front();
            q.pop();

            int direct = forwardDirection.size();
            for (int j = 0; j < direct; j++) {
                std::pair<int, int> p = isForward ? forwardDirection[j] : backwardDirection[j];
                int nx = delta.first + p.first;
                int ny = delta.second + p.second;

                if (!isValid(grid, visited, nx, ny)) {
                    continue;
                }

                if (oppositeVisited.count(nx * grid[0].size() + ny)) {
                    return true;
                }

                q.push({ nx, ny });
                visited.insert(nx * grid[0].size() + ny);
            }
        }

        return false;
    }

    bool isValid(std::vector<std::vector<bool>>& grid, std::unordered_set<int>& visited, int x, int y) 
    {
        if (x < 0 || x >= (int)grid.size() || y < 0 || y >= (int)grid[0].size()) {
            return false;
        }

        if (grid[x][y]) {
            return false;
        }

        if (visited.count(x * grid[0].size() + y)) {
            return false;
        }

        return true;
    }
};


class Solution630 
{
public:
    /**
     * @param grid: a chessboard included 0 and 1
     * @return: the shortest path
     */
    int shortestPath2(std::vector<std::vector<bool>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int row = grid.size(), col = grid[0].size();
        std::vector<std::pair<int, int>> delta = { {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };

        // state & initialize:
        std::vector<std::vector<int>> dp(row, std::vector<int>(col, INT_MAX));
        dp[0][0] = 0;

        // functions
        for (int j = 0; j < col; j++) {     // j(column) first!!!!
            for (int i = 0; i < row; i++) {
                if (grid[i][j]) {
                    continue;
                }

                for (auto p : delta) {
                    int x = i + p.first;
                    int y = j + p.second;

                    if (x < 0 || x >= row || y < 0 || y >= col) {
                        continue;
                    }
                    if (dp[x][y] == INT_MAX) {
                        continue;
                    }

                    dp[i][j] = std::min(dp[i][j], dp[x][y] + 1);
                }
            }
        }

        return dp[row - 1][col - 1] == INT_MAX ? -1 : dp[row - 1][col - 1];
    }
};

#endif

