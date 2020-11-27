#ifndef __LINTCODE_0683__
#define __LINTCODE_0683__

#include "data-types.h"


/*683. Word Break III
Give a dictionary of words and a sentence with all whitespace removed,
return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Example
Example1
Input:
    "CatMat"
    ["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
    Output: 3
    Explanation:
        we can form 3 sentences, as follows:
        "CatMat" = "Cat" + "Mat"
        "CatMat" = "Ca" + "tM" + "at"
        "CatMat" = "C" + "at" + "Mat"

Example1
    Input:
    "a"
    []
    Output: 0

Notice
    Ignore case
*/
class Solution683DP 
{
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(std::string& s, std::unordered_set<std::string>& dict)
    {
        if (s.empty() || dict.empty()) {
            return 0;
        }

        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        std::unordered_set<std::string> hs;

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (std::string e : dict) {
            std::transform(e.begin(), e.end(), e.begin(), ::tolower);
            hs.insert(e);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (hs.count(s.substr(i, j - i + 1))) {
                    dp[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = i; k < j; k++) {
                    dp[i][j] += dp[i][k] * dp[k + 1][j];
                }
            }
        }

        return dp[0][n - 1];
    }
};

class Solution683DP2 
{
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(std::string& s, std::unordered_set<std::string>& dict)
    {
        if (s.empty() || dict.empty()) {
            return 0;
        }

        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::unordered_set<std::string> hs;
        for (std::string e : dict) {
            std::transform(e.begin(), e.end(), e.begin(), ::tolower);
            hs.insert(e);
        }

        int n = s.size();
        std::vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (hs.count(s.substr(i, j - i + 1))) {
                    dp[j + 1] += dp[i];
                }
            }
        }

        return dp[n];
    }
};


#endif

