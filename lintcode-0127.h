#ifndef __LINTCODE_0127__
#define __LINTCODE_0127__

#include "data-types.h"

/*@127. Topological Sorting
Given an directed graph, a topological order of the graph nodes is defined as follow:
For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Challenge
Can you do it in both BFS and DFS?

Clarification
Learn more about representation of graphs

Notice
You can assume that there is at least one topological order in the graph.
*/
class Solution127
{
public:
	std::vector<DirectedGraphNode*> topSort(std::vector<DirectedGraphNode*>& graph)
	{
		if (graph.empty()) {
			return {};
		}

		std::unordered_map<DirectedGraphNode*, int> mapping;
		// calculate the in-degree.
		for (auto node : graph) {
			for (auto neighbor : node->neighbors) {
				mapping[neighbor]++;
			}
		}

		std::vector<DirectedGraphNode*> result;

		// if in-degree==0, push to queue.
		std::queue<DirectedGraphNode*> q;
		for (auto node : graph) {
			if (!mapping.count(node)) {
				q.push(node);
				result.emplace_back(node);
			}
		}

		while (!q.empty()) {
			DirectedGraphNode* node = q.front();
			q.pop();

			for (auto neighbor : node->neighbors) {
				mapping[neighbor]--;
				if (mapping[neighbor] <= 0) {
					q.push(neighbor);
					result.emplace_back(neighbor);
				}
			}
		}
		return result;
	}
};


#endif

