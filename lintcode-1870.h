#ifndef __LINTCODE_1870__
#define __LINTCODE_1870__

#include "data-types.h"


/*@1870. number of substrings with all zeroes
Given a string str containing only0 or 1, please return the number of substrings that are consist of 0 .

Example
Example 1:
    Input:"00010011"
    Output:9
    Explanation:
        There are 5 substrings of "0",
        There are 3 substrings of "00",
        There is 1 substring of "000".
        So return 9
Example 2:
Input:"010010"
    Output:5
Notice
    1<=|str|<=30000
*/
/* double pointer : same direction*/
class Solution1870BS 
{
public:
    /**
     * @param str: the string
     * @return: the number of substrings
     */
    int stringCount(std::string& str) 
    {
        if (str.empty()) {
            return 0;
        }

        int j = 1, result = 0;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] != '0') {
                continue;
            }

            j = std::max(j, i + 1);
            while (j < (int)str.size() && str[j] == '0') {
                j++;
            }

            result += j - i;
        }

        return result;
    }
};

#endif

