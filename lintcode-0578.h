#ifndef __LINTCODE_0578__
#define __LINTCODE_0578__

#include "data-types.h"


/*@578. Lowest Common Ancestor III
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example1
    Input:
        {4, 3, 7, #, #, 5, 6}
        3 5
        5 6
        6 7
        5 8
    Output:
        4
        7
        7
        null
    Explanation:
          4
         / \
        3   7
           / \
          5   6

    LCA(3, 5) = 4
    LCA(5, 6) = 7
    LCA(6, 7) = 7
    LCA(5, 8) = null

Example2
    Input:
        {1}
        1 1
    Output:
        1
    Explanation:
        The tree is just a node, whose value is 1.

Notice
    node A or node B may not exist in tree.
    Each node has a different value
*/
class Solution578 
{
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) {
        std::tuple<bool, bool, TreeNode*> rt = divideConquer(root, A, B);
        if (std::get<0>(rt) && std::get<1>(rt)) {
            return std::get<2>(rt);
        }

        return nullptr;
    }

private:
    std::tuple<bool, bool, TreeNode*> divideConquer(TreeNode* root, TreeNode* A, TreeNode* B) 
    {
        if (!root) {
            return std::tuple<bool, bool, TreeNode*>(false, false, nullptr);
        }

        std::tuple<bool, bool, TreeNode*> left = divideConquer(root->left, A, B);
        std::tuple<bool, bool, TreeNode*> right = divideConquer(root->right, A, B);

        bool aExist = std::get<0>(left) || std::get<0>(right) || root == A;
        bool bExist = std::get<1>(left) || std::get<1>(right) || root == B;

        if (root == A || root == B || (std::get<2>(left) && std::get<2>(right))) {
            return std::tuple<bool, bool, TreeNode*>(aExist, bExist, root);
        }

        if (std::get<2>(left)) {
            return std::tuple<bool, bool, TreeNode*>(aExist, bExist, std::get<2>(left));
        }

        if (std::get<2>(right)) {
            return std::tuple<bool, bool, TreeNode*>(aExist, bExist, std::get<2>(right));
        }

        return std::tuple<bool, bool, TreeNode*>(aExist, bExist, nullptr);
    }
};

struct ReturnType {
    bool aExist;
    bool bExist;
    TreeNode* node;

    ReturnType(bool a, bool b, TreeNode* n) {
        aExist = a;
        bExist = b;
        node = n;
    }
};

class Solution578dfs 
{
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* A, TreeNode* B) 
    {
        ReturnType rt = divideConquer(root, A, B);
        if (rt.aExist && rt.bExist) {
            return rt.node;
        }

        return nullptr;
    }

private:
    ReturnType divideConquer(TreeNode* root, TreeNode* A, TreeNode* B) 
    {
        if (!root) {
            return ReturnType(false, false, nullptr);
        }

        ReturnType left = divideConquer(root->left, A, B);
        ReturnType right = divideConquer(root->right, A, B);

        bool aExist = left.aExist || right.aExist || root == A;
        bool bExist = left.bExist || right.bExist || root == B;

        if (root == A || root == B || (left.node && right.node)) {
            return ReturnType(aExist, bExist, root);
        }

        if (left.node) {
            return ReturnType(aExist, bExist, left.node);
        }

        if (right.node) {
            return ReturnType(aExist, bExist, right.node);
        }

        return ReturnType(aExist, bExist, nullptr);
    }

};


#endif

