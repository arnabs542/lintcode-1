#ifndef __LINTCODE_0148__
#define __LINTCODE_0148__

#include "data-types.h"

/*@148. Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Example 1
    Input : [1, 0, 1, 2]
    Output : [0, 1, 1, 2]
    Explanation : sort it in-place

Challenge
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
    Could you come up with an one-pass algorithm using only constant space?

Notice
    You are not suppose to use the library's sort function for this problem.
    You should do it in-place (sort numbers in the original array).
*/
class Solution148
{
public:
    void sortColors148(std::vector<int>& nums)
    {
        if (nums.empty() || nums.size() < 2) {
            return;
        }

        int left = 0, index = 0, right = nums.size() - 1;

        while (index <= right) {
            if (nums[index] == 0) {
                std::swap(nums[left], nums[index]);
                left++;
                index++;

            }
            else if (nums[index] == 2) {
                std::swap(nums[index], nums[right]);
                right--;

            }
            else {
                index++;
            }
        }
    }
};

#endif

