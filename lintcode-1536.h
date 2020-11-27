#ifndef __LINTCODE_1536__
#define __LINTCODE_1536__

#include "data-types.h"

/*@1536. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution1536 {
public:
    /**
     * @param nums: the array of integers
     * @param target:
     * @return: the starting and ending position
     */
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return { -1, -1 };
        }

        std::vector<int> result;
        // find the start.
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                end = mid;
            }
            else if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            result.push_back(start);
        }
        else if (nums[end] == target) {
            result.push_back(end);
        }
        else {
            return { -1, -1 };
        }

        // find the end.
        end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[end] == target) {
            result.push_back(end);
        }
        else {
            result.push_back(start);
        }

        return result;
    }
};


#endif
