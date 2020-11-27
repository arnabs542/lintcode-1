#ifndef __LINTCODE_0134__
#define __LINTCODE_0134__

#include "data-types.h"

//@134. LRU Cache
/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Finally, you need to return the data from each get.


Example1
	Input:
		LRUCache(2)
		set(2, 1)
		set(1, 1)
		get(2)
		set(4, 1)
		get(1)
		get(2)
	Output: [1,-1,1]
	Explanation:
		cache cap is 2,set(2,1),set(1, 1),get(2) and return 1,set(4,1) and delete (1,1),because (1,1)is the least use,get(1) and return -1,get(2) and return 1.

Example 2:
	Input:
		LRUCache(1)
		set(2, 1)
		get(2)
		set(3, 2)
		get(2)
		get(3)
	Output:[1,-1,2]
	Explanation:
		cache cap is 1,set(2,1),get(2) and return 1,set(3,2) and delete (2,1),get(2) and return -1,get(3) and return 2.
*/
class LRUCache134 
{
private:
	struct Node {
		Node* prev;
		Node* next;
		int key;
		int value;

		Node(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {};
	};

	int capacity;
	std::unordered_map<int, Node*> mapping;
	Node* head;
	Node* tail;

	void moveToTail(Node* node) {

		if (!node) {
			return;
		}

		node->prev = tail->prev;
		tail->prev = node;
		node->prev->next = node;
		node->next = tail;
	}

public:
	/*
	* @param capacity: An integer
	*/
	LRUCache134(int _capacity) 
	{
		capacity = _capacity;

		head = new Node(0, 0);    // head and tail are dummy nodes, they won't save in mapping.
		tail = new Node(0, 0);
		head->next = tail;
		tail->prev = head;
	}

	/*
		* @param key: An integer
		* @return: An integer
		*/
	int get(int key) 
	{
		// write your code here
		if (!mapping.count(key)) {
			return -1;
		}

		// remove current.
		Node* curr = mapping[key];
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;

		// move current to tail.
		moveToTail(curr);

		return mapping[key]->value;
	}

	/*
		* @param key: An integer
		* @param value: An integer
		* @return: nothing
		*/
	void set(int key, int value) 
	{
		// write your code here
		if (mapping.count(key)) {
			mapping[key]->value = value;

			// move current to tail.
			Node* curr = mapping[key];
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			curr->value = value;
			moveToTail(curr);

			return;
		}

		if ((int)mapping.size() >= capacity) {
			Node* delNode = head->next;
			mapping.erase(head->next->key);
			head->next = head->next->next;
			head->next->prev = head;

			delete delNode;
		}

		Node* newNode = new Node(key, value);
		mapping.insert({ key, newNode });
		moveToTail(newNode);
	}
};

#endif




