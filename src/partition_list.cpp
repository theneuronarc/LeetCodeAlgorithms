/*
https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include "std_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* smallerTail = NULL;
		ListNode* largerTail = NULL;
		ListNode* current = head;

		ListNode* smallerBegin = NULL;
		ListNode* largerBegin = NULL;

		while (current) {
			if (current->val < x) {
				if (smallerTail) {
					smallerTail->next = current;
					smallerTail = smallerTail->next;
				}
				else {
					smallerTail = current;
					smallerBegin = smallerTail;
				}
			}
			else {
				if (largerTail) {
					largerTail->next = current;
					largerTail = largerTail->next;
				}
				else {
					largerTail = current;
					largerBegin = largerTail;
				}
			}

			current = current->next;
		}

		if (largerTail)
			largerTail->next = NULL;

		if (smallerTail)
			smallerTail->next = largerBegin;

		return smallerBegin ? smallerBegin : largerBegin;
	}
};