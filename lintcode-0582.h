#ifndef __LINTCODE_0582__
#define __LINTCODE_0582__

#include "data-types.h"

/*@582. Word Break II
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.

Example 1:
    Input:"lintcode",["de","ding","co","code","lint"]
    Output:["lint code", "lint co de"]
    Explanation:
        insert a space is "lint code",insert two spaces is "lint co de".

Example 2:
    Input:"a",[]
    Output:[]
    Explanation:dict is null.
*/
class Solution582Memoization 
{
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    std::vector<std::string> wordBreak(std::string& s, std::unordered_set<std::string>& wordDict)
    {
        if (s.empty() || wordDict.empty()) {
            return {};
        }

        std::unordered_map<std::string, std::vector<std::string>> memo;

        return wordBreakerHelper(s, wordDict, memo);
    }

    std::vector<std::string> wordBreakerHelper(std::string& s,
        std::unordered_set<std::string>& dict,
        std::unordered_map<std::string, std::vector<std::string>>& memo)
    {
        if (memo.count(s)) {
            return memo[s];
        }

        std::vector<std::string> results;

        if (s.empty()) {
            return results;
        }

        if (dict.count(s)) {
            results.push_back(s);
        }

        for (int len = 1; len < (int)s.size(); len++) {
            std::string word = s.substr(0, len);
            if (!dict.count(word)) {
                continue;
            }

            std::string suffix = s.substr(len, std::string::npos);
            std::vector<std::string> segmentations = wordBreakerHelper(suffix, dict, memo);

            for (std::string e : segmentations) {
                results.push_back(word + " " + e);
            }
        }

        memo[s] = results;

        return results;
    }
};


#endif

