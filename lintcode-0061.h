#ifndef __LINTCODE_0061__
#define __LINTCODE_0061__

#include "data-types.h"

/*@61. Search for a Range
Given a sorted array of n integers, find the starting and ending position of a given target value.
If the target is not found in the array, return [-1, -1].

Example 1:
    Input:[] 9
    Output: [-1,-1]

Example 2:
Input: [5, 7, 7, 8, 8, 10] 8
Output: [3, 4]

Challenge
    O(log n) time.
*/
class Solution61 
{
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    std::vector<int> searchRange(std::vector<int>& A, int target) 
    {
        if (A.empty()) {
            return { -1, -1 };
        }

        std::vector<int> result;

        int start = 0, end = A.size() - 1;

        // find the first one.
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
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
            result.push_back(start);
        }
        else if (A[end] == target) {
            result.push_back(end);
        }
        else {
            return { -1, -1 };
        }

        start = 0, end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
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
            result.push_back(end);
        }
        else {
            result.push_back(start);
        }

        return result;
    }
};

#endif

