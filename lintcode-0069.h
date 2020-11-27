#ifndef __LINTCODE_0069__
#define __LINTCODE_0069__

#include "data-types.h"

/*@69.Binary Tree Level Order Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example 1:
	Input:{ 1,2,3}
	Output:[[1],[2,3]]
	Explanation:
		  1
		 / \
		2   3
		it will be serialized {1,2,3} level order traversal

Example 2:
	Input:{1,#,2,3}
	Output:[[1],[2],[3]]
	Explanation:
		1
		 \
		  2
		 /
		3
		it will be serialized {1,#,2,3}	level order traversal

Challenge
Challenge 1: Using only 1 queue to implement it.
Challenge 2: Use BFS algorithm to do it.

Notice
	The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
	The number of nodes does not exceed 20.
*/
class Solution69UsingSingleQueue
{
public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root)
	{
		if (!root) {
			return {};
		}

		std::vector<std::vector<int>> result;
		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();
			std::vector<int> level;

			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				q.pop();

				level.emplace_back(node->val);

				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			result.emplace_back(level);
		}

		return result;
	}
};

class Solution69UsingDoubleQueue
{
public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root)
	{
		if (!root) {
			return {};
		}

		std::vector<std::vector<int>> result;
		std::queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			std::queue<TreeNode*> nq;
			std::vector<int> level;

			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop();

				level.emplace_back(node->val);

				if (node->left) {
					nq.push(node->left);
				}
				if (node->right) {
					nq.push(node->right);
				}
			}
			q = nq;
			result.emplace_back(level);
		}

		return result;
	}
};

class Solution69UsingDummyNode
{
public:
	std::vector<std::vector<int>> levelOrder69(TreeNode* root)
	{
		if (!root) {
			return {};
		}

		std::vector<std::vector<int>> result;
		std::vector<int> level;

		std::queue<TreeNode*> q;
		q.push(root);
		q.push(nullptr);

		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();

			if (node == nullptr) {
				if (q.empty()) {
					if (!level.empty()) {
						result.emplace_back(level);
					}
					break;
				}
				q.push(nullptr);
				result.emplace_back(level);
				level.clear();
				continue;
			}

			level.emplace_back(node->val);
			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}

		return result;
	}
};

#endif

