#ifndef __LINTCODE_0104__
#define __LINTCODE_0104__

#include "data-types.h"

/*@104. Merge K Sorted Lists
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example
Example 1:
    Input:   [2->4->null,null,-1->null]
    Output:  -1->2->4->null

Example 2:
    Input: [2->6->null,5->null,7->null]
    Output:  2->5->6->7->null
*/
class Solution104Heap 
{
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        if (lists.empty()) {
            return nullptr;
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, compareVal> heap;
        for (int i = 0; i < (int)lists.size(); i++) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!heap.empty()) {
            ListNode* head = heap.top();
            heap.pop();
            tail->next = head;
            tail = head;
            if (head->next) {
                heap.push(head->next);
            }
        }

        return dummy->next;
    }

private:
    struct compareVal {
        bool operator() (ListNode* left, ListNode* right) {
            return left->val > right->val;
        }
    };
};

class Solution104MergeTwoByTwo 
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            std::vector<ListNode*> newLists;
            for (int i = 0; i + 1 < (int)lists.size(); i += 2) {
                ListNode* mergeList = merge(lists[i], lists[i + 1]);
                newLists.push_back(mergeList);
            }

            if (lists.size() % 2) {
                newLists.push_back(lists[lists.size() - 1]);
            }
            lists = newLists;
        }

        return lists[0];
    }

private:
    ListNode* merge(ListNode* a, ListNode* b) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a) {
            tail->next = a;
        }
        if (b) {
            tail->next = b;
        }

        return dummy->next;
    }
};

class Solution104DivideConquer 
{
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        if (lists.empty()) {
            return nullptr;
        }

        return divideConquer(lists, 0, lists.size() - 1);
    }

private:
    ListNode* divideConquer(std::vector<ListNode*>& lists, int start, int end) 
    {
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = divideConquer(lists, start, mid);
        ListNode* right = divideConquer(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) 
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        if (a) {
            tail->next = a;
        }
        if (b) {
            tail->next = b;
        }

        ListNode* head = dummy->next;
        dummy->next = nullptr;
        delete dummy;

        return head;
    }

};


#endif

