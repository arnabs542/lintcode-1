
#ifndef __LINTCODE_0841__
#define __LINTCODE_0841__

#include "data-types.h"

/*@841. String Replace
Given two identical-sized string array A, B and a string S. All substrings A appearing in S are replaced by B.
(Notice: From left to right, it must be replaced if it can be replaced. If there are multiple alternatives, replace longer priorities.
 After the replacement of the characters can't be replaced again.)

Example 1
    Input: A = ["ab","aba"] B = ["cc","ccc"] S = "ababa"
    Output: "cccba"
    Explanation: In accordance with the rules, the substring that can be replaced is "ab" or "aba". Since "aba" is longer, we replace "aba" with "ccc".

Example 2
    Input:A = ["ab","aba"] B = ["cc","ccc"] S = "aaaaa"
    Output: "aaaaa"
    Explanation: S does not contain strings in A, so no replacement is done.

Example 3
    Input: A = ["cd","dab","ab"] B = ["cc","aaa","dd"] S = "cdab"
    Output: "ccdd"
    Explanation: From left to right, you can find the "cd" can be replaced at first, so after the replacement becomes "ccab",
                 then you can find "ab" can be replaced, so the string after the replacement is "ccdd".
Notice
    The size of each string array does not exceed 100, the total string length does not exceed 50000.
    The lengths of A [i] and B [i] are equal.
    The length of S does not exceed 50000.
    All characters are lowercase letters.
    We guarantee that the A array does not have the same string
*/
class Solution841 {
private:
    static bool Compare(std::string& a, std::string& b) 
    {
        return a.size() >= b.size();
    }

public:

    std::string stringReplace841(std::vector<std::string>& a, std::vector<std::string>& b, std::string& s)
    {
        if (a.empty() || b.empty() || s.empty() || a.size() != b.size()) {
            return s;
        }

        std::unordered_map<std::string, std::string> aTob;

        for (int i = 0; i < (int)a.size(); i++) {
            aTob[a[i]] = b[i];
        }

        std::sort(a.begin(), a.end(), Compare);

        int i = 0;
        while (i < (int)s.size()) {

            bool bFound = false;
            int j = 0;
            while (j < (int)a.size()) {
                if (s.substr(i, a[j].size()) == a[j]) {
                    bFound = true;
                    break;
                }
                j++;
            }

            if (bFound) {
                s.replace(i, a[j].size(), aTob[a[j]]);
                i += a[j].size();
            }
            else {
                i++;
            }
        }

        return s;
    }
};

#endif