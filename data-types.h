#ifndef __DATATYPES__
#define __DATATYPES__

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>


/* Definition of TreeNode :*/
class TreeNode {
public:
	int val;
	TreeNode* left, * right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = nullptr;
	}
};

class ParentTreeNode {
public:
	int val;
	ParentTreeNode* parent, * left, * right;

};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
struct DirectedGraphNode {
	int label;
	std::vector<DirectedGraphNode*> neighbors;
	DirectedGraphNode(int x) : label(x) {};
};

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = nullptr;
	}
};

class Interval{
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};

#endif
