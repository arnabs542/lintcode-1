#ifndef __LINTCODE_0761__
#define __LINTCODE_0761__

#include "data-types.h"

/*@761. Smallest Subset
Given an array of non-negative integers.
Our task is to find minimum number of elements such that their sum should be greater than the sum of rest of the elements of the array.
At least one positive integer is in the array.

Example 1:
    Input: nums = [3, 1, 7, 1],
    Output: 1

Example 2:
    Input: nums = [2, 1, 2],
    Output: 2
*/
class Solution761 
{
public:
    /**
     * @param arr:  an array of non-negative integers
     * @return: minimum number of elements
     */
    int minElements(std::vector<int>& arr) 
    {
        if (arr.empty()) {
            return 0;
        }

        int halfSum = 0;
        for (auto e : arr) {
            halfSum += e;
        }
        halfSum = halfSum / 2;

        std::sort(arr.begin(), arr.end());

        int result = 0, currSum = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            result++;
            currSum += arr[i];
            if (currSum > halfSum) {
                break;
            }
        }

        return result;
    }
};

#endif

