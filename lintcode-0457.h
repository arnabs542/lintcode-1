#ifndef __LINTCODE_0457__
#define __LINTCODE_0457__

#include "data-types.h"

/* 457. classical Binary Search
Find any position of a target number in a sorted array. Return -1 if target does not exist.

Example
Example 1:

Input: nums = [1,2,2,4,5,5], target = 2
Output: 1 or 2
Example 2:

Input: nums = [1,2,2,4,5,5], target = 6
Output: -1
Challenge
O(logn) time
*/
class Solution457
{
public:
    int findPosition(std::vector<int>& nums, int target) 
    {
        // write your code here
        if (nums.empty()) {
            return -1;
        }

        return binarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int binarySearch(std::vector<int>& nums, int start, int end, int target) 
    {
        if (start > end) {
            return -1;
        }

        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, end, target);
        }
        else {
            return binarySearch(nums, start, mid - 1, target);
        }
    }
};

#endif

