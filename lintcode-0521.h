#ifndef __LINTCODE_0521__
#define __LINTCODE_0521__

#include "data-types.h"

/*@521. Remove Duplicate Numbers in Array
Given an array of integers, remove the duplicate numbers in it.
You should:
Do it in place in the array.
Move the unique numbers to the front of the array.
Return the total number of the unique numbers.

Example
Example 1:
    Input: nums = [1,3,1,4,4,2]
    Output:[1,3,4,2,?,?] 4
    Explanation:
        Move duplicate integers to the tail of nums => nums = [1,3,4,2,?,?].
        Return the number of unique integers in nums => 4.
        Actually we don't care about what you place in ?, we only care about the part which has no duplicate integers.

Example 2:
    Input: nums = [1,2,3]
    Output:[1,2,3] 3

Challenge
    Do it in O(n) time complexity.
    Do it in O(nlogn) time without extra space.
Notice
    You don't need to keep the original order of the integers.
*/
class Solution521 {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(std::vector<int>& nums) 
    {
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        for (; i < (int)nums.size(); i++) {
            while (j < (int)nums.size() && nums[j] == nums[i]) {
                j++;
            }

            if (j >= (int)nums.size()) {
                break;
            }

            nums[i + 1] = nums[j];
        }

        return i + 1;
    }
};

#endif

