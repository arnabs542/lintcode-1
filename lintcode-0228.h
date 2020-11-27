#ifndef __LINTCODE_0228__
#define __LINTCODE_0228__

#include "data-types.h"

/*@228. Middle of Linked List
Find the middle node of a linked list.

Example
Example 1:

Input:  1->2->3
Output: 2
Explanation: return the value of the middle node.
Example 2:

Input:  1->2
Output: 1
Explanation: If the length of list is  even return the value of center left one.
Challenge
If the linked list is in a data stream, can you find the middle without iterating the linked list again?
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

class Solution228TwoPointers 
{
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode* middleNode(ListNode* head) 
    {
        if (!head) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

#endif

