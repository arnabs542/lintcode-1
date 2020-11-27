#ifndef __LINTCODE_0610__
#define __LINTCODE_0610__

#include "data-types.h"

/*@610. Two Sum - Difference equals to target
Given an sorted array of integers, find two numbers that their difference equals to a target value.
return a list with two number like [num1, num2] that the difference of num1 and num2 equals to target value, and num1 is less thannum2.

Example
Example 1:
    Input: nums = [2, 7, 15, 24], target = 5
    Output: [2, 7]
    Explanation:
    (7 - 2 = 5)

Example 2:
    Input: nums = [1, 1], target = 0
    Output: [1, 1]
    Explanation:
    (1 - 1 = 0)
Notice
    It's guaranteed there is only one available solution.
    Note: Extra space is prohibited
*/
class Solution610BS 
{
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (num1 < num2)
     */
    std::vector<int> twoSum7(std::vector<int>& nums, int target) 
    {
        if (nums.empty()) {
            return {};
        }

        std::vector<int> result;

        target = abs(target);
        for (int i = 0; i < (int)nums.size(); i++) {
            int j = binarySearch(nums, i + 1, nums.size() - 1, target + nums[i]);
            if (j != -1) {
                result.push_back(nums[i]);
                result.push_back(nums[j]);

                return result;
            }
        }

        return {};
    }

private:
    int binarySearch(std::vector<int>& nums, int start, int end, int target) 
    {
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }

        if (nums[end] == target) {
            return end;
        }

        return -1;
    }
};

class Solution610BS2 
{
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (num1 < num2)
     */
    std::vector<int> twoSum7(std::vector<int>& nums, int target) 
    {
        if (nums.empty()) {
            return {};
        }

        target = abs(target);
        int j = 1;
        for (int i = 0; i < (int)nums.size(); i++) {
            j = std::max(j, i + 1);
            while (j < (int)nums.size() && nums[j] - nums[i] < target) {
                j++;
            }

            if (j >= (int)nums.size()) {
                break;
            }

            if (nums[j] - nums[i] == target) {
                return std::vector<int>{nums[i], nums[j]};
            }
        }

        return {};
    }
};

#endif

