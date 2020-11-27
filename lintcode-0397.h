#ifndef __LINTCODE_0397__
#define __LINTCODE_0397__

#include "data-types.h"

/*@397. Longest Continuous Increasing Subsequence
Give an integer array,find the longest increasing continuous subsequence in this array.
An increasing continuous subsequence:
Can be from right to left or from left to right.
Indices of the integers in the subsequence should be continuous.

Example 1:
    Input:[5, 4, 2, 1, 3]
    Output:4
    Explanation: For [5, 4, 2, 1, 3], the LICS  is [5, 4, 2, 1], return 4.

Example 2:
    Input: [5, 1, 2, 3, 4]
    Output: 4
    Explanation: For [5, 1, 2, 3, 4], the LICS  is [1, 2, 3, 4], return 4.

Challenge
    O(n) time and O(1) extra space.
*/
class Solution397 
{
public:
    /**
     * @param A: An array of Integer
     * @return: an integer
     */
    int longestIncreasingContinuousSubsequence(std::vector<int>& A) {
        if (A.empty()) {
            return 0;
        }

        int longest = 1, incr = 1, desc = 1;
        for (int i = 1; i < (int)A.size(); i++) {
            if (A[i] > A[i - 1]) {
                incr += 1;
                desc = 1;
            }
            else if (A[i] < A[i - 1]) {
                incr = 1;
                desc += 1;
            }
            else {
                incr = 1;
                desc = 1;
            }

            longest = std::max(longest, std::max(incr, desc));
        }

        return longest;
    }
};


#endif

