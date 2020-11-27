#ifndef __LINTCODE_0242__
#define __LINTCODE_0242__

#include "data-types.h"

/*@242. Convert Binary Tree to Linked Lists by Depth
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Example 1:
    Input: {1,2,3,4}
    Output: [1->null,2->3->null,4->null]
    Explanation:
            1
           / \
          2   3
         /
        4

Example 2:
    Input: {1,#,2,3}
    Output: [1->null,2->null,3->null]
    Explanation:
        1
         \
          2
         /
        3
*/
class Solution242Iterator 
{
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    std::vector<ListNode*> binaryTreeToLists(TreeNode* root) 
    {
        if (!root) {
            return {};
        }

        std::vector<ListNode*> result;
        std::queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {

            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                curr->next = new ListNode(node->val);
                curr = curr->next;

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(dummy->next);

            dummy->next = nullptr;
            delete dummy;
        }

        return result;
    }
};

class Solution242dfs 
{
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    std::vector<ListNode*> binaryTreeToLists(TreeNode* root) 
    {
        if (!root) {
            return {};
        }

        std::vector<ListNode*> result;
        dfs(root, 1, result);

        return result;
    }

private:
    void dfs(TreeNode* root, int depth, std::vector<ListNode*>& result)
    {
        if (!root) {
            return;
        }

        ListNode* node = new ListNode(root->val);
        if ((int)result.size() < depth) {
            result.push_back(node);
        }
        else {
            node->next = result[depth - 1];
            result[depth - 1] = node;
        }

        dfs(root->right, depth + 1, result);
        dfs(root->left, depth + 1, result);
    }
};

#endif

