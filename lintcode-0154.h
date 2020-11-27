#ifndef __LINTCODE_0154__
#define __LINTCODE_0154__

#include "data-types.h"

/*@154. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(string s, string p)
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true

Example 1:
    Input:"aa","a"
    Output:false
    Explanation:
        unable to match

Example 2:
    Input:"aa","a*"
    Output:true
    Explanation:
        '*' can repeat a

*/
class Solution154DP 
{
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(std::string& s, std::string& p) {
        if (s.empty() || p.empty()) {
            return false;
        }

        std::vector<std::vector<bool>> memo(s.size(), std::vector<bool>(p.size()));
        std::vector<std::vector<bool>> visited(s.size(), std::vector<bool>(p.size()));

        return isMatchHelper(s, 0, p, 0, memo, visited);
    }

    bool isMatchHelper(std::string& s, int sIndex, std::string& p, int pIndex,
        std::vector<std::vector<bool>>& memo, std::vector<std::vector<bool>>& visited) {
        if (pIndex == p.size()) {
            return sIndex == s.size();
        }

        if (sIndex == s.size()) {
            return isEmpty(p, pIndex);
        }

        if (visited[sIndex][pIndex]) {
            return memo[sIndex][pIndex];
        }

        char sChar = s[sIndex];
        char pChar = p[pIndex];
        bool match = false;

        if (pIndex + 1 < (int)p.size() && p[pIndex + 1] == '*') {
            match = isMatchHelper(s, sIndex, p, pIndex + 2, memo, visited) ||
                charMatch(sChar, pChar) && isMatchHelper(s, sIndex + 1, p, pIndex, memo, visited);
        }
        else {
            match = charMatch(sChar, pChar) &&
                isMatchHelper(s, sIndex + 1, p, pIndex + 1, memo, visited);
        }

        visited[sIndex][pIndex] = true;
        memo[sIndex][pIndex] = match;

        return match;
    }

    bool charMatch(char sChar, char pChar) {
        return sChar == pChar || pChar == '.';
    }

    bool isEmpty(std::string& p, int pIndex) {
        for (int i = pIndex; i < (int)p.size(); i += 2) {
            if (i + 1 >= (int)p.size() || p[i + 1] != '*') {
                return false;
            }
        }

        return true;
    }
};


#endif

