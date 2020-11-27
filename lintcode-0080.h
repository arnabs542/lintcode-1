#ifndef __LINTCODE_0080__
#define __LINTCODE_0080__

#include "data-types.h"

/*Easy@80. Median
Given a unsorted array with integers, find the median of it.
A median is the middle number of the array after it is sorted.
If there are even numbers in the array, return the N/2-th number after sorted.

Example 1:
    Input: [4, 5, 1, 2, 3]
    Output: 3
    Explanation: After sorting, [1,2,3,4,5], the middle number is 3

Example 2:
    Input: [7, 9, 4, 5]
    Output: 5
    Explanation: After sorting, [4,5,7,9], the second(4/2) number is 5

Challenge
    O(n) time.

Notice
    The size of array is not exceed 10000
*/
class Solution80
{
public:
    int median(std::vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }

        int mid = (nums.size() + 1) / 2;

        return quickSelectAscend(nums, 0, nums.size() - 1, mid);
    }

private:
    int quickSelectAscend(std::vector<int>& nums, int start, int end, int k)
    {

        if (start == end) {
            return nums[start];
        }

        int i = start, j = end;
        int pivot = nums[(start + end) / 2];

        while (i <= j) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }

            while (i <= j && nums[j] > pivot) {
                j--;
            }

            if (i <= j) {
                std::swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        if (start + k - 1 <= j) {
            return quickSelectAscend(nums, start, j, k);
        }

        if (start + k - 1 >= i) {
            return quickSelectAscend(nums, i, end, k - (i - start));
        }

        return nums[j + 1];
    }
};

#endif

