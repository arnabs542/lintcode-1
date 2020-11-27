#ifndef __LINTCODE_0474__
#define __LINTCODE_0474__

#include "data-types.h"


/*@474. Lowest Common Ancestor II
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
The node has an extra attribute parent which point to the father of itself. The root's parent is null.

Example 1:
    Input:{4,3,7,#,#,5,6},3,5
    Output:4
    Explanation:
         4
         / \
        3   7
           / \
          5   6
    LCA(3, 5) = 4

Example 2:
    Input:{4,3,7,#,#,5,6},5,6
    Output:7
    Explanation:
          4
         / \
        3   7
           / \
          5   6
    LCA(5, 6) = 7
*/
class Solution474DFS // same as #1311
{   
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode* lowestCommonAncestorII(ParentTreeNode* root, ParentTreeNode* A, ParentTreeNode* B) {
        if (!root || !A || !B) {
            return nullptr;
        }

        if (root->val == A->val || root->val == B->val) {
            return root;
        }

        ParentTreeNode* left = lowestCommonAncestorII(root->left, A, B);
        ParentTreeNode* right = lowestCommonAncestorII(root->right, A, B);

        if (!left || !right) {
            return left == nullptr ? right : left;
        }

        return root;
    }
};

class Solution474DFS1     // use parent variable.
{  
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode* lowestCommonAncestorII(ParentTreeNode* root, ParentTreeNode* A, ParentTreeNode* B) 
    {
        if (!root || !A || !B) {
            return nullptr;
        }

        std::unordered_set<int> parentSet;

        ParentTreeNode* curr = A;
        while (curr) {               // save A parents to hashmap.
            parentSet.insert(curr->val);
            curr = curr->parent;
        }

        curr = B;
        while (curr) {
            if (parentSet.count(curr->val)) {   // if B or its parent occured in hashmap at first time, means this is A & B's LCA.
                return curr;
            }
            curr = curr->parent;
        }

        return nullptr;
    }
};

#endif

