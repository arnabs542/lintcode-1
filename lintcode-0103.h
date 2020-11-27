#ifndef __LINTCODE_0103__
#define __LINTCODE_0103__

#include "data-types.h"


/*@103. Linked List Cycle II
Given a linked list, return the node where the cycle begins.
If there is no cycle, return null.

Example 1:
    Input: null,no cycle
    Output: no cycle
    Explanation: List is null,so no cycle.

Example 2:
    Input: -21->10->4->5,tail connects to node index 1
    Output: 10
    Explanation: The last node 5 points to the node whose index is 1, which is 10, so the entrance of the ring is 10

Challenge
Follow up:
    Can you solve it without using extra space?
*/
//???? how to use hashmap to do it ??? how to built the hash function for ListNode* ???
class Solution103 
{
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode* detectCycle(ListNode* head) 
    {
        if (!head) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        if (!fast || !fast->next) {
            return nullptr;
        }

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};

#endif
