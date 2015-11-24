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

ListNode* dummyHead = &ListNode(0);

class Solution {
public:
	ListNode* reverse(ListNode* head, int k) {
		dummyHead->next = head;
		ListNode* prev = dummyHead;
		ListNode* cur = head;
		ListNode* next = cur->next;
		while (next && k--) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
		}
		dummyHead->next->next = next;
		return dummyHead->next;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {

	}
};