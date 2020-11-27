#ifndef __LINTCODE_0787__
#define __LINTCODE_0787__

#include "data-types.h"


/*@787. The Maze
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall.
When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space.
You may assume that the borders of the maze are all walls.
The start and destination coordinates are represented by row and column indexes.

Example 1:
    Input:
        map =
        [
         [0,0,1,0,0],
         [0,0,0,0,0],
         [0,0,0,1,0],
         [1,1,0,1,1],
         [0,0,0,0,0]
        ]
        start = [0,4]
        end = [3,2]
    Output:
        false

Example 2:
    Input:
        map =
        [[0,0,1,0,0],
         [0,0,0,0,0],
         [0,0,0,1,0],
         [1,1,0,1,1],
         [0,0,0,0,0]
        ]
        start = [0,4]
        end = [4,4]
    Output:
        true

Notice
    1.There is only one ball and one destination in the maze.
    2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
    3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
    5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/
class Solution787BFS 
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination) 
    {
        if (maze.empty() || maze[0].empty() || start.empty() || destination.empty()) {
            return false;
        }

        if (maze[destination[0]][destination[1]]) {
            return false;
        }

        if (start[0] == destination[0] && start[1] == destination[1]) {
            return true;
        }

        int n = maze.size(), m = maze[0].size();

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

        q.push({ start[0], start[1] });
        visited[start[0]][start[1]] = true;

        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();

            //found.
            if (curr.first == destination[0] && curr.second == destination[1]) {
                return true;
            }

            for (auto delta : direction) {
                int nx = curr.first;
                int ny = curr.second;

                while (isValid(maze, nx + delta.first, ny + delta.second)) { /////!!!!!!!
                    nx += delta.first;
                    ny += delta.second;
                }
                if (visited[nx][ny]) {
                    continue;
                }

                q.push({ nx, ny });
                visited[nx][ny] = true;
            }
        }

        return false;
    }

private:
    std::vector<std::pair<int, int>> direction = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

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

