#ifndef __LINTCODE_0120__
#define __LINTCODE_0120__

#include "data-types.h"


/*@120. Word Ladder
Given two words (start and end), and a dictionary, find the shortest transformation sequence from start to end, output the length of the sequence.
Transformation rule such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary. (Start and end words do not need to appear in the dictionary )

Example 1:
    Input: start = "a", end = "c", dict =["a","b","c"]
    Output: 2
    Explanation: "a"->"c"

Example 2:
    Input: start ="hit", end = "cog", dict =["hot","dot","dog","lot","log"]
    Output: 5
    Explanation: "hit"->"hot"->"dot"->"dog"->"cog"

Notice
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
*/
class Solution120BFS2 
{
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(std::string& start, std::string& end, std::unordered_set<std::string>& dict) 
    {
        // write your code here
        if (dict.empty()) {
            return -1;
        }

        if (start == end) {
            return 0;
        }

        dict.insert(start);
        dict.insert(end);
        std::unordered_map<std::string, std::unordered_set<std::string>> graph = buildGraph(dict);

        std::queue<std::string> forwardQue;
        std::unordered_set<std::string> forwardSet;
        std::queue<std::string> backwardQue;
        std::unordered_set<std::string> backwardSet;

        forwardQue.push(start);
        forwardSet.insert(start);
        backwardQue.push(end);
        backwardSet.insert(end);

        int distance = 1;  // ????
        while (!forwardQue.empty() && !backwardQue.empty()) {
            distance++;
            if (extendQueue(graph, forwardQue, forwardSet, backwardSet)) {
                return distance;
            }

            distance++;
            if (extendQueue(graph, backwardQue, backwardSet, forwardSet)) {
                return distance;
            }
        }

        return -1;
    }

private:
    bool extendQueue(std::unordered_map<std::string, std::unordered_set<std::string>>& graph,
                    std::queue<std::string>& q, 
                    std::unordered_set<std::string>& visited, 
                    std::unordered_set<std::string>& oppositeVisited) 
    {

        int size = q.size();
        for (int i = 0; i < size; i++) {
            std::string word = q.front();
            q.pop();

            for (auto nextWord : graph[word]) {
                if (visited.count(nextWord)) {
                    continue;
                }

                if (oppositeVisited.count(nextWord)) {
                    return true;
                }

                q.push(nextWord);
                visited.insert(nextWord);
            }
        }

        return false;
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> buildGraph(std::unordered_set<std::string>& dict) 
    {
        std::unordered_map<std::string, std::unordered_set<std::string>> graph;
        for (auto word : dict) {
            graph[word] = getNextWords(word, dict);
        }

        return graph;
    }

/*    std::unordered_set<std::string> getNextWords(std::string& word, std::unordered_set<std::string>& dict) 
    {
        std::string chars = "abcdefghijklmnopqrstuvwxyz";
        std::unordered_set<std::string> nextWordSets;

        int wordLen = word.size();
        for (int i = 0; i < wordLen; i++) {
            std::string nextWord = word;
            for (int j = 0; j < chars.size(); j++) {
                if (word[i] == chars[j]) {
                    continue;
                }

                nextWord[i] = chars[j];
                if (dict.count(nextWord)) {
                    nextWordSets.insert(nextWord);
                }
            }
        }

        return nextWordSets;
    }*/
    std::unordered_set<std::string> getNextWords(std::string& word, std::unordered_set<std::string>& dict)
    {
        std::unordered_set<std::string> nextWordSets;

        for (int i = 0; i < (int)word.size(); i++) {
            std::string nextWord = word;
            for (char j = 'a'; j <= 'z'; j++) {
                nextWord[i] = j;
                if (nextWord != word && dict.count(nextWord)) {
                    nextWordSets.insert(nextWord);
                }
            }
        }

        return nextWordSets;
    }
};


class Solution120_1
{
public:
    int ladderLength(std::string& start, std::string& end, std::unordered_set<std::string>& dict)
    {
        if (dict.empty()) {
            return 0;
        }
        dict.insert(end);
        std::unordered_map<std::string, int> distance;
        std::queue<std::string> q;

        q.push(start);
        distance[start] = 1;
        while (!q.empty()) {
            std::string word = q.front();
            q.pop();

            if (word == end) {
                return distance[word];
            }

            std::vector<std::string> words = getNextWords(word);
            for (auto nextWord : words) {
                if (!dict.count(nextWord) || distance.count(nextWord)) {
                    continue;
                }
                q.push(nextWord);
                distance[nextWord] = distance[word] + 1;
            }
        }

        return 0;
    }

    int ladderLengthUsingLevel(std::string& start, std::string& end, std::unordered_set<std::string>& dict)
    {
        if (dict.empty()) {
            return 0;
        }

        dict.insert(end);
        int distance = 0;
        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            int size = q.size();
            distance++;

            for (int i = 0; i < size; i++) {
                std::string word = q.front();
                q.pop();

                if (word == end) {
                    return distance;
                }

                std::vector<std::string> words = getNextWords(word);
                for (auto nextWord : words) {
                    if (!dict.count(nextWord) || visited.count(nextWord)) {
                        continue;
                    }
                    q.push(nextWord);
                    visited.insert(nextWord);
                }
            }
        }
        return 0;
    }

private:
    std::vector<std::string> getNextWords(std::string& word)
    {
        std::vector<std::string> words;
        for (int i = 0; i < (int)word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (word[i] == c) {
                    continue;
                }
                std::string newWord = word;
                newWord[i] = c;
                words.emplace_back(newWord);
            }
        }
        return words;
    }
};

#endif
