#ifndef __LINTCODE_0680__
#define __LINTCODE_0680__

#include "data-types.h"


/*@680. Split String
Give a string, you can choose to split the string after one character or two adjacent characters, 
and make the string to be composed of only one character or two characters. 
Output all possible results.

Example1
	Input: "123"
	Output: [["1","2","3"],["12","3"],["1","23"]]

Example2
	Input: "12345"
	Output: [["1","23","45"],["12","3","45"],["12","34","5"],["1","2","3","45"],["1","2","34","5"],["1","23","4","5"],["12","3","4","5"],["1","2","3","4","5"]]
*/
/*
Input:123

Your stdout
index = 0
sets =
results =

1 : dfs
index = 1
sets = 1,
results =

1 : dfs
index = 2
sets = 1, 2,
results =

1 : dfs
index = 3
sets = 1, 2, 3,
results =

2 : dfs
index = 3
sets = 1, 23,
results = 1, 2, 3,


2 : dfs
index = 2
sets = 12,
results = 1, 2, 3,
1, 23,


1 : dfs
index = 3
sets = 12, 3,
results = 1, 2, 3,
1, 23,
Output
[["1","23"],["12","3"],["1","2","3"]]
*/
class Solution680dfs 
{
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    std::vector<std::vector<std::string>> splitString(std::string& s) 
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> sets;

        dfs(s, 0, sets, results);

        return results;
    }

private:
    void dfs(std::string& s, int index, std::vector<std::string>& sets, std::vector<std::vector<std::string>>& results) 
    {
        /*
        cout << "index = " << index << endl;
        cout << "sets = ";
        for (auto e : sets) {
            cout << e << ", ";
        }
        cout << endl;

        cout << "results = ";
        for (auto path : results) {
            for (auto e : path)
                cout << e << ", ";
            cout << endl;
        }
        cout << endl;
        */
        if (index == s.size()) {
            results.push_back(sets);
            return;
        }

        sets.push_back(s.substr(index, 1));
        dfs(s, index + 1, sets, results);
        sets.pop_back();

        if (index + 1 < (int)s.size()) {
            sets.push_back(s.substr(index, 2));
            dfs(s, index + 2, sets, results);
            sets.pop_back();
        }
    }
};

#endif


