#ifndef __LINTCODE_0155__
#define __LINTCODE_0155__

#include "data-types.h"

/*155. Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Example 1:
    Input: {}
    Output: 0

Example 2:
    Input:  {1,#,2,3}
    Output: 3
    Explanation:
        1
         \
          2
         /
        3
    it will be serialized {1,#,2,3}

Example 3:
    Input:  {1,2,3,#,#,4,5}
    Output: 2
    Explanation:
          1
         / \
        2   3
           / \
          4   5
    it will be serialized {1,2,3,#,#,4,5}
*/
class Solution155BFS 
{
public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode* root) 
    {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        int miniDepth = 0;
        while (!q.empty()) {

            miniDepth++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (!node->left && !node->right) {
                    return miniDepth;
                }

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return miniDepth;
    }
};

class Solution155DFS 
{
public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode* root) 
    {
        if (!root) {
            return 0;
        }

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (left == 0 || right == 0) {
            return left + right + 1;
        }

        return std::min(left, right) + 1;
    }
};


#endif

