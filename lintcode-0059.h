#ifndef __LINTCODE_0059__
#define __LINTCODE_0059__

#include "data-types.h"


/*@59. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

Example 1:
    Input:[2,7,11,15],3
    Output:20
    Explanation: 2+7+11=20

Example 2:
    Input:[-1,2,1,-4],1
    Output:2
    Explanation: -1+2+1=2

Challenge
    O(n^2) time, O(1) extra space

Notice
    You may assume that each input would have exactly one solution.
*/
class Solution59_1 
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(std::vector<int>& numbers, int target) {
        if (numbers.empty() || numbers.size() < 3) {
            return 0;
        }

        sort(numbers.begin(), numbers.end());

        int nearest = INT_MAX;
        for (int i = 0; i < (int)numbers.size() - 2; i++) {
            if (i > 0 && numbers[i] == numbers[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = numbers.size() - 1;

            while (left < right) {
                int curr = numbers[i] + numbers[left] + numbers[right];

                if (curr == target) {
                    return target;
                }

                if (abs(curr - target) < abs(nearest - target)) {
                    nearest = curr;
                }

                if (curr > target) {
                    right -= 1;

                    while (right >= 0 && numbers[right] == numbers[right + 1]) {
                        right -= 1;
                    }
                }
                else {
                    left += 1;
                    while (left < (int)numbers.size() && numbers[left] == numbers[left - 1]) {
                        left += 1;
                    }
                }
            }
        }

        return nearest;
    }
};

class Solution59_2
{
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(std::vector<int>& numbers, int target) {
        if (numbers.empty() || numbers.size() < 3) {
            return 0;
        }

        sort(numbers.begin(), numbers.end());

        int result = INT_MAX;
        for (int i = 0; i < (int)numbers.size() - 1; i++) {
            int left = i + 1;
            int right = numbers.size() - 1;

            while (left < right) {
                int curr = numbers[i] + numbers[left] + numbers[right];
                if (abs(result - target) > abs(curr - target)) {
                    result = curr;
                }

                if (curr == target) {
                    return curr;
                }

                if (curr < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

#endif
