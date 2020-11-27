#ifndef __LINTCODE_1375__
#define __LINTCODE_1375__

#include "data-types.h"

/*@1375. Substring With At Least K Distinct Characters
Given a string S with only lowercase characters.

Return the number of substrings that contains at least k distinct characters.

Example
Example 1:

Input: S = "abcabcabca", k = 4
Output: 0
Explanation: There are only three distinct characters in the string.
Example 2:

Input: S = "abcabcabcabc", k = 3
Output: 55
Explanation: Any substring whose length is not smaller than 3 contains a, b, c.
    For example, there are 10 substrings whose length are 3, "abc", "bca", "cab" ... "abc"
    There are 9 substrings whose length are 4, "abca", "bcab", "cabc" ... "cabc"
    ...
    There is 1 substring whose length is 12, "abcabcabcabc"
    So the answer is 1 + 2 + ... + 10 = 55.
Notice
    10 <= length(S) <= 1,000,000
    1 <= k <= 26
*/
class Solution1375 
{
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long kDistinctCharacters(std::string& s, int k) {
        if (s.empty() || k <= 0) {
            return 0;
        }

        int left = 0;
        std::unordered_map<int, int> counter;
        long long  answer = 0;

        for (int right = 0; right < (int)s.size(); right++) {

            counter[s[right]]++;
            while (left <= right && (int)counter.size() >= k) {
                counter[s[left]]--;
                if (counter[s[left]] == 0) {
                    counter.erase(s[left]);
                }
                left++;
            }

            if (counter.size() == k - 1 && left > 0 && !counter.count(s[left - 1])) {
                answer += left;
            }
        }

        return answer;
    }
};

#endif
