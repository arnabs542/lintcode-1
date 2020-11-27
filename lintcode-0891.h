#ifndef __LINTCODE_0891__
#define __LINTCODE_0891__

#include "data-types.h"

/*@891. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
    Input: s = "aba"
    Output: true
    Explanation: Originally a palindrome.

Example 2:
    Input: s = "abca"
    Output: true
    Explanation: Delete 'b' or 'c'.

Example 3:
    Input: s = "abc"
    Output: false
    Explanation: Deleting any letter can not make it a palindrome.

Notice
    The string will only contain lowercase characters.
    The maximum length of the string is 50000.
*/
class Solution891 
{
public:
    /**
     * @param s: a string
     * @return bool: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(std::string& s) 
    {
        if (s.size() < 2) {
            return true;
        }

        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                break;
            }
            left++;
            right--;
        }

        if (left >= right) {
            return true;
        }

        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    }

private:
    bool isPalindrome(std::string& s, int left, int right) 
    {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

class Solution891Optimize 
{
public:
    bool validPalindrome891(std::string& s)
    {
        if (s.empty() || s.size() == 1) {
            return true;
        }

        std::pair<int, int> p = findDifference(s, 0, s.size() - 1);
        if (p.first >= p.second) {
            return true;
        }

        return isPalindrome(s, p.first + 1, p.second) || isPalindrome(s, p.first, p.second - 1);

    }

private:
    std::pair<int, int> findDifference(std::string& s, int left, int right)
    {
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }

        return std::pair<int, int>(left, right);
    }

    bool isPalindrome(std::string& s, int left, int right)
    {
        std::pair<int, int> p = findDifference(s, left, right);
        return p.first >= p.second;
    }

};


#endif

