#ifndef __LINTCODE_0380__
#define __LINTCODE_0380__

#include "data-types.h"


/*@380. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.

Example 1:
    Input:
        A:          a1->a2
                           \
                             c1->c2->c3
                           /
        B:     b1->b2->b3
    Output:c1
    Explanation:begin to intersect at node c1.

Example 2:
    Input:
        Intersected at 6
        1->2->3->4->5->6->7->8->9->10->11->12->13->null
        6->7->8->9->10->11->12->13->null
    Output: Intersected at 6
    Explanation:begin to intersect at node 6.

Challenge
    Your code should preferably run in O(n) time and use only O(1) memory.

Notice
    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
*/
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution380Stack 
{
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        if (!headA || !headB) {
            return nullptr;
        }

        std::stack<ListNode*> stackA;
        std::stack<ListNode*> stackB;

        while (headA) {
            stackA.push(headA);
            headA = headA->next;
        }

        while (headB) {
            stackB.push(headB);
            headB = headB->next;
        }
        ListNode* prev = nullptr;
        while (!stackA.empty() && !stackB.empty()) {
            ListNode* currA = stackA.top();
            stackA.pop();

            ListNode* currB = stackB.top();
            stackB.pop();

            if (currA != currB) {
                break;
            }
            prev = currA;
        }

        return prev;
    }
};

class Solution380TwoPointers 
{
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        if (!headA || !headB) {
            return nullptr;
        }

        ListNode* tailA = headA;
        while (tailA->next) {
            tailA = tailA->next;
        }
        tailA->next = headB;

        ListNode* slow = headA;
        ListNode* fast = headA;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                break;
            }
        }

        fast = headA;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

#endif

