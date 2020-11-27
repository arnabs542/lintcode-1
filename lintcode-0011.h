#ifndef __LINTCODE_0011__
#define __LINTCODE_0011__

#include "data-types.h"

/*@11. Search Range in Binary Search Tree
Given a binary search tree and a range [k1, k2], return node values within a given range in ascending order.

Example 1:
    Input: {5},6,10
    Output: []
            5
    it will be serialized {5}
    No number between 6 and 10

Example 2:
    Input: {20,8,22,4,12},10,22
    Output: [12,20,22]
    Explanation: 
            20
           /  \
          8   22
         / \
        4   12
    it will be serialized {20,8,22,4,12}
    [12,20,22] between 10 and 22
*/
class Solution11Travel 
{
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    std::vector<int> searchRange(TreeNode* root, int k1, int k2) 
    {
        std::vector<int> result;

        travel(root, k1, k2, result);

        return result;
    }

private:
    void travel(TreeNode* root, int k1, int k2, std::vector<int>& result) 
    {
        if (!root) {
            return;
        }

        if (k1 < root->val) {
            travel(root->left, k1, k2, result);
        }

        if (k1 <= root->val && root->val <= k2) {
            result.push_back(root->val);
        }

        if (root->val < k2) {
            travel(root->right, k1, k2, result);
        }
    }
};

class Solution11DivideConquer 
{
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    std::vector<int> searchRange(TreeNode* root, int k1, int k2) 
    {
        std::vector<int> result;

        result = divideCon(root, k1, k2);

        return result;
    }

private:
    std::vector<int> divideCon(TreeNode* root, int k1, int k2) 
    {

        if (!root) {
            return {};
        }

        std::vector<int> left;
        if (k1 < root->val) {
            left = divideCon(root->left, k1, k2);
        }

        std::vector<int> right;
        if (root->val < k2) {
            right = divideCon(root->right, k1, k2);
        }

        std::vector<int> result;
        if (k1 <= root->val && root->val <= k2) {
            result = left;
            result.push_back(root->val);
            result.insert(result.end(), right.begin(), right.end());
        }
        else if (root->val < k1) {
            result = right;
        }
        else if (root->val > k2) {
            result = left;
        }

        return result;
    }
};

#endif


