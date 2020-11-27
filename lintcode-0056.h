#ifndef __LINTCODE_0056__
#define __LINTCODE_0056__

#include "data-types.h"

/*@56. Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are zero-based.

Example1:
    numbers=[2, 7, 11, 15], target=9
    return [0, 1]

Example2:
    numbers=[15, 2, 7, 11], target=9
    return [1, 2]

Challenge
    Either of the following solutions are acceptable:
    O(n) Space, O(nlogn) Time
    O(n) Space, O(n) Time

Notice
    You may assume that each input would have exactly one solution
*/
class Solution56HashMap 
{
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        if (numbers.empty()) {
            return {};
        }

        std::unordered_map<int, int> maps;
        std::vector<int> result;

        for (int i = 0; i < (int)numbers.size(); i++) {
            if (maps.count(target - numbers[i])) {
                result.push_back(maps[target - numbers[i]]);
                result.push_back(i);
                break;
            }

            maps[numbers[i]] = i;
        }

        return result;
    }
};

class Solution56TwoPointer 
{
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        if (numbers.empty()) {
            return {};
        }

        std::vector<std::pair<int, int>> maps;
        for (int i = 0; i < (int)numbers.size(); i++) {
            maps.push_back({ numbers[i], i });
        }
        sort(maps.begin(), maps.end());

        int left = 0, right = (int)maps.size() - 1;
        while (left < right) {
            if (maps[left].first + maps[right].first < target) {
                left++;

            }
            else if (maps[left].first + maps[right].first > target) {
                right--;

            }
            else {
                std::vector<int> result = { maps[left].second, maps[right].second };
                std::sort(result.begin(), result.end());
                return result;
            }
        }

        return { -1, -1 };
    }
};


#endif

