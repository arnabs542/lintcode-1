#ifndef __LINTCODE_0200__
#define __LINTCODE_0200__

#include "data-types.h"


/*@200:Longest Palindromic Substring
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example 1:
    Input:"abcdzdcab"
    Output:"cdzdc"

Example 2:
    Input:"aba"
    Output:"aba"
Challenge
    O(n2) time is acceptable. Can you do it in O(n) time.
*/
class Solution200
{
public:
    std::string longestPalindrome200BullyI(std::string& s)
    {
        std::string result;

        if (s.empty()) {
            return result;
        }

        int length = (int)s.size();
        int start = 0, longest = 1;

        for (int left = 0; left < length; left++) {
            for (int right = length - 1; right >= 0; right--) {

                if (!isPalindrome(s, left, right)) {
                    continue;
                }

                if (right - left + 1 > longest) {
                    start = left;
                    longest = right - left + 1;
                }
            }
        }

        result = s.substr(start, longest);

        return result;
    }

    std::string longestPalindrome200BullyII(std::string& s)
    {
        std::string result;

        if (s.empty()) {
            return result;
        }

        for (int length = s.size(); length > 0; length--) {
            for (int start = 0; start + length <= (int)s.size(); start++) {

                if (isPalindrome(s, start, start + length - 1)) {
                    result = s.substr(start, length);
                    return result;
                }
            }
        }

        return result;
    }

    std::string longestPalindrome200Enumerate(std::string& s)
    {
        std::string result;

        if (s.empty()) {
            return result;
        }

        for (int i = 0; i < (int)s.size(); i++) {
            std::string oddPalindrome = getPalindrome(s, i, i);
            if (oddPalindrome.size() > result.size()) {
                result = oddPalindrome;
            }

            std::string evenPalindrome = getPalindrome(s, i, i + 1);
            if (evenPalindrome.size() > result.size()) {
                result = evenPalindrome;
            }
        }

        return result;
    }

    std::string longestPalindrome200DP(std::string& s)
    {
        if (s.empty()) {
            return s;
        }

        int n = s.size();
        std::vector<std::vector<bool>> isPalindrome(n, std::vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }

        int longest = 1, start = 0;
        for (int i = 0; i < n - 1; i++) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
            if (isPalindrome[i][i + 1]) {
                start = i;
                longest = 2;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                isPalindrome[i][j] = (isPalindrome[i + 1][j - 1] && s[i] == s[j]);
                if (isPalindrome[i][j] && j - i + 1 > longest) {
                    start = i;
                    longest = j - i + 1;
                }
            }
        }

        return s.substr(start, longest);
    }

private:
    std::string getPalindrome(std::string& s, int left, int right)
    {
        while (left >= 0 && right < (int)s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }

        return s.substr(left + 1, right - 1 - left);
    }

    bool isPalindrome(std::string& s, int left, int right)
    {
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

#endif

