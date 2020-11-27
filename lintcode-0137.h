#ifndef __LINTCODE_0137__
#define __LINTCODE_0137__

#include "data-types.h"

/*@137. Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. Nodes are labeled uniquely.

You need to return a deep copied graph, which has the same structure as the original graph, and any changes to the new graph will not have any effect on the original graph.

Example
Example1

Input:
{1,2,4#2,1,4#4,1,2}
Output:
{1,2,4#2,1,4#4,1,2}
Explanation:
1------2
 \     |
  \    |
   \   |
	\  |
	  4
Clarification
How we serialize an undirected graph: http://www.lintcode.com/help/graph/

Notice
You need return the node with the same label as the input node.
*/
class Solution137
{
public:
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node)
	{
		if (!node) {
			return nullptr;
		}

		std::unordered_set<UndirectedGraphNode*> nodes = getNodes(node);
		std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping = cloneNodes(nodes);
		connectNeighbors(nodes, mapping);

		return mapping[node];
	}

private:
	std::unordered_set<UndirectedGraphNode*> getNodes(UndirectedGraphNode* node)
	{
		std::unordered_set<UndirectedGraphNode*> nodes;
		std::queue<UndirectedGraphNode*> q;

		q.push(node);
		nodes.insert(node);
		while (!q.empty()) {
			UndirectedGraphNode* head = q.front();
			q.pop();

			for (auto neighbor : head->neighbors) {
				if (nodes.count(neighbor)) {
					continue;
				}

				q.push(neighbor);
				nodes.insert(neighbor);
			}
		}

		return nodes;
	}

	std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cloneNodes(std::unordered_set<UndirectedGraphNode*>& nodes)
	{
		std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;

		for (auto node : nodes) {
			mapping[node] = new UndirectedGraphNode(node->label);
		}
		return mapping;
	}

	void connectNeighbors(std::unordered_set<UndirectedGraphNode*>& nodes,
		std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& mapping)
	{
		for (auto node : nodes) {
			UndirectedGraphNode* newNode = mapping[node];

			for (auto neighbor : node->neighbors) {
				UndirectedGraphNode* newNeighbor = mapping[neighbor];
				newNode->neighbors.emplace_back(newNeighbor);
			}
		}
	}

};

#endif

