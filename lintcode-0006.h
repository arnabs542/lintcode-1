#ifndef __LINTCODE_0006__
#define __LINTCODE_0006__

#include "data-types.h"

/*@6. Merge Two Sorted Arrays
Merge two given sorted ascending integer array A and B into a new sorted integer array.

Example 1:
    Input:  A=[1], B=[1]
    Output: [1,1]
    Explanation:  return array merged.

Example 2:
    Input:  A=[1,2,3,4], B=[2,4,5,6]
    Output: [1,2,2,3,4,4,5,6]
    Explanation: return array merged.
Challenge
    How can you optimize your algorithm if one array is very large and the other is very small?
*/
class Solution6 
{
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    std::vector<int> mergeSortedArray(std::vector<int>& A, std::vector<int>& B) 
    {
        if (A.empty() || B.empty()) {
            return A.empty() == true ? B : A;
        }

        std::vector<int> result(A.size() + B.size());

        int n = (int)A.size(), m = (int)B.size();
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (A[i] < B[j]) {
                result[k++] = A[i++];
            }
            else {
                result[k++] = B[j++];
            }
        }

        while (i < n) {
            result[k++] = A[i++];
        }

        while (j < m) {
            result[k++] = B[j++];
        }

        return result;
    }
};

#endif

