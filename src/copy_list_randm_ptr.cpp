/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/
#include "std_headers.h"
typedef struct RandomListNode RandomListNode;


struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	// Copy original List and create a Map
	RandomListNode* current = head;
	RandomListNode* copy;
	RandomListNode* prev, **copyHead;
	if (!head)
		return NULL;

	prev = (RandomListNode*)malloc(sizeof(RandomListNode));

	copyHead = &prev->next;

	while (current != NULL) {
		copy = (RandomListNode*)malloc(sizeof(RandomListNode));
		copy->next = NULL;
		copy->random = current->random;
		copy->label = current->label;

		current->random = copy;
		prev->next = copy;
		current = current->next;
		prev = prev->next;
	}

	current = *copyHead;
	while (current != NULL) {
		prev = current->next;
		current->next = current->random;
		current->random = (current->random ? current->random->random : NULL);
		current = prev;
	}

	current = head;
	while (current != NULL) {
		prev = current->random->next;
		current->random->next = current->next ? current->next->random : NULL;
		current->random = prev;
		current = current->next;
	}

	return *copyHead;
}