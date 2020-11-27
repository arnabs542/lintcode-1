#ifndef __LINTCODE_0034__
#define __LINTCODE_0034__

#include "data-types.h"

/*@34. N-Queens II
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

Example 1:
    Input: n=1
    Output: 1
    Explanation:
        1:
        1

Example 2:
    Input: n=4
    Output: 2
    Explanation:
        1:
            0 0 1 0
            1 0 0 0
            0 0 0 1
            0 1 0 0
        2:
            0 1 0 0
            0 0 0 1
            1 0 0 0
            0 0 1 0

*/
class Solution34DFS 
{
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) 
    {

        if (n <= 0) {
            return 0;
        }

        cnt = 0;

        dfs(0, n);

        return cnt;
    }

private:
    std::unordered_set<int> colUsed;
    std::unordered_set<int> sumUsed;
    std::unordered_set<int> diffUsed;
    int cnt;

    void dfs(int row, int n) 
    {

        if (row == n) {
            cnt++;
            return;
        }

        for (int colIndex = 0; colIndex < n; colIndex++) {
            if (!isValid(row, colIndex)) {
                continue;
            }

            colUsed.insert(colIndex);
            sumUsed.insert(colIndex + row);
            diffUsed.insert(colIndex - row);

            dfs(row + 1, n);

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
};

#endif

