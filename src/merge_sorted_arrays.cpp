/*
https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/

#include "std_headers.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class MergeTwoLists {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head, *tail;

		if (l1 && l2)
			head = (l1->val < l2->val) ? l1 : l2;
		else if (l1)
			return l1;
		else if (l2)
			return l2;
		else
			return NULL;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
			tail->next = NULL;
		}

		if (l1)
			tail->next = l1;

		if (l2)
			tail->next = l2;

		return head;

	}
};


void mergeLists() {

}