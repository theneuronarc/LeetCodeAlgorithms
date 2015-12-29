/*
https://leetcode.com/problems/linked-list-cycle/
*/


typedef struct ListNode {
  int val;
  struct ListNode *next;
}ListNode;

bool hasCycle(struct ListNode *head) {
	ListNode* ptr1, *ptr2;
	ptr1 = ptr2 = head;
	while (ptr1 && ptr2) {
		ptr1 = ptr1->next;
		ptr2 = (ptr2->next ? ptr2->next->next : 0);

		if (ptr1 == ptr2 && ptr1 != 0)
			return true;
	}

	return false;
}

struct ListNode *detectCycle(struct ListNode *head) {
	ListNode* ptr1, *ptr2, *ptr3;
	if (!head)
		return 0;

	ptr1 = ptr2 = ptr3 = head;

	while (ptr1 && ptr2) {
		ptr1 = ptr1->next;
		ptr2 = (ptr2->next ? ptr2->next->next : 0);

		if (ptr1 == ptr2)
			break;
	}

	if (!ptr1 || !ptr2)
		return 0;

	while (ptr1 != ptr3) {
		ptr3 = ptr3->next;
		ptr1 = ptr1->next;
	}

	return ptr3;
}