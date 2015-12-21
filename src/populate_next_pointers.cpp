/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

#include "std_headers.h"

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  struct TreeLinkNode *left, *right, *next;
* };
*
*/
void connect(struct TreeLinkNode *root) {
	TreeLinkNode* current;
	if (!root)
		return;

	root->next = NULL;
	while (root->left) {
		current = root;
		while (current) {
			current->left->next = current->right;
			if (current->next)
				current->right->next = current->next->left;
			else
				current->right->next = NULL;
			current = current->next;
		}
		root = root->left;
	}
}

void connect2(struct TreeLinkNode *root) {
	TreeLinkNode* nodeFirst, *nodeSecond;
	TreeLinkNode* firstChild, *secondChild;
	TreeLinkNode* first;
	TreeLinkNode* current;
	if (!root)
		return;

	first = root;
	first->next = NULL;
	while (first) {
		current = first;
		nodeFirst = nodeSecond = NULL;
		first = NULL;
		while (current) {
			if (current->left || current->right) {
				if (!first) {
					if (current->left)
						first = current->left;
					else
						first = current->right;
				}


				if (!nodeFirst)
					nodeFirst = current;
				else
					nodeSecond = current;

				if (current->right && current->left) {
					current->left->next = current->right;
				}

				if (current->right)
					current->right->next = NULL;
				else
					current->left->next = NULL;

			}

			if (nodeFirst && nodeSecond) {
				if (nodeFirst->right)
					firstChild = nodeFirst->right;
				else
					firstChild = nodeFirst->left;

				if (nodeSecond->left)
					secondChild = nodeSecond->left;
				else
					secondChild = nodeSecond->right;

				firstChild->next = secondChild;


				nodeFirst = nodeSecond;
				nodeSecond = NULL;
			}

			current = current->next;
		}
	}
}