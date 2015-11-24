/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
*/


#include "std_headers.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
	ListNode* reverse(ListNode* dummyHead, int k) {		
		ListNode* prev = dummyHead;
		ListNode* cur = dummyHead->next;
		ListNode* next = cur->next;
		int tmp = 0;
		while (next && tmp < k) {
			cur->next = prev;
			prev = cur;
			cur = next;
			next = cur->next;
			tmp++;
		}
		
		if (!next && tmp < k) {
			cur->next = prev;
			prev = cur;
			cur = next;
			tmp++;
		}

		next = dummyHead->next;
		dummyHead->next->next = cur;
		dummyHead->next = prev;
		if (tmp < k) 
			return reverse(dummyHead, tmp);
		else
			return next;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1 || head == NULL)
			return head;

		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		while ((cur = reverse(cur, k)) && cur->next);
		

		return dummyHead->next;
	}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1 || head == NULL)
			return head;

		ListNode* listHead = new ListNode(0);
		listHead->next = head;

		ListNode* dummyHead = listHead;
		ListNode* prev, *cur, *next;		

		do {
			prev = dummyHead;
			cur = dummyHead->next;
			next = cur->next;
			int tmp = 0;
			while (next && tmp < k) {
				cur->next = prev;
				prev = cur;
				cur = next;
				next = cur->next;
				tmp++;
			}

			if (!next && tmp < k) {
				cur->next = prev;
				prev = cur;
				cur = next;
				tmp++;
			}

			next = dummyHead->next;
			dummyHead->next->next = cur;
			dummyHead->next = prev;
			if (tmp < k) {
				k = tmp;
				//dummyHead = reverse(dummyHead, tmp);
			}
			else
				dummyHead = next;
		} while (dummyHead && dummyHead->next);

		return listHead->next;
	}
};

static void printList(ListNode* node) {
	while (node) {
		cout << node->val << " -> ";
		node = node->next;
	}
}
void reverseKnodesMain() {
	Solution obj;
	ListNode* head = NULL;
	int k = 3;
	for (int i = 8; i >0; i--) {
		ListNode* cur = new ListNode(i);
		cur->next = head;
		head = cur;
	}

	head = obj.reverseKGroup(head, k);
	printList(head);
}