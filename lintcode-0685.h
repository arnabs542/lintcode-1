#ifndef __LINTCODE_0685__
#define __LINTCODE_0685__

#include "data-types.h"

/* 685. First Unique Number in Data Stream
Given a continuous stream of data, write a function that returns the first unique number (including the last number) when the terminating number arrives.
If the unique number is not found, return -1.

Example
	Input:
	[1, 2, 2, 1, 3, 4, 4, 5, 6]
	5
	Output: 3

Example2
	Input:
	[1, 2, 2, 1, 3, 4, 4, 5, 6]
	7
	Output: -1

Example3
	Input:
	[1, 2, 2, 1, 3, 4]
	3
	Output: 3
*/
class Solution685 
{
public:
	/**
	 * @param nums: a continuous stream of numbers
	 * @param number: a number
	 * @return: returns the first unique number
	 */
	int firstUniqueNumber(std::vector<int>& nums, int number) 
	{
		// Write your code here
		initialize();

		int i = 0;
		while (i < (int)nums.size()) {
			AddStream(nums[i]);
			if (nums[i] == number) {
				break;
			}
			i++;
		}

		if (i == nums.size()) {
			return -1;
		}

		return (!dummy->next) ? -1 : dummy->next->val;
	}

	void initialize() 
	{
		dummy = new Node;
		tail = dummy;
	}

private:
	struct Node {
		int val;
		Node* next;

		Node(int v = -1) : val(v), next(nullptr) {};
	};

	Node* dummy;
	Node* tail;

	std::unordered_map<int, Node*> onceValToPrevNode;
	std::unordered_set<int> twice;

	void addList(int val) 
	{
		onceValToPrevNode[val] = tail;
		tail->next = new Node(val);
		tail = tail->next;
	}

	void AddStream(int val) 
	{
		if (twice.count(val)) {
			return;
		}

		if (onceValToPrevNode.count(val)) {
			removeList(val);
			twice.insert(val);
			return;
		}

		addList(val);
	}

	void removeList(int val) 
	{
		Node* prev = onceValToPrevNode[val];
		Node* curr = prev->next;
		Node* next = curr->next;

		prev->next = next;
		free(curr);
		onceValToPrevNode.erase(val);

		if (next) {
			onceValToPrevNode[next->val] = prev;
		}

		if (tail == curr) {
			tail = prev;
		}
	}
};

#endif

