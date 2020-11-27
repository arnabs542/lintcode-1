#ifndef __LINTCODE_0046__
#define __LINTCODE_0046__

#include "data-types.h"


/*@46: Majority Element
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.

Example 1:
    Input: [1, 1, 1, 1, 2, 2, 2]
    Output: 1

Example 2:
    Input: [1, 1, 1, 2, 2, 2, 2]
    Output: 2

Challenge
    O(n) time and O(1) extra space

Notice
    You may assume that the array is non-empty and the majority number always exist in the array.
*/
class Solution46HashMap
{
public:
    int majorityNumber(std::vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }

        std::unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); i++) {
            m[nums[i]]++;
        }

        int major = nums[0];
        int total = 1;
        for (auto pair : m) {
            if (pair.second > total) {
                major = pair.first;
                total = pair.second;
            }
        }

        return major;
    }
};

class Solution46
{
public:
    int majorityNumber(std::vector<int>& nums)
    {
        int major = 0;
        int count = 0;

        for (auto num : nums) {
            if (count == 0) {
                major = num;
            }

            if (num == major) {
                count++;
            }
            else {
                count--;
            }
        }

        return major;
    }
};
#endif
