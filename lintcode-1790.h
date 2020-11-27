#ifndef __LINTCODE_1790__
#define __LINTCODE_1790__

#include "data-types.h"


/*@1790. Rotate String II
Given a string(Given in the way of char array), a right offset and a left offset, rotate the string by offset in place.
(left offest represents the offset of a string to the left,right offest represents the offset of a string to the right,
the total offset is calculated from the left offset and the right offset,split two strings at the total offset and swap positions).

Example 1:
    Input:str ="abcdefg", left = 3, right = 1
    Output:"cdefgab"
Explanation:The left offset is 3, the right offset is 1, and the total offset is left 2. Therefore,the original string moves to the left and becomes "cdefg"+ "ab".

Example 2:
    Input:str="abcdefg",left = 0, right = 0
    Output:"abcdefg"
    Explanation:The left offset is 0, the right offset is 0, and the total offset is 0. So the string remains unchanged.

Example 3:
    Input:str = "abcdefg",left = 1, right = 2
    Output:"gabcdef"
    Explanation:The left offset is 1, the right offset is 2, and the total offset is right 1. Therefore, the original string moves to the left and becomes "g" + "abcdef".
*/
class Solution1790
{
public:
    std::string RotateString1790(std::string& str, int left, int right)
    {
        if (str.empty() || left < 0 || right < 0 || left == right) {
            return str;
        }

        int Length = str.size();
        left = left % Length;
        right = right % Length;
        if (left < right) {
            str = str.substr(Length - (right - left), std::string::npos) + str.substr(0, Length - (right - left));
        }
        else {
            str = str.substr(left - right, std::string::npos) + str.substr(0, left - right);
        }

        return str;
    }
};

#endif
