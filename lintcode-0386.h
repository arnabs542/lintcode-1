#ifndef __LINTCODE_0386__
#define __LINTCODE_0386__

#include "data-types.h"


/*@386. Longest Substring with At Most K Distinct Characters
Given a string S, find the length of the longest substring T that contains at most k distinct characters.

Example
Example 1:
    Input: S = "eceba" and k = 3
    Output: 4
    Explanation: T = "eceb"

Example 2:
    Input: S = "WORLD" and k = 4
    Output: 4
    Explanation: T = "WORL" or "ORLD"

Challenge
    O(n) time
*/
/*
class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def lengthOfLongestSubstringKDistinct(self, s, k):
        if not s:
            return 0

        counter = {}
        left = 0
        longest = 0
        for right in range(len(s)):
            counter[s[right]] = counter.get(s[right], 0) + 1
            while left <= right and len(counter) > k:
                counter[s[left]] -= 1
                if counter[s[left]] == 0:
                    del counter[s[left]]
                left += 1

            longest = max(longest, right - left + 1)
        return longest
*/
class Solution386BS 
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(std::string& s, int k) {
        if (s.empty() || k <= 0) {
            return 0;
        }

        std::vector<int> vis(256, 0);
        int start = 0, cnt = 0;
        int ans = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (vis[s[i]]++ == 0) {
                cnt++;
            }
            while (cnt > k) {
                vis[s[start]]--;
                if (vis[s[start++]] == 0) {
                    cnt--;
                }
            }
            ans = std::max(i - start + 1, ans);
        }

        return ans;
    }
};

#endif
