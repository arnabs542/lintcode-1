#ifndef __LINTCODE_0102__
#define __LINTCODE_0102__

#include "data-types.h"

/*@102. Linked List Cycle
Given a linked list, determine if it has a cycle in it.

Example
    Example 1:
        Input: 21->10->4->5,  then tail connects to node index 1(value 10).
        Output: true

    Example 2:
        Input: 21->10->4->5->null
        Output: false

    ```
Challenge
Follow up:
Can you solve it without using extra space?
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
class Solution102Hashmap 
{
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode* head) 
    {
        if (!head) {
            return false;
        }

        std::unordered_set<ListNode*> sets;
        sets.insert(head);
        while (head->next) {
            head = head->next;

            if (sets.count(head)) {
                return true;
            }

            sets.insert(head);
        }

        return false;
    }
};

class Solution102TwoPointers 
{
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode* head) 
    {
        if (!head) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};

#endif

