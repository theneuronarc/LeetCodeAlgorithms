/*

*/

#include "std_headers.h"

typedef struct ListNode {
     int val;
     struct ListNode *next;
 };

void insertNode(struct ListNode** head, int val) {
	ListNode* node = (ListNode*)malloc(sizeof(struct ListNode));
	node->val = val;
	node->next = *head;
	*head = node;
}

struct ListNode* removeNode(ListNode* head, ListNode* node) {
	ListNode* tmp = head;

	if (!head && head == node) {
		head = head->next;
		free(node);
	}

	while (tmp && tmp->next != node)
		tmp = tmp->next;

	if (tmp) {
		tmp->next = node->next;
		free(node);
	}

	return head;
}

void deleteNode(struct ListNode* node) {
	if (!node || !node->next)
		return;

	while (node && node->next) {		
		node->val = node->next->val;

		if (!node->next->next) { // next node is tail
			free(node->next);
			node->next = NULL;
		}

		node = node->next;		
	}
}

struct ListNode* removeElements(struct ListNode* head, int val) {
	ListNode* tmp = (ListNode*)malloc(sizeof(struct ListNode));
	tmp->val = val+1;
	tmp->next = head;

	head = tmp;

	while (tmp && tmp->next) {
		if (tmp->next->val == val) {
			ListNode* node = tmp->next;
			tmp->next = tmp->next->next;
			free(node);
		}
		else {
			tmp = tmp->next;
		}
	}

	tmp = head;
	head = head->next;
	free(tmp);

	return head;
	
}