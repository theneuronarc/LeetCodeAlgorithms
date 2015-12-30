/*
https://leetcode.com/problems/insertion-sort-list/
*/

#include "std_headers.h"

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* findMinimum(ListNode** head){
	ListNode* cur = *head, *min = *head, *minPrev = NULL;
	while (cur->next) {
		if (cur->next->val < min->val) {
			min = cur->next;
			minPrev = cur;
		}
		cur = cur->next;
	}

	if (minPrev) {
		minPrev->next = min->next;
	}
	else {
		*head = (*head)->next;
	}

	return min;
}

struct ListNode* insertionSortList2(struct ListNode* head) {
	ListNode* sorted, *unsorted = head;
	head = sorted = (ListNode*)malloc(sizeof(ListNode));
	sorted->next = 0;	
	while (unsorted) {
		sorted->next = findMinimum(&unsorted);
		sorted = sorted->next;
	}

	return head->next;
}

struct ListNode* insertionSortList(struct ListNode* head) {
	if (!head)
		return head;

	ListNode* unsorted = head->next;
	ListNode* cur, *prev, *node, *sorted = head;
	sorted->next = 0;

	while (unsorted) {
		cur = sorted;
		prev = 0;
		node = unsorted;
		unsorted = unsorted->next;
		while (cur) {
			if (cur->val > node->val) {
				if (prev) {
					node->next = prev->next;
					prev->next = node;
				}
				else {
					node->next = sorted;
					sorted = node;
				}
				break;
			}

			if (!cur->next) {
				cur->next = node;
				node->next = 0;
				cur = node;
			}

			prev = cur;
			cur = cur->next;
		}
	}

	return sorted;
}