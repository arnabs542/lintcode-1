#ifndef __LINTCODE_0132__
#define __LINTCODE_0132__

#include "data-types.h"

/*@132. Word Search II
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. 
A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 
One character only be used once in one word. 
No same word in dictionary

Example 1:
    Input:["doaf","agai","dcan"],["dog","dad","dgdg","can","again"]
    Output:["again","can","dad","dog"]
    Explanation:
      d o a f
      a g a i
      d c a n
    search in Matrix,so return ["again","can","dad","dog"]
Example 2:
    Input:["a"],["b"]
    Output:[]
    Explanation:
     a
    search in Matrix,return [].

Challenge
    Using trie to implement your algorithm.
*/
class Solution132
{
public:
    std::vector<std::string> wordSearchII(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
    {
        // write your code here
        if (board.empty() || board[0].empty()) {
            return {};
        }

        std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board[0].size(), false));
        std::unordered_map<std::string, bool> prefixIsWord = getPrefixSet(words);
        std::unordered_set<std::string> wordSet;

        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[i].size(); j++) {
                visited[i][j] = true;
                std::string s;
                s += board[i][j];
                dfs(board, visited, i, j, s, prefixIsWord, wordSet);
                visited[i][j] = false;
            }
        }

        std::vector<std::string> results;
        for (auto e : wordSet) {
            results.push_back(e);
        }

        return results;
    }

private:
    std::unordered_map<std::string, bool> getPrefixSet(std::vector<std::string>& words)
    {
        std::unordered_map<std::string, bool> prefixIsWord;

        for (std::string word : words) {
            for (int i = 0; i < (int)word.size() - 1; i++) {

                std::string prefix = word.substr(0, i + 1);

                if (!prefixIsWord.count(prefix)) {
                    prefixIsWord.insert({ prefix, false });
                }
            }

            if (prefixIsWord.count(word)) {
                prefixIsWord[word] = true;
            }
            else {
                prefixIsWord.insert({ word, true });
            }
        }

        return prefixIsWord;
    }

    void dfs(std::vector<std::vector<char>>& board,
        std::vector<std::vector<bool>>& visited,
        int x,
        int y,
        std::string& word,
        std::unordered_map<std::string, bool>& prefixIsWord,
        std::unordered_set<std::string>& wordSet)
    {

        if (!prefixIsWord.count(word)) {
            return;
        }

        if (prefixIsWord[word]) {
            wordSet.insert(std::string(word));
        }

        for (int i = 0; i < 4; i++) {
            int adjX = x + dx[i];
            int adjY = y + dy[i];

            if (!inside(board, adjX, adjY) || visited[adjX][adjY]) {
                continue;
            }

            word.push_back(board[adjX][adjY]);
            visited[adjX][adjY] = true;
            dfs(board, visited, adjX, adjY, word, prefixIsWord, wordSet);
            visited[adjX][adjY] = false;
            word.pop_back();

        }
    }

    bool inside(std::vector<std::vector<char>>& board, int x, int y)
    {
        return x >= 0 && x < (int)board.size() && y >= 0 && y < (int)board[0].size();
    }

private:
    std::vector<int> dx = { 0, 1, -1, 0 };
    std::vector<int> dy = { 1, 0, 0, -1 };
};

#endif
