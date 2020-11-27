#ifndef __LINTCODE_0609__
#define __LINTCODE_0609__

#include "data-types.h"

/*@609. Two Sum - Less than or equal to target
Given an array of integers, find how many pairs in the array such that their sum is less than or equal to a specific target number. 
Please return the number of pairs.

Example 1:
    Input: nums = [2, 7, 11, 15], target = 24.
    Output: 5.
    Explanation:
        2 + 7 < 24
        2 + 11 < 24
        2 + 15 < 24
        7 + 11 < 24
        7 + 15 < 24

Example 2:
    Input: nums = [1], target = 1.
    Output: 0.
*/
class Solution609 
{
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(std::vector<int>& nums, int target) 
    {
        if (nums.size() < 2) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int result = 0;
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                result += right - left;
                left++;

            }
            else {
                right--;
            }
        }

        return result;
    }
};

#endif
