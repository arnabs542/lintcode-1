#ifndef __LINTCODE_0596__
#define __LINTCODE_0596__

#include "data-types.h"


/*@596. Minimum Subtree.
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example 1:
    Input: {1,-5,2,1,2,-4,-5}
    Output:1
    Explanation:
        The tree is look like this:
             1
           /   \
         -5     2
         / \   /  \
        1   2 -4  -5
        The sum of whole tree is minimum, so return the root.

Example 2:
    Input:{1}
    Output:1
    Explanation:
        The tree is look like this:
            1
        There is one and only one subtree in the tree. So we return 1.

Notice
    LintCode will print the subtree which root is your return node.
    It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.
*/
class Solution596_1
{
public:
    TreeNode* findSubtree(TreeNode* root)
    {
        //0:min sum, 1: sum, 2: subroot.
        std::tuple<int, int, TreeNode*> res = getSum(root);

        return std::get<2>(res);
    }

private:
    std::tuple<int, int, TreeNode*> getSum(TreeNode* root)
    {

        if (!root) {
            return std::tuple<int, int, TreeNode*>(INT_MAX, 0, nullptr);
        }

        std::tuple<int, int, TreeNode*> leftResult = getSum(root->left);
        std::tuple<int, int, TreeNode*> rightResult = getSum(root->right);

        int sum = root->val + std::get<1>(leftResult) + std::get<1>(rightResult);

        if (std::get<0>(leftResult) == std::min(std::get<0>(leftResult), std::min(sum, std::get<0>(rightResult)))) {
            return std::tuple<int, int, TreeNode*>(std::get<0>(leftResult), sum, std::get<2>(leftResult));
        }

        if (std::get<0>(rightResult) == std::min(std::get<0>(rightResult), std::min(sum, std::get<0>(leftResult)))) {
            return std::tuple<int, int, TreeNode*>(std::get<0>(rightResult), sum, std::get<2>(rightResult));
        }

        return std::tuple<int, int, TreeNode*>(sum, sum, root);
    }
};

class Solution596_2
{
public:
    /**
        * @param root: the root of binary tree
        * @return: the root of the minimum subtree
        */
    TreeNode* findSubtree(TreeNode* root) {
        int miniSum = INT_MAX;
        TreeNode* miniSubtree = nullptr;

        getSum(root, miniSum, miniSubtree);

        return miniSubtree;
    }
private:
    int getSum(TreeNode* root, int& miniSum, TreeNode*& miniSubtree) 
    {
        if (!root) {
            return 0;
        }

        int leftSum = getSum(root->left, miniSum, miniSubtree);
        int rightSum = getSum(root->right, miniSum, miniSubtree);

        int sum = root->val + leftSum + rightSum;
        if (sum < miniSum) {
            miniSum = sum;
            miniSubtree = root;
        }

        return sum;
    }
};


#endif