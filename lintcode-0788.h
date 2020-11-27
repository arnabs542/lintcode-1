#ifndef __LINTCODE_0788__
#define __LINTCODE_0788__

#include "data-types.h"


/*@788. The Maze II
There is a ball in a maze with empty spaces and walls. 
The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall.
When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination.
The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls.
The start and destination coordinates are represented by row and column indexes.

Example 1:
    Input:
    (rowStart, colStart) = (0,4)
    (rowDest, colDest)= (4,4)
    0 0 1 0 0
    0 0 0 0 0
    0 0 0 1 0
    1 1 0 1 1
    0 0 0 0 0

    Output:  12

    Explanation:
    (0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(2,0)->(2,1)->(2,2)->(3,2)->(4,2)->(4,3)->(4,4)

Example 2:
    Input:
    (rowStart, colStart) = (0,4)
    (rowDest, colDest)= (0,0)
    0 0 1 0 0
    0 0 0 0 0
    0 0 0 1 0
    1 1 0 1 1
    0 0 0 0 0

    Output:  6

    Explanation:
    (0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(0,0)

Notice
    1.There is only one ball and one destination in the maze.
    2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    4.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/
class Solution788BFS 
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination) 
    {
        if (maze.empty() || maze[0].empty()) {
            return -1;
        }

        if (start[0] == destination[0] && start[1] == destination[1]) {
            return 0;
        }

        int n = maze.size(), m = maze[0].size();
        std::vector<std::vector<int>> visited(n, std::vector<int>(m, INT_MAX));
        std::queue<std::pair<int, int>> q;

        int res = INT_MAX;

        q.push({ start[0] * m + start[1], 0 });
        visited[start[0]][start[1]] = 0;
        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();

            int x = curr.first / m, y = curr.first % m;
            int d = curr.second;

            if (visited[x][y] < d) {
                continue;
            }

            if (x == destination[0] && y == destination[1]) {
                res = std::min(res, d);
                continue;
            }

            for (auto p : direction) {

                int nx = x + p.first;
                int ny = y + p.second;
                int nd = d + 1;
                while (isValid(maze, nx, ny)) {
                    nx += p.first;
                    ny += p.second;
                    nd += 1;
                }
                nx -= p.first;
                ny -= p.second;
                nd -= 1;

                if (visited[nx][ny] <= nd) {
                    continue;
                }

                q.push({ nx * m + ny, nd });
                visited[nx][ny] = nd;
            }
        }

        return res == INT_MAX ? -1 : res;
    }

private:
    std::vector<std::pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    bool isValid(std::vector<std::vector<int>>& maze, int x, int y) 
    {
        if (x < 0 || x >= (int)maze.size() || y < 0 || y >= (int)maze[0].size()) {
            return false;
        }

        if (maze[x][y]) {
            return false;
        }

        return true;
    }
};

class Solution788BFS1 
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination) 
    {
        if (maze.empty() || maze[0].empty()) {
            return -1;
        }

        if (start[0] == destination[0] && start[1] == destination[1]) {
            return 0;
        }

        int n = maze.size(), m = maze[0].size();
        std::vector<std::vector<int>> res(n, std::vector<int>(m, INT_MAX));
        std::queue<std::tuple<int, int, int>> q;

        q.push(std::tuple<int, int, int>(start[0], start[1], 0));
        while (!q.empty()) {
            std::tuple<int, int, int> curr = q.front();
            q.pop();

            int x = std::get<0>(curr), y = std::get<1>(curr), d = std::get<2>(curr);

            if (d >= res[x][y]) {
                continue;
            }
            res[x][y] = d;

            for (auto p : direction) {
                int nx = x;
                int ny = y;
                int nd = d;
                while (isValid(maze, nx, ny)) {
                    nx += p.first;
                    ny += p.second;
                    nd++;
                }
                nx -= p.first;
                ny -= p.second;
                nd--;

                q.push(std::tuple<int, int, int>(nx, ny, nd));
            }
        }

        return res[destination[0]][destination[1]] == INT_MAX ? -1 : res[destination[0]][destination[1]];
    }

private:
    std::vector<std::pair<int, int>> direction = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    bool isValid(std::vector<std::vector<int>>& maze, int x, int y) 
    {
        if (x < 0 || x >= (int)maze.size() || y < 0 || y >= (int)maze[0].size()) {
            return false;
        }

        if (maze[x][y]) {
            return false;
        }

        return true;
    }
};


#endif

