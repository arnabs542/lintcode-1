#ifndef __LINTCODE_0627__
#define __LINTCODE_0627__

#include "data-types.h"

/*@627:Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

Example 1:
    Input : s = "abccccdd"
    Output : 7

Explanation :
    One longest palindrome that can be built is "dccaccd", whose length is `7`.
Notice
    Assume the length of given string will not exceed 100000.
*/
class Solution627
{
    int longestPalindrome(std::string& s)
    {
        if (s.empty()) {
            return 0;
        }

        std::unordered_map<char, int> m;

        for (int i = 0; i < (int)s.size(); i++) {
            m[s[i]]++;
        }

        int ones = 0;
        int total = 0;
        for (auto pair : m) {

            if (pair.second % 2 == 0) {
                total += pair.second;

            }
            else {
                if (pair.second > 2) {
                    total += pair.second - 1;
                }
                ones = 1;
            }
        }

        total += ones;

        return total;
    }
};

#endif

