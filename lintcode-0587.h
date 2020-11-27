#ifndef __LINTCODE_0587__
#define __LINTCODE_0587__

#include "data-types.h"

/*587. Two Sum - Unique pairs
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Example 1:
    Input: nums = [1,1,2,45,46,46], target = 47
    Output: 2
    Explanation:
        1 + 46 = 47
        2 + 45 = 47

Example 2:
    Input: nums = [1,1], target = 2
    Output: 1
    Explanation:
        1 + 1 = 2
*/
class Solution587
{
public:
    int twoSum(std::vector<int>& nums, int target)
    {
        if (nums.empty() || nums.size() < 2) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int cnt = 0;
        int left = 0, right = nums.size() - 1;

        while (left < right) {

            if (nums[left] + nums[right] < target) {
                left++;
            }
            else if (nums[left] + nums[right] > target) {
                right--;
            }
            else {
                cnt++;
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }

                while (left < right && nums[right] == nums[right + 1]) {
                    right++;
                }
            }
        }

        return cnt;
    }

};


#endif
