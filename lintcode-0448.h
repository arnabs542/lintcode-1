#ifndef __LINTCODE_0448__
#define __LINTCODE_0448__

#include "data-types.h"

/*@448. Inorder Successor in BST
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.
If the given node has no in-order successor in the tree, return null.

Example 1:
    Input: {1,#,2}, node with value 1
    Output: 2
    Explanation:
      1
       \
        2

Example 2:
    Input: {2,1,3}, node with value 1
    Output: 2
    Explanation:
        2
       / \
      1   3
    Binary Tree Representation

Challenge
    O(h), where h is the height of the BST.

Notice
    It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)
*/
// Also, we can use inorder feature to order the nodes then find the next one.
class Solution448 
{
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) {
            return nullptr;
        }

        TreeNode* successorNode = nullptr;
        while (root) {
            if (root->val <= p->val) {
                root = root->right;

            }
            else {

                if (!successorNode || successorNode->val > root->val) {
                    successorNode = root;
                }
                root = root->left;
            }
        }

        return successorNode;
    }
};

class Solution448Recursion 
{
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) {
            return nullptr;
        }

        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        }

        TreeNode* left = inorderSuccessor(root->left, p);
        if (left) {
            return left;
        }

        return root;
    }
};

class Solution448Method3 
{
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) {
            return nullptr;
        }

        TreeNode* fa = nullptr;
        while (root && root->val != p->val) {
            if (root->val < p->val) {
                root = root->right;
            }
            else {
                fa = root;
                root = root->left;
            }
        }

        if (!root || !root->right) {
            return fa;
        }

        root = root->right;
        while (root->left) {
            root = root->left;
        }

        return root;
    }
};


#endif

