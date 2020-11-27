#ifndef __LINTCODE_0057__
#define __LINTCODE_0057__


#include "Lintcode.h"


/*@57
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Example 1:
    Input:[2,7,11,15]
    Output:[]

Example 2:
    Input:[-1,0,1,2,-1,-4]
    Output:[[-1, 0, 1],[-1, -1, 2]]

Notice
    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
    The solution set must not contain duplicate triplets.
*/
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& numbers)
    {
        std::vector<std::vector<int>> result;
        if (numbers.empty() || numbers.size() < 3) {
            return result;
        }

        std::sort(numbers.begin(), numbers.end());

        int size = numbers.size();
        int i = 0;
        while (i < size) {

            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                if (numbers[left] + numbers[right] < -numbers[i]) {
                    left++;
                }
                else if (numbers[left] + numbers[right] > -numbers[i]) {
                    right--;
                }
                else {
                    result.push_back({ numbers[i], numbers[left], numbers[right] });
                    left++;
                    right--;

                    while (left < right && numbers[left] == numbers[left - 1]) {
                        left++;
                    }
                    while (left < right && numbers[right] == numbers[right + 1]) {
                        right--;
                    }
                }
            }

            i++;
            while (i < size && numbers[i] == numbers[i - 1]) {
                i++;
            }
        }

        return result;
    }
};


#endif
