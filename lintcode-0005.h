#ifndef __LINTCODE_0005__
#define __LINTCODE_0005__

#include "data-types.h"

/*@5. Kth Largest Element
Find K-th largest element in an array.

Example 1:
    Input: n = 1, nums = [1,3,4,2]
    Output: 4

Example 2:
    Input: n = 3, nums = [9,3,2,4,8]
    Output: 4

Challenge
    O(n) time, O(1) extra memory.

Notice
    You can swap elements in the array
*/
class Solution5QuickSelect 
{
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, std::vector<int>& nums) 
    {
        if (nums.empty()) {
            return -1;
        }

        return quickSelect(nums, 0, nums.size() - 1, n);
    }

private:
    int quickSelect(std::vector<int>& nums, int start, int end, int k) 
    {
        if (start >= end) {
            return nums[start];
        }

        int left = start, right = end;
        int pivot = nums[start + (end - start) / 2];
        while (left <= right) {
            while (left <= right && nums[left] > pivot) {
                left++;
            }

            while (left <= right && nums[right] < pivot) {
                right--;
            }

            if (left <= right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        if (start + k - 1 <= right) {
            return quickSelect(nums, start, right, k);
        }

        if (start + k - 1 >= left) {
            return quickSelect(nums, left, end, k - (left - start));
        }

        return nums[right + 1];
    }
};

class Solution5Method2 
{
public:
    int kthLargestElement(int n, std::vector<int>& nums)
    {
        if (nums.empty() || (int)nums.size() < n) {
            return -1;
        }

        std::sort(nums.begin(), nums.end());

        return nums[nums.size() - n];
    }

};

#endif

