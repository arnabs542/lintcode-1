#ifndef __LINTCODE_0915__
#define __LINTCODE_0915__

#include "data-types.h"

/*@915. Inorder Predecessor in BST
Given a binary search tree and a node in it, find the in-order predecessor of that node in the BST.

Example1
    Input: root = {2,1,3}, p = 1
    Output: null

Example2
    Input: root = {2,1}, p = 2
    Output: 1

Notice
    If the given node has no in-order predecessor in the tree, return null
*/
class Solution915 
{
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) {
            return nullptr;
        }

        std::vector<TreeNode*> inorderArrs;

        getInorder(root, inorderArrs);

        for (int i = 0; i < (int)inorderArrs.size(); i++) {
            if (inorderArrs[i]->val == p->val) {
                if (i == 0) {
                    break;
                }
                else {
                    return inorderArrs[i - 1];
                }
            }
        }

        return nullptr;
    }

    void getInorder(TreeNode* root, std::vector<TreeNode*>& arrs) {
        if (!root) {
            return;
        }

        getInorder(root->left, arrs);
        arrs.push_back(root);
        getInorder(root->right, arrs);
    }
};

//use BST feature: left < root < right.
class Solution915BST 
{
public:
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) 
    {
        if (!root || !p) {
            return nullptr;
        }

        TreeNode* result = nullptr;
        while (root) {
            if (root->val < p->val) {
                if (!result || root->val > result->val) {
                    result = root;
                }
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        return result;
    }
};


#endif

