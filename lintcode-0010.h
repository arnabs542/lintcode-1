#ifndef __LINTCODE_0010__
#define __LINTCODE_0010__

#include "data-types.h"

/*@10. String Permutation II
Given a string, find all permutations of it without duplicates.

Example
Example 1:

Input: "abb"
Output:
["abb", "bab", "bba"]
Example 2:

Input: "aabb"
Output:
["aabb", "abab", "baba", "bbaa", "abba", "baab"]
*/
class Solution10
{
public:
    std::vector<std::string> stringPermutation(std::string& str)
    {
        std::vector<std::string> results;
        std::vector<bool> visited(str.size(), false);

        sort(str.begin(), str.end());

        std::string subset;
        dfs(str, visited, subset, results);

        return results;
    }

private:
    void dfs(std::string& str, std::vector<bool>& visited, std::string& subset, std::vector<std::string>& results)
    {
        if (subset.size() == str.size()) {
            results.push_back(subset);
            return;
        }

        for (int i = 0; i < (int)str.size(); i++) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && str[i] == str[i - 1] && !visited[i - 1]) {
                continue;
            }

            subset.push_back(str[i]);
            visited[i] = true;
            dfs(str, visited, subset, results);
            visited[i] = false;
            subset.pop_back();
        }
    }
};


#endif

