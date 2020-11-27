
#ifndef __LINTCODE_0667__
#define __LINTCODE_0667__

#include "data-types.h"

/*@667. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example1
    Input: "bbbab"
    Output: 4
    Explanation: One possible longest palindromic subsequence is "bbbb".

Example2
    Input: "bbbbb"
    Output: 5
*/
//Using Dynamic Programming.
class Solution0667
{
public:
    int longestPalindromeSubseq667(std::string& s)
    {
        if (s.empty()) {
            return 0;
        }

        int size = s.size();

        std::vector<std::vector<int >> dp(s.size(), std::vector<int>(s.size()));

        for (int i = 0; i < size; i++) {
            dp[i][i] = 1;
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;

                }
                else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }

        return dp[0][size - 1];
    }
};

#endif

