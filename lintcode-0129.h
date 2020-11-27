#ifndef __LINTCODE_0129__
#define __LINTCODE_0129__

#include "data-types.h"


/*@129. Rehashing
The size of the hash table is not determinate at the very beginning. 
If the total size of keys is too large (e.g. size >= capacity / 10), we should double the size of the hash table and rehash every keys. 
Say you have a hash table looks like below:
size=3, capacity=4
[null, 21, 14, null]
       |    |
       9   null
       |
      null
The hash function is:

int hashcode(int key, int capacity) {
    return key % capacity;
}
here we have three numbers, 9, 14 and 21, where 21 and 9 share the same position as they all have the same hashcode 1 (21 % 4 = 9 % 4 = 1). 
We store them in the hash table by linked list.

rehashing this hash table, double the capacity, you will get:
size=3, capacity=8
index:   0    1    2    3     4    5    6   7
hash : [null, 9, null, null, null, 21, 14, null]
Given the original hash table, return the new hash table after rehashing .

Example 1
    Input:[null, 21->9->null, 14->null, null]
    Output:[null, 9->null, null, null, null, 21->null, 14->null, null]

Notice
    For negative integer in hash table, the position can be calculated as follow:
    C++/Java: if you directly calculate -4 % 3 you will get -1. You can use function: a % b = (a % b + b) % b to make it is a non negative integer.
    Python: you can directly use -1 % 3, you will get 2 automatically.
*/
class Solution129
{
public:
    std::vector<ListNode*> rehashing(std::vector<ListNode*> hashTable)
    {
        if (hashTable.empty()) {
            return {};
        }

        int capacity = hashTable.size() * 2;
        std::vector<ListNode*> newHashTable(capacity, nullptr);

        for (int i = 0; i < (int)hashTable.size(); i++) {

            while (hashTable[i]) {

                ListNode* item = hashTable[i];
                hashTable[i] = hashTable[i]->next;
                item->next = nullptr;

                int newIndex = (item->val + capacity) % capacity;

                if (!newHashTable[newIndex]) { //nullptr
                    newHashTable[newIndex] = item;

                }
                else {
                    ListNode* tmp = newHashTable[newIndex];
                    while (tmp->next) {  // follow the old hash map ListNode* order.
                        tmp = tmp->next;
                    }
                    tmp->next = item;
                }
            }
        }
        return newHashTable;
    }
};

#endif