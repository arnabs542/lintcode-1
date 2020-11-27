#ifndef __LINTCODE_0068__
#define __LINTCODE_0068__

#include "data-types.h"

/*@68. Binary Tree Postorder Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

Example
Example 1:

Input:{1,2,3}
Output:[2,3,1]
Explanation:
   1
  / \
 2   3
 it will be serialized {1,2,3}
Post order traversal
Example 2:

Input:{1,#,2,3}
Output:[3,2,1]
Explanation:
1
 \
  2
 /
3
it will be serialized {1,#,2,3}
Post order traversal
Challenge
Can you do it without recursion?

Notice
The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
The number of nodes does not exceed 20.
*/
class Solution68Traversal 
{
public:
    /**
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    std::vector<int> postorderTraversal(TreeNode* root) 
    {
        // write your code here
        std::vector<int> result;
        if (!root) {
            return result;
        }

        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        std::stack<TreeNode*> s;

        s.push(root);
        std::cout << "Push root: " << root->val << std::endl;
        while (!s.empty()) {
            curr = s.top();

            std::cout << "\n\n" << std::endl;
            if (prev) {
                std::cout << " prev : " << prev->val << std::endl;
            }
            std::cout << " curr : " << curr->val << std::endl;

            if (!prev || prev->left == curr || prev->right == curr) { // traverse down the tree
                if (curr->left) {
                    s.push(curr->left);

                    std::cout << "Down: Push left : " << curr->left->val << std::endl;

                }
                else if (curr->right) {
                    s.push(curr->right);

                    std::cout << "Down: Push right : " << curr->right->val << std::endl;

                }
                else {
                    std::cout << "Down: This is leaf.." << std::endl;
                }
            }
            else if (curr->left == prev) { // traverse up the tree from the left

                if (curr->right) {
                    s.push(curr->right);

                    std::cout << "Up: Push right : " << curr->right->val << std::endl;

                }
                else {
                    std::cout << "Up: No right leaf ." << std::endl;
                }
            }
            else { // traverse up the tree from the right
                result.push_back(curr->val);
                s.pop();

                std::cout << " Pop: " << curr->val << std::endl;
            }

            prev = curr;
        }

        return result;
    }
};

#endif

