/*
https://leetcode.com/problems/sort-list/
*/


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

typedef struct ListNode ListNode;

ListNode* mergeList(ListNode* list1, ListNode* list2) {
	ListNode* head, *sorted;

	if (!list1)
		return list2;

	if (!list2)
		return list1;

	if (list1->val < list2->val) {
		sorted = list1;
		list1 = list1->next;
	}
	else {
		sorted = list2;
		list2 = list2->next;
	}

	head = sorted;
	while (list1 && list2) {
		if (list1->val < list2->val) {
			sorted->next = list1;
			list1 = list1->next;
		}
		else {
			sorted->next = list2;
			list2 = list2->next;
		}

		sorted->next->next = 0;
		sorted = sorted->next;
	}

	if (list1)
		sorted->next = list1;

	if (list2)
		sorted->next = list2;

	return head;
}

ListNode* sortListDC(ListNode* head) {
	ListNode* slow, *fast;

	if (!head || !head->next)
		return head;

	slow = fast = head;

	while (fast && fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	//printf("\n%d", slow->val);

	fast = slow->next;
	slow->next = 0;

	slow = sortListDC(head);
	fast = sortListDC(fast);

	return mergeList(slow, fast);
}

struct ListNode* sortList(struct ListNode* head) {
	return sortListDC(head);
}