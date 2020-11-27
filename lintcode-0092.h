#ifndef __LINTCODE_0092__
#define __LINTCODE_0092__

#include "data-types.h"


/*@92. Backpack
Given n items with size Ai, an integer m denotes the size of a backpack.
How full you can fill this backpack?

Example 1:
    Input:  [3,4,8,5], backpack size=10
    Output:  9

Example 2:
    Input:  [2,3,5,7], backpack size=12
    Output:  12

Challenge
    O(n x m) time and O(m) memory.
    O(n x m) memory is also acceptable if you do not know how to optimize memory.

Notice
    You can not divide any item into small pieces.
*/
class Solution92DP 
{
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, std::vector<int>& A) 
    {
        // write your code here
        if (A.empty() || m <= 0) {
            return -1;
        }

        int n = A.size();

        //state
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));

        //initialize
        dp[0][0] = true;

        //function
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= A[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        //answer
        for (int v = m; v >= 0; v--) {
            if (dp[n][v]) {
                return v;
            }
        }

        return -1;
    }
};

#endif

