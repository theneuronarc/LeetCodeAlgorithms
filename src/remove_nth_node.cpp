/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p1, *p2;
		p2 = head;
		p1 = head;

		if (n == 0)
			return head;


		for (int i = 0; i < n-1 && p2!=NULL; i++) {
			p2 = p2->next;
		}

		if (p2 == NULL)
			return head;

		if (p2->next == NULL) {
			head = head->next;
			return head;
		}
		else {
			p2 = p2->next;
			p1 = head;
		}

		while (p2->next != NULL) {
			p2 = p2->next;
			p1 = p1->next;
		}

		p1->next = p1->next->next;
		return head;		
	}
};