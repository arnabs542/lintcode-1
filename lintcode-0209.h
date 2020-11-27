#ifndef __LINTCODE_0209__
#define __LINTCODE_0209__

#include "data-types.h"

/*@209. First Unique Character in a String
Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

Example
Example 1:
    Input: "abaccdeff"
    Output:  'b'

    Explanation:
    There is only one 'b' and it is the first one.


Example 2:
    Input: "aabccd"
    Output:  'b'

    Explanation:
    'b' is the first one.
*/
class Solution209 
{
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(std::string& str) 
    {

        std::vector<int> visited(256, 0);

        for (int i = 0; i < (int)str.size(); i++) {
            visited[str[i]]++;
        }

        for (int i = 0; i < (int)str.size(); i++) {
            if (visited[str[i]] == 1) {
                return str[i];
            }
        }

    }
};

/*Note: because we need to find the FIRST unique character,
    When we use the hashmap, we need to loop to find it through the str order.
*/
class Solution209Hashmap 
{
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(std::string& str) 
    {

        if (str.empty()) {
            return '0';
        }

        std::unordered_map<char, int> map;

        for (int i = 0; i < (int)str.size(); i++) {
            map[str[i]]++;
        }

        for (int i = 0; i < (int)str.size(); i++) {
            if (map[str[i]] == 1) {
                return str[i];
            }
        }

        return '0';
    }
};

#endif

