#ifndef __LINTCODE_0033__
#define __LINTCODE_0033__

#include "data-types.h"

/*@33. N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other(Any two queens can't be in the same row, column, diagonal line).
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' each indicate a queen and an empty space respectively.

Example 1:
    Input:1
    Output:
       [["Q"]]

Example 2:
    Input:4
    Output:
    [
      // Solution 1
      [".Q..",
       "...Q",
       "Q...",
       "..Q."
      ],
      // Solution 2
      ["..Q.",
       "Q...",
       "...Q",
       ".Q.."
      ]
    ]

Challenge
    Can you do it without recursion?
*/
class Solution33DFS 
{
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    std::vector<std::vector<std::string>> solveNQueens(int n) 
    {
        std::vector<std::vector<std::string>> results;
        if (n <= 0) {
            return results;
        }

        std::vector<int> cols;
        search(results, cols, n);

        return results;
    }

private:
    void search(std::vector<std::vector<std::string>>& results, std::vector<int>& cols, int n) 
    {
        if (cols.size() == n) {
            results.push_back(draw(cols));
            return;
        }

        for (int colIndex = 0; colIndex < n; colIndex++) {
            if (!isValid(cols, colIndex)) {
                continue;
            }

            cols.push_back(colIndex);
            search(results, cols, n);
            cols.pop_back();
        }
    }

    bool isValid(std::vector<int>& cols, int col) 
    {
        int row = cols.size();
        for (int rowIndex = 0; rowIndex < row; rowIndex++) {
            if (cols[rowIndex] == col) {
                return false;
            }
            if (row + col == rowIndex + cols[rowIndex]) {
                return false;
            }
            if (row - col == rowIndex - cols[rowIndex]) {
                return false;
            }
        }

        return true;
    }

    std::vector<std::string> draw(std::vector<int>& cols) 
    {
        std::vector<std::string> result;

        for (int i = 0; i < (int)cols.size(); i++) {
            std::string row;
            for (int j = 0; j < (int)cols.size(); j++) {
                char c = cols[i] == j ? 'Q' : '.';
                row += c;
            }
            result.push_back(row);
        }

        return result;
    }
};

class Solution33DFS2 
{
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    std::vector<std::vector<std::string>> solveNQueens(int n) 
    {
        if (n <= 0) {
            return results;
        }

        board.resize(n, std::vector<char>(n, '.'));
        dfs(0, n);

        return results;
    }

private:
    std::vector<std::vector<char>> board;
    std::unordered_set<int> colUsed;
    std::unordered_set<int> sumUsed;
    std::unordered_set<int> diffUsed;
    std::vector<std::vector<std::string>> results;

    void dfs(int row, int n) 
    {

        if (row == n) {
            results.push_back(draw());
            return;
        }

        for (int colIndex = 0; colIndex < n; colIndex++) {
            if (!isValid(row, colIndex)) {
                continue;
            }

            colUsed.insert(colIndex);
            sumUsed.insert(colIndex + row);
            diffUsed.insert(colIndex - row);
            board[row][colIndex] = 'Q';

            dfs(row + 1, n);

            board[row][colIndex] = '.';
            diffUsed.erase(colIndex - row);
            sumUsed.erase(colIndex + row);
            colUsed.erase(colIndex);
        }
    }

    bool isValid(int row, int col) 
    {
        if (colUsed.count(col)) {
            return false;
        }
        if (sumUsed.count(row + col)) {
            return false;
        }
        if (diffUsed.count(col - row)) {
            return false;
        }

        return true;
    }

    std::vector<std::string> draw() 
    {
        std::vector<std::string> result;

        for (int i = 0; i < (int)board.size(); i++) {
            std::string row(board[i].begin(), board[i].end());
            result.push_back(row);
        }

        return result;
    }
};

#endif

