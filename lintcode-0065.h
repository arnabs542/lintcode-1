#ifndef __LINTCODE_0065__
#define __LINTCODE_0065__

#include "data-types.h"

/*@65. Median of two Sorted Arrays
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Example 1
    Input:
    A = [1,2,3,4,5,6]
    B = [2,3,4,5]
    Output: 3.5

Example 2
    Input:
    A = [1,2,3]
    B = [4,5]
    Output: 3

Challenge
    The overall run time complexity should be O(log (m+n)).

Clarification
    The definition of the median:
    The median here is equivalent to the median in the mathematical definition.
    The median is the middle of the sorted array.
    If there are n numbers in the array and n is an odd number, the median is A[(n-1)/2].
    If there are n numbers in the array and n is even, the median is (A[n / 2] + A[n / 2 + 1]) / 2.
    For example, the median of the array A=[1,2,3] is 2, and the median of the array A=[1,19] is 10.
*/
class Solution65 
{
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(std::vector<int>& A, std::vector<int>& B) 
    {
        // write your code here
        if (A.empty() && B.empty()) {
            return 0.0;
        }

        std::vector<int> mergeArray(A.size() + B.size());

        int aIdx = 0, bIdx = 0, idx = 0;

        while (aIdx < (int)A.size() && bIdx < (int)B.size()) {
            if (A[aIdx] <= B[bIdx]) {
                mergeArray[idx++] = A[aIdx++];
            }
            else {
                mergeArray[idx++] = B[bIdx++];
            }
        }

        while (aIdx < (int)A.size()) {
            mergeArray[idx++] = A[aIdx++];
        }

        while (bIdx < (int)B.size()) {
            mergeArray[idx++] = B[bIdx++];
        }

        int mSize = mergeArray.size();
        if (mSize % 2) { // odd
            return  (double)mergeArray[mSize / 2];
        }

        // even.
        return  (double)(mergeArray[mSize / 2 - 1] + mergeArray[mSize / 2]) / 2;
    }
};

class Solution65BS 
{
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(std::vector<int>& A, std::vector<int>& B) 
    {
        // write your code here
        if (A.empty() && B.empty()) {
            return 0.0;
        }

        int n = A.size(), m = B.size();

        // odd.
        if ((n + m) % 2 == 1) {
            return getKth(A, 0, n - 1, B, 0, m - 1, (m + n) / 2 + 1);
        }

        // even
        int left = getKth(A, 0, n - 1, B, 0, m - 1, (n + m) / 2);
        int right = getKth(A, 0, n - 1, B, 0, m - 1, (n + m) / 2 + 1);
        return (left + right) / 2.0;
    }

private:
    int getKth(std::vector<int>& A, int startA, int endA, std::vector<int>& B, int startB, int endB, int k) 
    {
        int lenA = endA - startA + 1;
        int lenB = endB - startB + 1;

        if (lenA > lenB) {
            return getKth(B, startB, endB, A, startA, endA, k);
        }

        if (lenA == 0) {
            return B[startB + k - 1];
        }

        if (k == 1) {
            return std::min(A[startA], B[startB]);
        }

        // bineary search
        int i = startA + std::min(lenA, k / 2) - 1;
        int j = startB + std::min(lenB, k / 2) - 1;

        if (A[i] > B[j]) {
            return getKth(A, startA, endA, B, j + 1, endB, k - (j - startB + 1));
        }
        else {
            return getKth(A, i + 1, endA, B, startB, endB, k - (i - startA + 1));
        }
    }
};

#endif

