/*
https://leetcode.com/problems/reorder-list/
*/


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

ListNode* reverseList(ListNode* head, ListNode* prev) {
	if (!head)
		return;

	ListNode* cur = head, *next = cur->next;	

	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}

void reorderList(struct ListNode* head) {
	ListNode* mid = head, *end = head;
	ListNode* midCur, *endCur;
	if (!head)
		return;

	while (end) {
		if (end->next && end->next->next)
			end = end->next->next;
		else
			break;
		mid = mid->next;
	}

	if (mid == end)
		return;

	end = reverseList(mid->next, 0);
	mid->next = 0;
	while (mid && end) {
		endCur = end->next;
		midCur = mid->next;
		mid->next = end;
		end->next = midCur;
		mid = midCur;
		end = endCur;
	}
}