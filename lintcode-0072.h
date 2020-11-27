#ifndef __LINTCODE_0072__
#define __LINTCODE_0072__

#include "data-types.h"


/*@72. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Example 1:
    Input:[],[]
    Output:{}
    Explanation: The binary tree is null

Example 2:
    Input:[1,2,3],[1,3,2]
    Output:{2,1,3}
    Explanation: The binary tree is as follows
                  2
                 / \
                1   3

Notice
    You may assume that duplicates do not exist in the tree.
*/
class Solution72
{
public:
    TreeNode* buildTree72(std::vector<int>& inorder, std::vector<int>& postorder) 
    {
        // write your code here
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }

        return buildTree72(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTree72(std::vector<int>& inorder, int istart, int iend, std::vector<int>& postorder, int pstart, int pend) 
    {
        if (istart > iend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[pend]);

        int idx = istart;
        while (inorder[idx] != postorder[pend]) {
            idx++;
        }

        int leftLen = idx - istart;

        // left subtree: inorder[istart]~inorder[idx-1]
        // right subtree: inorder[idx+1]~inorder[iend]
        // ledt subtree: postorder[pstart]~postorder[pstart + leftLen - 1]
        // right subtree: postorder[pstart + leftLen]~postorder[pend - 1]

        root->left = buildTree72(inorder, istart, idx - 1, postorder, pstart, pstart + leftLen - 1);
        root->right = buildTree72(inorder, idx + 1, iend, postorder, pstart + leftLen, pend - 1);

        return root;
    }
};

#endif
