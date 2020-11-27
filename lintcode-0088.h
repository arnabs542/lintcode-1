#ifndef __LINTCODE_0088__
#define __LINTCODE_0088__

#include "data-types.h"


/*@88. Lowest Common Ancestor of a Binary Tree
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.

Example 1:
    Input:{1},1,1
    Output:1
    Explanation:
     For the following binary tree(only one node)
             1
     LCA(1,1) = 1

Example 2:
    Input:{4,3,7,#,#,5,6},3,5
    Output:4
    Explanation:
     For the following binary tree:

          4
         / \
        3   7
           / \
          5   6

     LCA(3, 5) = 4

Notice
    Assume two nodes are exist in tree.
*/
class Soluton0088
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* A, TreeNode* B)
    {
        if (!root) {
            return nullptr;
        }

        if (root == A || root == B) {
            return root;
        }

        TreeNode* leftResult = lowestCommonAncestor(root->left, A, B);
        TreeNode* rightResult = lowestCommonAncestor(root->right, A, B);

        if (leftResult && rightResult) {
            return root;
        }

        if (leftResult || rightResult) {
            return leftResult == nullptr ? rightResult : leftResult;
        }

        return nullptr;
    }
};

#endif
