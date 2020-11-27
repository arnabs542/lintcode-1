#ifndef __LINTCODE_0939__
#define __LINTCODE_0939__

#include "data-types.h"

/*@939. Binary Tree Kth Floor Node
Return the number of nodes in the kth layer(The layer number starts from 1 and the root node is layer 1).

Example1
    Input: root = {3,9,20,#,#,15,7}, k = 2
    Output: 2
    Explanation:
          3
         / \
        9  20
          /  \
         15   7

Example2
    Input: root = {3,1,2}, k = 1
    Output: 1
    Explanation:
          3
         / \
        1   2
*/
class Solution939BFS 
{
public:
    /**
     * @param root: the root node
     * @param k: an integer
     * @return: the number of nodes in the k-th layer of the binary tree
     */
    int kthfloorNode(TreeNode* root, int k) 
    {
        if (!root || k <= 0) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (!q.empty() && k-- > 0) {
            int size = q.size();
            count = 0;
            for (int i = 0; i < size; i++) {
                count++;
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return count;
    }
};

class Solution939BFSMethod2 
{
public:
    /**
     * @param root: the root node
     * @param k: an integer
     * @return: the number of nodes in the k-th layer of the binary tree
     */
    int kthfloorNode(TreeNode* root, int k) 
    {
        if (!root || k <= 0) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int size = 0;
        while (!q.empty() && k-- > 0) {
            size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return size;
    }
};


#endif

