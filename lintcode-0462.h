#ifndef __LINTCODE_0462__
#define __LINTCODE_0462__

#include "data-types.h"


/*@462. Total Occurrence of Target
Given a target number and an integer array sorted in ascending order.
Find the total number of occurrences of target in the array.

Example1:
    Input: [1, 3, 3, 4, 5] and target = 3,
    Output: 2.

Example2:
    Input: [2, 2, 3, 4, 6] and target = 4,
    Output: 1.

Example3:
    Input: [1, 2, 3, 4, 5] and target = 6,
    Output: 0.

Challenge
    Time complexity in O(logn)
*/
class Solution462 
{
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(std::vector<int>& A, int target) {
        if (A.empty()) {
            return 0;
        }
        int firstIdx = 0, lastIdx = 0;
        int start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            // find the first one.
            if (A[mid] == target) {
                end = mid;
            }
            else if (A[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (A[start] == target) {
            firstIdx = start;
            lastIdx = start;
        }
        else if (A[end] == target) {
            firstIdx = end;
            lastIdx = end;
        }
        else {
            return 0;
        }

        start = firstIdx + 1, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            // find the last one.
            if (A[mid] == target) {
                start = mid;
            }
            else if (A[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (A[end] == target) {
            lastIdx = end;
        }
        else if (A[start] == target) {
            lastIdx = start;
        }

        return lastIdx - firstIdx + 1;
    }
};


#endif

