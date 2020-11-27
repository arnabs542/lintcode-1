#ifndef __LINTCODE_0902__
#define __LINTCODE_0902__

#include "data-types.h"

/*@902. Kth Smallest Element in a BST.
Given a binary search tree,write a function kthSmallest to find the kth smallest element in it.

Example 1:
    Input:{1,#,2},2
    Output:2
    Explanation:
        1
         \
          2
    The second smallest element is 2.

Example 2:
    Input:{2,1,3},1
    Output:1
    Explanation:
      2
     / \
    1   3
    The first smallest element is 1.

Challenge
    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
    How would you optimize the kthSmallest routine?

Notice
    You may assume k is always valid, 1 <= k <= BST's total elements.
*/
class Solution902
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root || k <= 0) {
            return 0;
        }

        std::stack<TreeNode*> s;
        while (!s.empty() || root) {

            while (root) {
                s.push(root);
                root = root->left;
            }

            root = s.top();
            s.pop();

            k--;
            if (k == 0) {
                return root->val;
            }

            root = root->right;
        }

        return 0;
    }

};

#endif

