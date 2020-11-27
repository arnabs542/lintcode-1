#ifndef __LINTCODE_0802__
#define __LINTCODE_0802__

#include "data-types.h"

/*@802. Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the number 0.
You may assume that there will be only one unique solution.

Example 1:
    Given a Sudoku puzzle:
    [
        [0,0,9,7,4,8,0,0,0],
        [7,0,0,0,0,0,0,0,0],
        [0,2,0,1,0,9,0,0,0],
        [0,0,7,0,0,0,2,4,0],
        [0,6,4,0,1,0,5,9,0],
        [0,9,8,0,0,0,3,0,0],
        [0,0,0,8,0,3,0,2,0],
        [0,0,0,0,0,0,0,0,6],
        [0,0,0,2,7,5,9,0,0]
    ]
    Return its solution:
    [
        [5,1,9,7,4,8,6,3,2],
        [7,8,3,6,5,2,4,1,9],
        [4,2,6,1,3,9,8,7,5],
        [3,5,7,9,8,6,2,4,1],
        [2,6,4,3,1,7,5,9,8],
        [1,9,8,5,2,4,3,6,7],
        [9,7,5,8,6,3,1,2,4],
        [8,3,2,4,9,1,7,5,6],
        [6,4,1,2,7,5,9,8,3]
    ]
*/
class Solution802DFS 
{
public:
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(std::vector<std::vector<int>>& board) 
    {
        if (board.empty() || board[0].empty()) {
            return;
        }

        dfs(board, 0);
    }

private:
    bool dfs(std::vector<std::vector<int>>& board, int index) 
    {
        if (index == 81) {
            return true;
        }

        int x = index / 9, y = index % 9;
        if (board[x][y] != 0) {
            return dfs(board, index + 1);
        }

        for (int val = 1; val <= 9; val++) {
            if (!isValid(board, x, y, val)) {
                continue;
            }

            board[x][y] = val;
            if (dfs(board, index + 1)) {
                return true;
            }

            board[x][y] = 0;
        }

        return false;
    }

    bool isValid(std::vector<std::vector<int>>& board, int x, int y, int val) 
    {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == val) {
                return false;
            }

            if (board[i][y] == val) {
                return false;
            }

            if (board[x / 3 * 3 + i / 3][y / 3 * 3 + i % 3] == val) {
                return false;
            }
        }

        return true;
    }
};

#endif