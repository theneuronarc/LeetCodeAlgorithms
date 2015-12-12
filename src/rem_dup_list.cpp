#include "std_headers.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution1 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;

		ListNode* end = head->next;
		ListNode* start = head;

		while (end) {
			if (start->val != end->val) {
				if (start->next != end) {
					start->next = end;
				}

				start = start->next;
			}

			end = end->next;
		}

		start->next = NULL;
		return head;
	}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* start = dummy;
		ListNode* end = dummy->next;
		
		while (end) {
			if (!end->next || start->next->val != end->next->val) {			
				if (start->next != end) {
					start->next = end->next;
				}
				else {
					start = end;
				}
			}

			end = end->next;
		}

		return dummy->next;
	}
};