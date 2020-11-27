#ifndef __LINTCODE_0415__
#define __LINTCODE_0415__

#include "data-types.h"

/*@415. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example 1:
    Input: "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama"

Example 2:
    Input: "race a car"
    Output: false
    Explanation: "raceacar"

Challenge
    O(n) time without extra memory.

Notice
    Have you consider that the string might be empty? This is a good question to ask during an interview.
    For the purpose of this problem, we define empty string as valid palindrome.
*/
class Solution415
{
public:
    bool isPalindrome(std::string& s)
    {
        if (s.empty() || s.size() == 1) {
            return true;
        }

        int left = 0, right = s.size() - 1;  // can NOT define the type as size_t.
        while (left <= right) {

            while (left <= right && !isalnum(s[left])) {
                left++;
            }

            while (left <= right && !isalnum(s[right])) {
                right--;
            }

            if (left <= right) {
                if (toupper(s[left]) != toupper(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }

        return true;
    }
};

#endif
