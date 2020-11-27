#ifndef __LINTCODE_0246__
#define __LINTCODE_0246__

#include "data-types.h"

/*@246. Binary Tree Path Sum II
Your are given a binary tree in which each node contains a value. 
Design an algorithm to get all paths which sum to a given value. 
The path does not need to start or end at the root or a leaf, but it must go in a straight line down.

Example 1:
    Input:
        {1,2,3,4,#,2}
        6
    Output:
        [[2, 4],[1, 3, 2]]
    Explanation:
        The binary tree is like this:
            1
           / \
          2   3
         /   /
        4   2
        for target 6, it is obvious 2 + 4 = 6 and 1 + 3 + 2 = 6.
Example 2:
    Input:
        {1,2,3,4}
        10
    Output:
        []
    Explanation:
        The binary tree is like this:
            1
           / \
          2   3
         /
        4
    for target 10, there is no way to reach it.
*/
class Solution246dfs 
{
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    std::vector<std::vector<int>> binaryTreePathSum2(TreeNode* root, int target) 
    {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> results;
        std::vector<int> path;

        findSum(root, target, 0, path, results);

        return results;
    }

private:
    void findSum(TreeNode* root, int sum, int level, std::vector<int>& path, std::vector<std::vector<int>>& results) 
    {
        if (!root) {
            return;
        }

        int tmp = sum;
        path.push_back(root->val);
        for (int i = level; i >= 0; i--) {
            tmp -= path[i];
            if (tmp == 0) {
                results.push_back(std::vector<int>(path.begin() + i, path.end()));
            }
        }

        findSum(root->left, sum, level + 1, path, results);
        findSum(root->right, sum, level + 1, path, results);
        path.pop_back();

    }
};


#endif
