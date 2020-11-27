#ifndef __LINTCODE_1879__
#define __LINTCODE_1879__

#include "data-types.h"

/*@1879. Two Sum VII
Given an array of integers that is already sorted in ascending absolute order, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are zero-based.
You are not allowed to sort this array.

Example
    Input:
        [0,-1,2,-3,4]
        1
    Output: [[1,2],[3,4]]
    Explanation: nums[1] + nums[2] = -1 + 2 = 1, nums[3] + nums[4] = -3 + 4 = 1

You can return [[3,4],[1,2]], the system will automatically help you sort it to [[1,2],[3,4]]. But [[2,1],[3,4]] is invaild.

Challenge
    O(n) time complexity and O(1) extra space

Notice
    It is guaranteed that all numbers in the numsnums is distinct.
    The length of numsnums is <=100000.
    The number in nums is <=10^9.


*/
class Solution1879 
{
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    std::vector<std::vector<int>> twoSumVII(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;

        if (nums.empty() || nums.size() < 2) {
            return result;
        }

        int n = nums.size();
        int left = 0, right = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[right]) {
                right = i;
            }

            if (nums[i] < nums[left]) {
                left = i;
            }
        }

        while (nums[left] < nums[right]) {
            if (nums[left] + nums[right] < target) {
                left = nextLeft(left, nums);
                if (left == -1) {
                    break;
                }
            }
            else if (nums[left] + nums[right] > target) {
                right = nextRight(right, nums);
                if (right == -1) {
                    break;
                }
            }
            else {
                std::vector<int> tmp;
                if (left < right) {
                    tmp.push_back(left);
                    tmp.push_back(right);
                }
                else {
                    tmp.push_back(right);
                    tmp.push_back(left);
                }
                result.push_back(tmp);
                left = nextLeft(left, nums);
                if (left == -1) {
                    break;
                }
            }
        }

        return result;
    }

private:
    int nextLeft(int left, std::vector<int>& nums) {
        int n = nums.size();
        if (nums[left] < 0) {
            for (int i = left - 1; i >= 0; i--) {
                if (nums[i] < 0) {
                    return i;
                }
            }
            for (int i = 0; i < n; i++) {
                if (nums[i] >= 0) {
                    return i;
                }
            }

            return -1;
        }

        for (int i = left + 1; i < n; i++) {
            if (nums[i] >= 0) {
                return i;
            }
        }

        return -1;
    }

    int nextRight(int right, std::vector<int>& nums) {
        int n = nums.size();
        if (nums[right] > 0) {
            for (int i = right - 1; i >= 0; i--) {
                if (nums[i] > 0) {
                    return i;
                }
            }

            for (int i = 0; i < n; i++) {
                if (nums[i] <= 0) {
                    return i;
                }
            }
            return -1;
        }

        for (int i = right + 1; i < n; i++) {
            if (nums[i] <= 0) {
                return i;
            }
        }

        return -1;
    }
};

#endif
