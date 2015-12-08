/*
https://leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include "std_headers.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* newHead = head;
		ListNode* cur = head;
		int n = 1;
		while (cur && cur->next) {
			cur = cur->next;
			n++;
		}

		k = k%n;
		cur->next = head;
		k = n - k - 1;
		for (int i = 0; i < k; i++) {
			cur = cur->next;
		}
		head = cur->next;
		cur->next = NULL;
		return head;
	}
};