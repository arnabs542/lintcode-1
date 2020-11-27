#ifndef __LINTCODE_0425__
#define __LINTCODE_0425__

#include "data-types.h"

/*@425. Letter Combinations of a Phone Number
Given a digit string excluded 0 and 1, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
1	2    3   4   5   6    7    8   9
   ABC	DEF GHI	JKL	MNO  PQRS TUV  WXYZ

Example 1:
    Input: "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
    Explanation:
        '2' could be 'a', 'b' or 'c'
        '3' could be 'd', 'e' or 'f'

Example 2:
    Input: "5"
    Output: ["j", "k", "l"]

Notice
    Although the answer above is in lexicographical order, your answer could be in any order you want.
*/
std::unordered_map<char, std::string> mapping = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                                  {'6', "mno"}, {'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"} };
class Solution425
{
public:
    std::vector<std::string> letterCombinations(std::string& digits)
    {
        if (digits.empty()) {
            return {};
        }

        std::vector<std::string> results;

        std::string subset;
        dfs(digits, 0, subset, results);

        return results;
    }

private:
    void dfs(std::string& digits, int index, std::string& subset, std::vector<std::string>& results)
    {
        if (index == digits.size()) {
            results.push_back(subset);
            return;
        }

        char c = digits[index];
        for (int i = 0; i < (int)mapping[c].size(); i++) {

            subset.push_back(mapping[c][i]);
            dfs(digits, index + 1, subset, results);
            subset.pop_back();
        }
    }
};


#endif

