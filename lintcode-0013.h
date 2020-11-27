#ifndef __LINTCODE_0013__
#define __LINTCODE_0013__

#include "data-types.h"

/*@13. Implement strStr()
For a given source string and a target string, you should output the first index(from 0) of target string in source string.
If target does not exist in source, just return -1.

Example 1:
    Input: source = "source" ,target = "target"
    Output: -1
    Explanation: If the source does not contain the target content, return - 1.

Example 2:
    Input:source = "abcdabcdefg" ,target = "bcd"
    Output: 1
    Explanation: If the source contains the target content, return the location where the target first appeared in the source.

Challenge
    O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)

Clarification
    Do I need to implement KMP Algorithm in a real interview?
    Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability.
    But make sure you confirm with the interviewer first.
*/
class Solution13_1
{
public:
    int strStr(std::string& source, std::string& target)
    {
        if (target.empty()) {
            return 0;
        }

        if (source.empty() || source.size() < target.size()) {
            return -1;
        }

        int sLength = source.size();
        int tLength = target.size();
        for (int i = 0; i + tLength <= sLength; i++) {
            if (source.substr(i, tLength) == target) {
                return i;
            }
        }

        return -1;
    }
};

class Solution13_2
{
public:
    int strStr(std::string& source, std::string& target)
    {
        if (target.empty()) {
            return 0;
        }

        if (source.empty() || source.size() < target.size()) {
            return -1;
        }

        int sLength = source.size();
        int tLength = target.size();
        for (int i = 0; i + tLength <= sLength; i++) {
            bool notEqual = false;

            for (int j = 0; j < tLength; j++) {
                if (source[i + j] != target[j]) {
                    notEqual = true;
                    break;
                }
            }
            if (!notEqual) {
                return i;
            }
        }

        return -1;
    }
};

#endif

