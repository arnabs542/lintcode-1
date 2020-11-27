#ifndef __LINTCODE_0611__
#define __LINTCODE_0611__

#include "data-types.h"

/*@611. Knight Shortest Path
Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position,
find the shortest path to a destination position, return the length of the route.
Return -1 if destination cannot be reached.

Example
    Input:
    [[0,0,0],
     [0,0,0],
     [0,0,0]]
    source = [2, 0] destination = [2, 2]
    Output: 2
    Explanation:[2,0]->[0,1]->[2,2]

Example 2:
    Input:
    [[0,1,0],
     [0,0,1],
     [0,0,0]]
    source = [2, 0] destination = [2, 2]
    Output:-1

Clarification
    If the knight is at (x, y), he can get to the following positions in one step:
    (x + 1, y + 2)
    (x + 1, y - 2)
    (x - 1, y + 2)
    (x - 1, y - 2)
    (x + 2, y + 1)
    (x + 2, y - 1)
    (x - 2, y + 1)
    (x - 2, y - 1)
Notice
    source and destination must be empty.
    Knight can not enter the barrier.
    Path length refers to the number of steps the knight takes.
*/
class Solution611BFS2 
{
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    int shortestPath(std::vector<std::vector<bool>>& grid, Point& source, Point& destination) 
    {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        if (grid[destination.x][destination.y]) {
            return -1;
        }

        if (source.x == destination.x && source.y == destination.y) {
            return 0;
        }

        int n = grid.size(), m = grid[0].size();

        std::queue<std::pair<int, int>> forwardQueue;
        std::unordered_set<int> forwardSet;
        std::queue<std::pair<int, int>> backwordQueue;
        std::unordered_set<int> backwordSet;

        forwardQueue.push({ source.x, source.y });
        forwardSet.insert(source.x * m + source.y);

        backwordQueue.push({ destination.x, destination.y });
        backwordSet.insert(destination.x * m + destination.y);

        int distance = 0;
        while (!forwardQueue.empty() && !backwordQueue.empty()) {
            distance++;
            if (extendQueue(grid, forwardQueue, forwardSet, backwordSet)) {
                return distance;
            }

            distance++;
            if (extendQueue(grid, backwordQueue, backwordSet, forwardSet)) {
                return distance;
            }
        }

        return -1;
    }

private:
    std::vector<std::pair<int, int>> direction = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };

    bool extendQueue(std::vector<std::vector<bool>>& grid, std::queue<std::pair<int, int>>& q,
        std::unordered_set<int>& visited, std::unordered_set<int>& oppositeVisited) 
    {

        int size = q.size();
        for (int i = 0; i < size; i++) {
            std::pair<int, int> delta = q.front();
            q.pop();

            for (auto p : direction) {
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


#endif

