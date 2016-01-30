/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
*/


typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	ListNode* node;
	if (headA) {
		node = headA;
		while (node) {
			lenA++;
			node = node->next;
		}
	}
	else {
		lenA = 0;
	}

	if (headB) {
		node = headB;
		while (node) {
			lenB++;
			node = node->next;
		}
	}
	else {
		lenB = 0;
	}


	if (!lenA || !lenB)
		return NULL;
	else {
		int len;
		ListNode* node2;
		if (lenA > lenB) {
			len = lenA - lenB;
			node = headA;
			node2 = headB;
		}
		else {
			len = lenB - lenA;
			node = headB;
			node2 = headA;
		}

		while (len) {		
			node = node->next;
			len--;
		}

		while (node && node2 && node != node2) {
			node = node->next;
			node2 = node2->next;
		}

		return node;
	}
}