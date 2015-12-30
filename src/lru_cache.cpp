/*
https://leetcode.com/problems/lru-cache/
get - O(1)
set - O(1)
*/

#include "std_headers.h"
typedef struct Node {
	int key;
	int val;
	Node* next;
	Node* prev;
}Node;
/*
class LRUCache1 {
	unordered_map<int, Node*> map;
	int capacity;
	Node* head;
	Node* tail;
public:
	LRUCache(int capacity):capacity(capacity) {
		head = tail = 0;
	}

	int get(int key) {
		if (map.count(key)) {
			Node* node = map[key];

			if (node == tail)
				return node->val;
				

			if (node == head) {
				head = node->next;
				head->prev = 0;

				tail->next = node;
				node->prev = tail;
				node->next = 0;
				tail = node;
				return node->val;
			}

			node->prev->next = node->next;
			node->next->prev = node->prev;
			tail->next = node;
			node->prev = tail;
			node->next = 0;
			tail = node;
			return node->val;
		}
		
		return -1;
	}

	void set(int key, int value) {
		if (get(key) != -1) {
			map[key]->val =  value;
			return;
		}

		if (capacity) {
			Node* node = new Node;
			node->key = key;
			node->val = value;
			node->next = 0;
			node->prev = tail;
			if (!tail) {
				head = tail = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
			map[key] = node;
			capacity--;
			return;
		}
		else{
			Node* node = head;
			if (head != tail) {
				head = head->next;
				head->prev = 0;
				node->next = 0;
				node->prev = tail;
				tail->next = node;
				tail = node;
			}
			map.erase(node->key);
			node->key = key;
			node->val = value;
			map[key] = node;
			return;
		}
	}
};
*/

// Using Sentinels
class LRUCache {
	unordered_map<int, Node*> map;
	int capacity;
	Node* head;
	Node* tail;
public:
	LRUCache(int capacity) :capacity(capacity) {
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		if (map.count(key)) {
			Node* node = map[key];
			node->prev->next = node->next;
			node->next->prev = node->prev;

			tail->prev->next = node;
			node->prev = tail->prev;
			tail->prev = node;
			node->next = tail;

			return node->val;
		}

		return -1;
	}

	void set(int key, int value) {
		if (get(key) != -1) {
			map[key]->val = value;
			return;
		}

		if (capacity) {
			Node* node = new Node;
			node->key = key;
			node->val = value;

			tail->prev->next = node;
			node->prev = tail->prev;
			tail->prev = node;
			node->next = tail;

			map[key] = node;
			capacity--;
			return;
		}
		else {
			Node* node = head->next;
			head->next = node->next;
			node->next->prev = head;

			tail->prev->next = node;
			node->prev = tail->prev;
			tail->prev = node;
			node->next = tail;

			map.erase(node->key);
			node->key = key;
			node->val = value;
			map[key] = node;
			return;
		}
	}
};


void LRUCacheMain() {
	LRUCache obj(2);
	obj.set(1,2);
	obj.set(2,4);
	obj.set(3, 8);
	obj.set(4, 16);
	obj.set(5, 32);

	cout << obj.get(1) << endl;
	cout << obj.get(2) << endl;
	obj.set(6, 64);
	cout << obj.get(3) << endl;
	cout << obj.get(4) << endl;
	cout << obj.get(5) << endl;
	cout << obj.get(6) << endl;
}