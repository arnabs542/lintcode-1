#ifndef __LINTCODE_0607__
#define __LINTCODE_0607__

#include "data-types.h"

/*Easy@607. Two Sum III - Data structure design
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
Example 1:

add(1); add(3); add(5);
find(4) // return true
find(7) // return false
*/
class Solution607_TwoSum
{
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
    void add(int number) {
        // write your code here
        nums.insert(number);
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        for (int num : nums) {

            int count = num == value - num ? 2 : 1;
            if (nums.count(value - num) >= count) {
                return true;
            }
        }
        return false;
    }

private:
    std::unordered_multiset<int> nums;
};

#endif

