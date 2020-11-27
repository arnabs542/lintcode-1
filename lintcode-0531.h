#ifndef __LINTCODE_0531__
#define __LINTCODE_0531__

#include "data-types.h"


/*@531. Six Degrees
Six degrees of separation is the theory that everyone and everything is six or fewer steps away,
by way of introduction,
from any other person in the world,
so that a chain of "a friend of a friend" statements can be made to connect any two people in a maximum of six steps.

Given a friendship relations, find the degrees of two people, return -1 if they can not been connected by friends of friends.

Example1
    Input: {1,2,3#2,1,4#3,1,4#4,2,3} and s = 1, t = 4
    Output: 2
    Explanation:
        1------2-----4
         \          /
          \        /
           \--3--/
Example2
    Input: {1#2,4#3,4#4,2,3} and s = 1, t = 4
    Output: -1
    Explanation:
        1      2-----4
                     /
                   /
                  3
*/
class Solution531BFS2 
{
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(std::vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) 
    {
        if (graph.empty() || !s || !t) {
            return -1;
        }

        if (s == t) {
            return 0;
        }

        int degree = 0;

        std::unordered_set<UndirectedGraphNode*> visitedS;
        std::unordered_set<UndirectedGraphNode*> visitedT;
        std::queue<UndirectedGraphNode*> queS;
        std::queue<UndirectedGraphNode*> queT;

        queS.push(s);
        visitedS.insert(s);
        queT.push(t);
        visitedT.insert(t);
        while (!queS.empty() && !queT.empty()) {

            degree++;
            int sizeS = queS.size();
            for (int i = 0; i < sizeS; i++) {
                UndirectedGraphNode* node = queS.front();
                queS.pop();

                for (auto neighbor : node->neighbors) {
                    if (visitedS.count(neighbor)) {
                        continue;
                    }

                    if (visitedT.count(neighbor)) {
                        return degree;
                    }

                    queS.push(neighbor);
                    visitedS.insert(neighbor);
                }
            }

            degree++;
            int sizeT = queT.size();
            for (int i = 0; i < sizeT; i++) {
                UndirectedGraphNode* node = queT.front();
                queT.pop();

                for (auto neighbor : node->neighbors) {
                    if (visitedT.count(neighbor)) {
                        continue;
                    }

                    if (visitedS.count(neighbor)) {
                        return degree;
                    }

                    queT.push(neighbor);
                    visitedT.insert(neighbor);
                }
            }
        }

        return -1;

    }
};

class Solution531BFS22 
{
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(std::vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) 
    {
        if (graph.empty() || !s || !t) {
            return -1;
        }

        if (s == t) {
            return 0;
        }

        int degree = 0;

        std::unordered_set<UndirectedGraphNode*> visitedS;
        std::unordered_set<UndirectedGraphNode*> visitedT;
        std::queue<UndirectedGraphNode*> queS;
        std::queue<UndirectedGraphNode*> queT;

        queS.push(s);
        visitedS.insert(s);
        queT.push(t);
        visitedT.insert(t);
        while (!queS.empty() && !queT.empty()) {

            degree++;
            int sizeS = queS.size();
            for (int i = 0; i < sizeS; i++) {
                if (extendQueue(queS, visitedS, visitedT)) {
                    return degree;
                }
            }

            degree++;
            int sizeT = queT.size();
            for (int i = 0; i < sizeT; i++) {
                if (extendQueue(queT, visitedT, visitedS)) {
                    return degree;
                }
            }
        }

        return -1;

    }

private:
    bool extendQueue(std::queue<UndirectedGraphNode*>& q,
        std::unordered_set<UndirectedGraphNode*>& visited,
        std::unordered_set<UndirectedGraphNode*>& oppositeVisited) 
    {

        UndirectedGraphNode* node = q.front();
        q.pop();

        for (auto neighbor : node->neighbors) {
            if (visited.count(neighbor)) {
                continue;
            }

            if (oppositeVisited.count(neighbor)) {
                return true;
            }

            q.push(neighbor);
            visited.insert(neighbor);
        }

        return false;
    }
};

class Solution531BFS 
{
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(std::vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) 
    {
        if (graph.empty() || !s || !t) {
            return -1;
        }

        if (s == t) {
            return 0;
        }

        int degree = 0;

        std::unordered_set<UndirectedGraphNode*> visited;
        std::queue<UndirectedGraphNode*> q;

        q.push(s);
        visited.insert(s);
        while (!q.empty()) {

            degree++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                UndirectedGraphNode* node = q.front();
                q.pop();

                if (node == t) {
                    return degree - 1; // ?????
                }

                for (auto neighbor : node->neighbors) {

                    if (visited.count(neighbor)) {
                        continue;
                    }

                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return -1;

    }
};

class Solution531BFS1 
{
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(std::vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) 
    {
        if (graph.empty() || !s || !t) {
            return -1;
        }

        if (s == t) {
            return 0;
        }

        int degree = 0;

        std::unordered_set<UndirectedGraphNode*> visited;
        std::queue<UndirectedGraphNode*> q;

        q.push(s);
        visited.insert(s);
        while (!q.empty()) {

            degree++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                UndirectedGraphNode* node = q.front();
                q.pop();

                for (auto neighbor : node->neighbors) {
                    if (neighbor == t) {
                        return degree;
                    }

                    if (visited.count(neighbor)) {
                        continue;
                    }

                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return -1;

    }
};

#endif

