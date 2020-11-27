#ifndef __LINTCODE_0594__
#define __LINTCODE_0594__

#include "data-types.h"

/*@594. strStr II : Robin Karp
Implement strStr function in O(n + m) time.
strStr return the first index of the target string in a source string. The length of the target string is m and the length of the source string is n.
If target does not exist in source, just return -1.


Example 1:
    Input:source = "abcdef", target = "bcd"
    Output:1
Explanation:
    The position of the first occurrence of a string is 1.

Example 2:
    Input:source = "abcde", target = "e"
    Output:4
Explanation:
    The position of the first occurrence of a string is 4.
*/
class Solution594
{
public:
    int strStr(const char* source, const char* target)
    {
        // write your code here
        if (source == nullptr || target == nullptr || strlen(source) < strlen(target)) {
            return -1;
        }

        std::string strSource = source;
        std::string strTarget = target;

        int n = strSource.size();
        int m = strTarget.size();

        if (m == 0) {
            return 0;
        }

        int BASE = 1000000;
        int power = 1;
        for (int i = 0; i < m; i++) {
            power = (power * 31) % BASE;
        }

        int targetCode = 0; // initialize for "".
        for (int i = 0; i < m; i++) {
            targetCode = (targetCode * 31 + strTarget[i]) % BASE;
        }

        int hashCode = 0;
        for (int i = 0; i < n; i++) {
            // abc + d
            hashCode = (hashCode * 31 + strSource[i]) % BASE;
            if (i < m - 1) {
                continue;
            }

            // abcd - a
            if (i >= m) {
                hashCode = hashCode - (strSource[i - m] * power) % BASE;
                if (hashCode < 0) {
                    hashCode = hashCode + BASE;
                }
            }

            // double check the string.
            if (hashCode == targetCode) {
                if (strSource.substr(i - m + 1, m) == strTarget) {
                    return i - m + 1;
                }
            }
        }

        return -1;
    }
};


#endif

