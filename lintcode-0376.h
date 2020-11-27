#ifndef __LINTCODE_0376__
#define __LINTCODE_0376__

#include "data-types.h"

/*@376
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Example
Example 1:

Input:
{1, 2, 4, 2, 3}
5
Output : [[1, 2, 2], [1, 4]]
Explanation :
	The tree is look like this :
	1
	/ \
	2   4
	/ \
	2   3
	For sum = 5, it is obviously 1 + 2 + 2 = 1 + 4 = 5
	Example 2:

Input:
{1, 2, 4, 2, 3}
3
Output : []
Explanation:
	The tree is look like this :
	1
	/ \
	2   4
	/ \
	2   3
	Notice we need to find all paths from root node to leaf nodes.
	1 + 2 + 2 = 5, 1 + 2 + 3 = 6, 1 + 4 = 5
	There is no one satisfying it.
*/
class Solution376DFS 
{
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    std::vector<std::vector<int>> binaryTreePathSum(TreeNode* root, int target) 
    {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> results;
        std::vector<int> level;
        dfs(root, target, level, results);

        return results;
    }

private:
    void dfs(TreeNode* root, int target, std::vector<int>& level, std::vector<std::vector<int>>& results) 
    {
        if (!root) {
            return;
        }

        level.push_back(root->val);

        if (!root->left && !root->right) {
            if (root->val == target) {
                results.push_back(level);
            }
            level.pop_back();
            return;
        }

        dfs(root->left, target - root->val, level, results);
        dfs(root->right, target - root->val, level, results);
        level.pop_back();
    }
};

class Solution376DFS1 
{
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    std::vector<std::vector<int>> binaryTreePathSum(TreeNode* root, int target) 
    {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> results;
        std::vector<int> level;
        level.push_back(root->val);
        dfs(root, target - root->val, level, results);

        return results;
    }

private:
    void dfs(TreeNode* root, int target, std::vector<int>& level, std::vector<std::vector<int>>& results) 
    {
        if (!root->left && !root->right) {
            if (target == 0) {
                results.push_back(level);
            }
            return;
        }


        if (root->left) {
            level.push_back(root->left->val);
            dfs(root->left, target - root->left->val, level, results);
            level.pop_back();
        }

        if (root->right) {
            level.push_back(root->right->val);
            dfs(root->right, target - root->right->val, level, results);
            level.pop_back();
        }
    }
};

class Solution376DFS2 
{
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    std::vector<std::vector<int>> binaryTreePathSum(TreeNode* root, int target) 
    {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> results;
        std::vector<int> path;
        dfs(root, target, 0, path, results);

        return results;
    }

private:
    void dfs(TreeNode* root, int target, int sum, std::vector<int>& path, std::vector<std::vector<int>>& results) 
    {
        if (!root) {
            return;
        }

        path.push_back(root->val);
        sum += root->val;

        if (!root->left && !root->right && target == sum) {
            results.push_back(path);
        }

        dfs(root->left, target, sum, path, results);
        dfs(root->right, target, sum, path, results);

        path.pop_back();

    }
};


#endif
