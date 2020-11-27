#ifndef __LINTCODE_0464__
#define __LINTCODE_0464__

#include "data-types.h"

/*@464. Sort Integers II
Given an integer array, sort it in ascending order in place. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.

Example1:
    Input: [3, 2, 1, 4, 5],
    Output: [1, 2, 3, 4, 5].

Example2:
    Input: [2, 3, 1],
    Output: [1, 2, 3].
*/
class Solution464QuickSort 
{
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(std::vector<int>& A) {
        if (A.size() < 2) {
            return;
        }

        quickSort(A, 0, A.size() - 1);
    }

private:
    void quickSort(std::vector<int>& nums, int start, int end) 
    {
        if (start >= end) {
            return;
        }

        int left = start, right = end;
        int pivot = nums[start + (right - start) / 2];    // Note 1: pivot NOT A[start] or A[end], is Value, NOT index.
        while (left <= right) {                           // Note 2: left <= right, NOT <
            while (left <= right && nums[left] < pivot) { // Note 3: A[left] < pivot, NOT <=
                left++;
            }

            while (left <= right && nums[right] > pivot) {
                right--;
            }

            if (left <= right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        quickSort(nums, start, right);
        quickSort(nums, left, end);
    }
};


#endif

