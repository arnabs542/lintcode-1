#ifndef __LINTCODE_0931__
#define __LINTCODE_0931__

#include "data-types.h"

/*@931. Median of K Sorted Arrays
There are k sorted arrays nums. Find the median of the given k sorted arrays.

Example 1:
    Input:
        [[1],[2],[3]]
    Output:
        2.00
Example 2:
    Input:
        [[1,1,2],[2,4,8],[3,7,10,20]]
    Output:
        3.50
Notice
    The length of the given arrays may not equal to each other.
    The elements of the given arrays are all positive number.
    Return 0 if there are no elements in the array.
    In order to ensure time complexity, the program will be executed repeatedly.
*/
class Solution931 
{
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(std::vector<std::vector<int>>& nums) 
    {
        //if (nums.empty() || nums[0].empty()) {
        //    return 0.0;
        //}

        int n = getNumbers(nums);

        if (n == 0) {
            return 0;
        }

        if (n % 2) {
            return findKth(nums, n / 2 + 1);
        }

        return findKth(nums, n / 2) / 2.0 + findKth(nums, n / 2 + 1) / 2.0;

    }

private:
    int getNumbers(std::vector<std::vector<int>>& nums) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i].size();
        }
        return sum;
    }

    int findKth(std::vector<std::vector<int>>& nums, int k) {
        int start = 0, end = INT_MAX;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getGTE(nums, mid) >= k) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (getGTE(nums, end) >= k) {
            return end;
        }

        return start;
    }

    int getGTE(std::vector<std::vector<int>>& nums, int val) {
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += getGTE(nums[i], val);
        }

        return sum;
    }

    int getGTE(std::vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int start = 0, end = nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= val) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        if (nums[start] >= val) {
            return nums.size() - start;
        }

        if (nums[end] >= val) {
            return nums.size() - end;
        }

        return 0;
    }
};


#endif
