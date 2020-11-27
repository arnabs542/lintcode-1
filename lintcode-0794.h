#ifndef __LINTCODE_0794__
#define __LINTCODE_0794__

#include "data-types.h"


/*@794. Sliding Puzzle II
On a 3x3 board, there are 8 tiles represented by the integers 1 through 8, and an empty square represented by 0.
A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
Given an initial state of the puzzle board and final state, return the least number of moves required so that the initial state to final state.
If it is impossible to move from initial state to final state, return -1.

Example 1:
    Input:
        [
         [2,8,3],
         [1,0,4],
         [7,6,5]
        ]
        [
         [1,2,3],
         [8,0,4],
         [7,6,5]
        ]
    Output:
        4
    Explanation:
        [                 [
         [2,8,3],          [2,0,3],
         [1,0,4],   -->    [1,8,4],
         [7,6,5]           [7,6,5]
        ]                 ]

        [                 [
         [2,0,3],          [0,2,3],
         [1,8,4],   -->    [1,8,4],
         [7,6,5]           [7,6,5]
        ]                 ]

        [                 [
         [0,2,3],          [1,2,3],
         [1,8,4],   -->    [0,8,4],
         [7,6,5]           [7,6,5]
        ]                 ]

        [                 [
         [1,2,3],          [1,2,3],
         [0,8,4],   -->    [8,0,4],
         [7,6,5]           [7,6,5]
        ]                 ]

Example 2:
    Input:
        [[2,3,8],[7,0,5],[1,6,4]]
        [[1,2,3],[8,0,4],[7,6,5]]
    Output:
        -1
Challenge
    How to optimize the memory?
    Can you solve it with A* algorithm?
*/
class Solution794BFS 
{
public:
    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(std::vector<std::vector<int>>& init_state, std::vector<std::vector<int>>& final_state) 
    {
        std::string source = matrixToString(init_state);
        std::string target = matrixToString(final_state);

        int step = 0;

        std::queue<std::string> q;
        std::unordered_set<std::string> visited;

        q.push(source);
        visited.insert(source);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                std::string curr = q.front();
                q.pop();

                if (curr == target) {
                    return step;
                }

                for (std::string next : getNext(curr)) {
                    if (visited.count(next)) {
                        continue;
                    }

                    q.push(next);
                    visited.insert(next);
                }
            }
            step++;
        }

        return -1;
    }

private:
    std::vector<std::pair<int, int>> direction = { {0,1}, {1, 0}, {-1, 0}, {0, -1} };

    std::string matrixToString(std::vector<std::vector<int>>& state) 
    {
        std::string result;

        for (int i = 0; i < (int)state.size(); i++) {
            for (int j = 0; j < (int)state[0].size(); j++) {
                result += std::to_string(state[i][j]);
            }
        }

        return result;
    }

    std::vector<std::string> getNext(std::string state) 
    {
        std::vector<std::string> states;

        int zeroIndex = state.find('0');
        int x = zeroIndex / 3;
        int y = zeroIndex % 3;

        for (auto p : direction) {
            int nx = x + p.first;
            int ny = y + p.second;

            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) {
                continue;
            }

            std::string chars = state;
            chars[x * 3 + y] = chars[nx * 3 + ny];
            chars[nx * 3 + ny] = '0';

            states.push_back(chars);
        }

        return states;
    }

};

#endif
