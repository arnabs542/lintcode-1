#ifndef __LINTCODE_0130__
#define __LINTCODE_0130__

#include "data-types.h"

/*@130. Heapify
Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].

Example 1
	Input : [3,2,1,4,5]
	Output : [1,2,3,4,5]
	Explanation : return any one of the legitimate heap arrays
Challenge
	O(n) time complexity

Clarification
	What is heap? What is heapify? What if there is a lot of solutions?

	Heap is a data structure, which usually have three methods: push, pop and top.
	where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.
	Convert an unordered integer array into a heap array.
	If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

	Return any of them.
*/
class Solution130_1
{
public:
	void heapify(std::vector<int>& A)
	{
		if (A.empty()) {
			return;
		}

		for (int i = 0; i < (int)A.size(); i++) {
			siftup(A, i);
		}
	}

private:
	void siftup(std::vector<int>& A, int k)
	{
		while (k) {
			int father = (k - 1) / 2;
			if (A[k] > A[father]) {
				break;
			}
			std::swap(A[k], A[father]);
			k = father;
		}
	}
};

class Solution130_2
{
public:
	void heapify(std::vector<int>& A)
	{
		for (int i = (A.size() - 1) / 2; i >= 0; i--) {
			siftdown(A, i);
		}
	}

private:
	void siftdown(std::vector<int>& A, int k)
	{
		while (k * 2 + 1 < (int)A.size()) {
			int son = k * 2 + 1;  // left son
			if (k * 2 + 2 < (int)A.size() && A[son] > A[k * 2 + 2]) {
				son = k * 2 + 2; // right son
			}
			if (A[son] > A[k]) {
				break;
			}
			std::swap(A[son], A[k]);
			k = son;
		}
	}

};

#endif

