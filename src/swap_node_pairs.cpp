/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


#include "std_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* current = dummyHead;
		ListNode* first = NULL, *second = NULL;

		while (true) {
			if (!((first = current->next) && (second = first->next)))
				break;

			current->next = second;
			current = first;

			first->next = second->next;
			second->next = first;
		}

		return dummyHead->next;
	}
};