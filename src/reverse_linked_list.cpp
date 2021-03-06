/*
https://leetcode.com/problems/reverse-linked-list-ii/


Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/

#include "std_headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* list, int m, int n) {
		ListNode* current = list;
		ListNode* next = NULL;
		ListNode* prev = NULL;

		ListNode** head = &list;
		ListNode* tail = list;

		int cnt = 1;

		while (current && cnt <= n) {
			if (cnt < m) {
				head = &current->next;
				current = current->next;
				tail = current;
				cnt++;				
				continue;
			}

			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			cnt++;
		}

		if(tail) tail->next = current;
		*head = prev;

		return list;
	}
};