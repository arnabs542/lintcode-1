#ifndef __LINTCODE_0031__
#define __LINTCODE_0031__

#include "data-types.h"

/*Medium@31. Partition Array
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

Example 1:
	Input:[],9
	Output:0

Example 2:
	Input:[3,2,2,1],2
	Output:1
	Explanation:the real array is[1,2,2,3].So return 1

Challenge
	Can you partition the array in-place and in O(n)?

Notice
	You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
	If all elements in nums are smaller than k, then return nums.length
*/
class Solution31 {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArrayTwoPointer1(std::vector<int>& nums, int k) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }

        //int result = 0;
        int left = 0, idx = 0, n = nums.size();
        while (idx < n) {
            if (nums[idx] < k) {
                std::swap(nums[left], nums[idx]);
                idx++;
                left++;
            }
            else {
                idx++;
            }
        }
        return left;
    }

    int partitionArrayTwoPointer2(std::vector<int>& nums, int k) {
        // write your code here
        if (nums.empty()) {
            return 0;
        }

        //int result = 0;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            while (left <= right && nums[left] < k) {
                left++;
            }
            while (left <= right && nums[right] >= k) {
                right--;
            }
            if (left <= right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return left;
    }

};


#endif
