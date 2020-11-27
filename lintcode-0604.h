#ifndef __LINTCODE_0604__
#define __LINTCODE_0604__

#include "data-types.h"

/*@604. Window Sum
Given an array of n integers, and a moving window(size k),
move the window at each iteration from the start of the array,
find the sum of the element inside the window at each moving.

Example 1
    Input:array = [1,2,7,8,5], k = 3
    Output:[10,17,20]
    Explanation:
        1 + 2 + 7 = 10
        2 + 7 + 8 = 17
        7 + 8 + 5 = 20
*/
class Solution604DoublePointer 
{
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    std::vector<int> winSum(std::vector<int>& nums, int k) 
    {
        if (nums.empty() || (int)nums.size() < k) {
            return {};
        }

        std::vector<int> result;

        int i = 0, j = k;
        while (j <= (int)nums.size()) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += nums[k];
            }
            result.push_back(sum);

            i++;
            j++;
        }

        return result;
    }
};

class Solution604DoublePointer2 
{
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    std::vector<int> winSum(std::vector<int>& nums, int k) 
    {
        if (nums.empty() || k <= 0 || (int)nums.size() < k) {
            return {};
        }

        std::vector<int> result;

        int j = 1, sum = nums[0];
        for (int i = 0; i < (int)nums.size(); i++) {
            while (j < (int)nums.size() && j - i < k) {
                sum += nums[j];
                j++;
            }

            if (j - i == k) {
                result.push_back(sum);
            }
            sum = sum - nums[i];
        }

        return result;
    }
};

#endif

