#ifndef __LINTCODE_0624__
#define __LINTCODE_0624__

#include "data-types.h"


/*@624. Remove Substrings
Given a string s and a set of n substrings.
You are supposed to remove every instance of those n substrings from s so that s is of the minimum length and output this minimum length.

Example 1:
    Input:
        "ccdaabcdbb"
        ["ab","cd"]
    Output:
        2
    Explanation:
        ccdaabcdbb -> ccdacdbb -> cabb -> cb (length = 2)

Example 2:
    Input:
        "abcabd"
        ["ab","abcd"]
    Output:
        0
    Explanation:
        abcabd -> abcd -> "" (length = 0)
*/
class Solution624 
{
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(std::string& s, std::unordered_set<std::string>& dict) 
    {
        std::unordered_map<std::string, int> visited;
        std::queue<std::string> q;

        int ans = INT_MAX;
        q.push(s);
        while (!q.empty()) {
            s = q.front();
            q.pop();

            for (auto word : dict) {
                int pos = s.find(word);
                while (pos != std::string::npos) {
                    if (s == word) {
                        ans = 0;
                        break;
                    }

                    std::string tmp = s.substr(0, pos) + s.substr(pos + word.size());
                    if (visited[tmp] == 0) {
                        visited[tmp] = 1;
                        ans = std::min(ans, (int)tmp.size());
                        q.push(tmp);
                    }

                    pos = s.find(word, pos + 1);
                }
            }
            if (ans == 0) {
                break;
            }
        }

        return ans;
    }
};

#endif

