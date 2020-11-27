#ifndef __LINTCODE_0192__
#define __LINTCODE_0192__

#include "data-types.h"

/*@192. Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1
    Input: "aa" "a"
    Output: false

Example 2
    Input: "aa" "aa"
    Output: true

Example 3
    Input: "aaa" "aa"
    Output: false

Example 4
    Input: "aa" "*"
    Output: true
    Explanation: '*' can replace any string

Example 5
    Input:"aa" "a*"
    Output: true

Example 6
    Input:"ab" "?*"
    Output: true
    Explanation:'?' -> 'a' '*' -> 'b'

Example 7
    Input: "aab" "c*a*b"
    Output: false

Notice
    1<=|s|, |p| <= 1000
    It is guaranteed that s only contains lowercase Latin letters and p contains lowercase Latin letters , ? and *
*/
class Solution192DP 
{
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(std::string& s, std::string& p) {
        if (s.empty() && p.empty()) {
            return true;
        }

        if (p.empty()) {
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
            return allStar(p, pIndex);
        }

        if (visited[sIndex][pIndex]) {
            return memo[sIndex][pIndex];
        }

        char sChar = s[sIndex];
        char pChar = p[pIndex];
        bool match = false;

        if (pChar == '*') {
            match = isMatchHelper(s, sIndex, p, pIndex + 1, memo, visited) ||
                isMatchHelper(s, sIndex + 1, p, pIndex, memo, visited);
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
        return (sChar == pChar || pChar == '?');
    }

    bool allStar(std::string& p, int pIndex) {
        for (int i = pIndex; i < (int)p.size(); i++) {
            if (p[i] != '*') {
                return false;
            }
        }

        return true;
    }
};

#endif

