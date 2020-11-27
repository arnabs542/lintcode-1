#ifndef __LINTCODE_1246__
#define __LINTCODE_1246__

#include "data-types.h"

/*@1246. Longest Repeating Character Replacement
Given a string that consists of only uppercase English letters,
you can replace any letter in the string with another letter at most k times.
Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Example1
    Input:"ABAB" 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

Example2
    Input: "AABABBA" 1
    Output: 4
    Explanation:
        Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.

Notice
    Both the string's length and k will not exceed 10^4.
*/
class Solution1246 
{
public:
    /**
     * @param s: a string
     * @param k: a integer
     * @return: return a integer
     */
    int characterReplacement(std::string& s, int k) 
    {
        if (s.empty() || k < 0 || (int)s.size() < k) {
            return 0;
        }

        int j = 0, longest = 0, maxFreq = 0;
        std::unordered_map<char, int> counter;

        for (int i = 0; i < (int)s.size(); i++) {
            while (j < (int)s.size() && j - i - maxFreq <= k) {
                counter[s[j]]++;
                maxFreq = std::max(maxFreq, counter[s[j]]);
                j++;
            }

            if (j - i - maxFreq > k) {
                longest = std::max(longest, j - i - 1);
            }
            else {
                longest = std::max(longest, j - i);
            }
            counter[s[i]]--;
        }

        return longest;
    }
};

#endif

