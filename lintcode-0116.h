#ifndef __LINTCODE_0116__
#define __LINTCODE_0116__

#include "data-types.h"


/*@116. Jump Game
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1
    Input : [2,3,1,1,4]
    Output : true

Example 2
    Input : [3,2,1,0,4]
    Output : false

Challenge
    This problem have two method which is Greedy and Dynamic Programming.
    The time complexity of Greedy method is O(n).
    The time complexity of Dynamic Programming method is O(n^2).
    We manually set the small data set to allow you pass the test in both ways. 
    This is just to let you learn how to use this problem in dynamic programming ways. 
    If you finish it in dynamic programming ways, you can try greedy method to make it accept again.

Notice
    The array A contains n integers a1 a2,..., an (1<=ai<=5000) (1<=n<=5000)
*/
class Solution116DP 
{
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(std::vector<int>& A) 
    {
        // write your code here
        if (A.empty()) {
            return false;
        }

        std::vector<bool> dp(A.size(), false);

        dp[0] = true;

        for (int i = 0; i < (int)A.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && A[j] + j >= i) {
                    dp[i] = true;
                }
            }
        }

        return dp[A.size() - 1];
    }
};

#endif
