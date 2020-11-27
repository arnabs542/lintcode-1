#ifndef __LINTCODE_0440__
#define __LINTCODE_0440__

#include "data-types.h"

/*@440. Backpack III
Given n kinds of items, and each kind of item has an infinite number available. The i-th item has size A[i] and value V[i].
Also given a backpack with size m. What is the maximum value you can put into the backpack?

Example 1:
    Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10
    Output: 15
    Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.

Example 2:
    Input: A = [1, 2, 3], V = [1, 2, 3], m = 5
    Output: 5
    Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.

Notice
    You cannot divide item into small pieces.
    Total size of items you put into backpack can not exceed m.
*/
class Solution444DP 
{
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(std::vector<int>& A, std::vector<int>& V, int m) 
    {
        if (A.empty() || V.empty() || A.size() != V.size() || m <= 0) {
            return 0;
        }

        int n = A.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int count = 0; count <= j / A[i - 1]; count++) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - count * A[i - 1]] + count * V[i - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

#endif

