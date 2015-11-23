#pragma once

template <typename T>
class Heap {
	typedef struct node{
		T data;
		node *left;
		node *right;
	}Node;

	Node* root;
	bool isEmpty;
	void heapify(Node* root);

public:
	Heap():isEmpty(true), root(NULL){}
	T top();
	void push(T);
	void pop();
	bool empty() {
		return isEmpty;
	}
};