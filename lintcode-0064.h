#ifndef __LINTCODE_0064__
#define __LINTCODE_0064__

#include "data-types.h"


/*@64. Merge Sorted Array
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Example 1:
    Input: [1, 2, 3] 3  [4,5]  2
    Output: [1,2,3,4,5]
    Explanation:
        After merge, A will be filled as [1, 2, 3, 4, 5]

Example 2:
    Input: [1,2,5] 3 [3,4] 2
    Output: [1,2,3,4,5]
    Explanation:
        After merge, A will be filled as [1, 2, 3, 4, 5]
Notice
    You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
    The number of elements initialized in A and B are m and n respectively.
*/
class Solution64 
{
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if (m < 0 || n < 0) {
            return;
        }

        std::vector<int> result(n + m, 0);
        int idx = 0;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (A[i] < B[j]) {
                result[idx++] = A[i++];
            }
            else {
                result[idx++] = B[j++];
            }
        }

        while (i < m) {
            result[idx++] = A[i++];
        }

        while (j < n) {
            result[idx++] = B[j++];
        }

        for (int k = 0; k < n + m; k++) {
            A[k] = result[k];
        }
    }
};

class Solution64Method2 
{
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        if (m < 0 || n < 0) {
            return;
        }

        int idx = m + n - 1;
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (A[i] < B[j]) {
                A[idx--] = B[j--];
            }
            else {
                A[idx--] = A[i--];
            }
        }

        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};

#endif
