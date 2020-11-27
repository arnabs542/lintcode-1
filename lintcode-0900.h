#ifndef __LINTCODE_0900__
#define __LINTCODE_0900__

#include "data-types.h"

/*@900. Cloest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Example
    Input: root = {5,4,9,2,#,8,10} and target = 6.124780
    Output: 5
    Explanation:
    Binary tree {5,4,9,2,#,8,10},  denote the following structure:
            5
           / \
         4    9
        /    / \
       2    8  10
Example2
    Input: root = {3,2,4,1} and target = 4.142857
    Output: 4
    Explanation:
    Binary tree {3,2,4,1},  denote the following structure:
         3
        / \
      2    4
     /
    1
Notice
    Given target value is a floating point.
    You are guaranteed to have only one unique value in the BST that is closest to the target.
*/
class Solution900_1
{
public:
    int closestValue(TreeNode* root, double target)
    {
        if (!root) {
            return -1;
        }

        int closest = root->val;
        while (root) {
            if (abs(closest - target) >= abs(root->val - target)) {
                closest = root->val;
            }

            root = target < root->val ? root->left : root->right;
        }

        return closest;
    }
};

class Solution900_2
{
public:
    int closestValue(TreeNode* root, double target)
    {
        if (!root) {
            return -1;
        }

        int lower = root->val;
        int upper = root->val;
        while (root) {
            if (target == root->val) {
                return root->val;
            }

            if (target < root->val) {
                lower = root->val;
                root = root->left;
            }
            else { // target > root->val
                upper = root->val;
                root = root->right;
            }
        }

        return abs(upper - target) > abs(target - lower) ? lower : upper;
    }
};

class Solution900_3
{
public:
    int closestValue(TreeNode* root, double target)
    {
        if (!root) {
            return -1;
        }

        TreeNode* lowerNode = lowerBound(root, target);
        TreeNode* upperNode = upperBound(root, target);

        if (!lowerNode && !upperNode) {
            return -1;
        }

        if (!lowerNode || !upperNode) {
            return lowerNode == nullptr ? upperNode->val : lowerNode->val;
        }

        return (target - lowerNode->val) > (upperNode->val - target) ? upperNode->val : lowerNode->val;
    }

private:
    TreeNode* lowerBound(TreeNode* root, double target)
    {
        if (!root) {
            return nullptr;
        }

        if (target <= root->val) {
            return lowerBound(root->left, target);
        }

        // root->val >= target
        TreeNode* lowerNode = lowerBound(root->right, target);

        return lowerNode == nullptr ? root : lowerNode;
    }

    TreeNode* upperBound(TreeNode* root, double target)
    {
        if (!root) {
            return nullptr;
        }

        if (root->val < target) { // NOT <=
            return upperBound(root->right, target);
        }

        // root->val >= target
        TreeNode* upperNode = upperBound(root->left, target);

        return upperNode == nullptr ? root : upperNode;
    }
};

class Solution900_4 
{
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode* root, double target) {
        if (!root) {
            return -1;
        }

        std::vector<int> inorder;
        getInorder(root, inorder);

        return getClosedValue(inorder, target);
    }

private:
    void getInorder(TreeNode* root, std::vector<int>& inorder) {
        if (!root) {
            return;
        }

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }

    int getClosedValue(std::vector<int>& nums, double target) {

        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return nums[mid];
            }

            if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (abs(nums[start] - target) > abs(nums[end] - target)) {
            return nums[end];
        }

        return nums[start];
    }
};



#endif
