#ifndef __LINTCODE_0587__
#define __LINTCODE_0587__

#include "data-types.h"



/*@453. Flatten Binary Tree to Linked List
Flatten a binary tree to a fake "linked list" in pre-order traversal.
Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example 1:
    Input:{1,2,5,3,4,#,6}
    Output:{1,#,2,#,3,#,4,#,5,#,6}
    Explanation:
         1
        / \
       2   5
      / \   \
     3   4   6

    1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Example 2:
    Input:{1}
    Output:{1}
    Explanation:
             1
             1
Challenge
    Do it in-place without any extra memory.

Notice
    Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.
*/
class Solution453_1
{
public:
    void flatten(TreeNode* root)
    {
        if (!root) {
            return;
        }

        root = divideConquer(root);
    }

private:
    TreeNode* divideConquer(TreeNode* root)
    {
        if (!root) {
            return nullptr;
        }

        TreeNode* leftSubTree = divideConquer(root->left);
        TreeNode* rightSubTree = divideConquer(root->right);

        if (leftSubTree) {
            leftSubTree->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if (rightSubTree) {
            return rightSubTree;
        }

        if (leftSubTree) {
            return leftSubTree;
        }

        return root;
    }
};

class Solution453_2 
{
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        std::stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();

            if (node->right) {
                s.push(node->right);
            }

            if (node->left) {
                s.push(node->left);
            }

            node->left = nullptr;

            if (!s.empty()) {
                node->right = s.top();
            }
            else {
                node->right = nullptr;
            }
        }
    }
};


#endif