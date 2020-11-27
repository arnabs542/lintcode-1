#ifndef __LINTCODE_0816__
#define __LINTCODE_0816__

#include "data-types.h"

/*@816. Traveling Salesman Problem
Give n cities(labeled from 1 to n), and the undirected road's cost among the cities as a three-tuple [A, B, c]
(i.e there is a road between city A and city B and the cost is c). 
We need to find the smallest cost to travel all the cities starting from 1.

Example 1
	Input:n = 3 tuple = [[1,2,1],[2,3,2],[1,3,3]]
	Output: 3
	Explanation: The shortest path is 1->2->3

Example 2
	Input:n = 1tuple = []
	Output: 0

Notice
	1.A city can only be passed once.
	2.You can assume that you can reach all the rest cities.
*/
class Solution816_1
{
public:
    int minCost(int n, std::vector<std::vector<int>>& roads)
    {
        if (roads.empty() || roads.size() == 1) {
            return 0;
        }

        std::vector<std::vector<int>> graph = constructGraph(roads, n);
        std::unordered_set<int> visited;
        int result = INT_MAX;

        visited.insert(1);
        dfs(1, n, visited, 0, graph, result);

        return result;

    }

private:
    std::vector<std::vector<int>> constructGraph(std::vector<std::vector<int>>& roads, int n)
    {
        std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                graph[i][j] = INT_MAX >> 4;
            }
        }

        for (int i = 0; i < (int)roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];

            graph[a][b] = std::min(graph[a][b], c);
            graph[b][a] = std::min(graph[b][a], c);
        }

        return graph;
    }

    void dfs(int city, int n, std::unordered_set<int>& visited, int cost, std::vector<std::vector<int>>& graph, int& result)
    {
        if (visited.size() == n) {
            result = std::min(result, cost);
            return;
        }

        for (int i = 1; i < (int)graph[city].size(); i++) {
            if (visited.count(i)) {
                continue;
            }

            visited.insert(i);
            dfs(i, n, visited, cost + graph[city][i], graph, result);
            visited.erase(i);
        }
    }
};

class Solution816_2
{
public:
    int minCost816DFSWithPrunning(int n, std::vector<std::vector<int>>& roads)
    {
        if (roads.empty() || roads.size() == 1) {
            return 0;
        }

        std::vector<std::vector<int>> graph = constructGraph(roads, n);
        std::unordered_set<int> visited;
        std::vector<int> path;
        int result = INT_MAX;

        visited.insert(1);
        path.push_back(1);
        dfsWithPrunning(1, n, visited, path, 0, graph, result);

        return result;
    }

private:
    std::vector<std::vector<int>> constructGraph(std::vector<std::vector<int>>& roads, int n)
    {
        std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                graph[i][j] = INT_MAX >> 4;
            }
        }

        for (int i = 0; i < (int)roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];

            graph[a][b] = std::min(graph[a][b], c);
            graph[b][a] = std::min(graph[b][a], c);
        }

        return graph;
    }

    void dfsWithPrunning(int city,
        int n,
        std::unordered_set<int>& visited,
        std::vector<int>& path,
        int cost,
        std::vector<std::vector<int>>& graph,
        int& result)
    {
        if (visited.size() == n) {
            result = std::min(result, cost);
            return;
        }

        for (int i = 1; i < (int)graph[city].size(); i++) {
            if (visited.count(i)) {
                continue;
            }

            if (hasBetterPath(graph, path, i)) {
                continue;
            }

            visited.insert(i);
            path.push_back(i);
            dfsWithPrunning(i, n, visited, path, cost + graph[city][i], graph, result);
            path.pop_back();
            visited.erase(i);
        }
    }

    bool hasBetterPath(std::vector<std::vector<int>>& graph, std::vector<int>& path, int city)
    {
        for (int i = 1; i < (int)path.size(); i++) {
            int A = path[i - 1];
            int B = path[i];
            int last = path.back();
            if (graph[A][B] + graph[last][city] > graph[A][last] + graph[B][city]) {
                return true;
            }
        }

        return false;
    }

};

class Solution816_3
{
public:
    int minCost816(int n, std::vector<std::vector<int>>& roads)
    {
        // Write your code here
        std::vector<std::vector<int>> graph = constructGraph(roads, n);
        int stateSize = 1 << n;
        std::vector<std::vector<int>> dp(stateSize, std::vector<int>(n + 1));

        for (int i = 0; i < stateSize; i++) {
            for (int j = 0; j < n + 1; j++) {
                dp[i][j] = INT_MAX >> 4;
            }
        }

        dp[1][1] = 0;
        for (int state = 0; state < stateSize; state++) {
            for (int i = 2; i < n + 1; i++) {

                if ((state & (1 << (i - 1))) == 0) {
                    continue;
                }

                int preState = state ^ (1 << (i - 1));
                for (int j = 1; j < n + 1; j++) {

                    if ((preState & (1 << (j - 1))) == 0) {
                        continue;
                    }

                    dp[state][i] = std::min(dp[state][i], dp[preState][j] + graph[i][j]);
                }
            }
        }

        auto pos = std::min_element(dp[stateSize - 1].begin(), dp[stateSize - 1].end());

        return *pos;
    }

private:
    std::vector<std::vector<int>> constructGraph(std::vector<std::vector<int>>& roads, int n)
    {
        std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                graph[i][j] = INT_MAX >> 4;
            }
        }

        for (int i = 0; i < (int)roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];

            graph[a][b] = std::min(graph[a][b], c);
            graph[b][a] = std::min(graph[b][a], c);
        }

        return graph;
    }
};

#endif
