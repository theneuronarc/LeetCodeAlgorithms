/*
https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include "std_headers.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0) : val(x), next(NULL) {}
};

typedef ListNode* ListNode_p;

struct compare
{
	bool operator()(const ListNode_p& l, const ListNode_p& r)
	{
		return l->val > r->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		std::priority_queue<ListNode_p, std::vector<ListNode_p>, compare> minHeap;
		ListNode* sortedList = new ListNode(0);
		ListNode* current = sortedList;

		// Initialize a heap
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i])
				minHeap.push(lists[i]);
		}

		while (!minHeap.empty()) {
			current->next = minHeap.top();
			minHeap.pop();
			current = current->next;
			if (current->next)
				minHeap.push(current->next);			
		}

		return sortedList->next;
	}
};

void printList(ListNode* list) {
	ListNode* current = list;
	while (current) {
		cout << current->val << " ";
		current = current->next;
	}
	cout << endl;
}

void mergeKLists() {
	ListNode arr[3];
	vector<ListNode*> lists;
	Solution obj;
	ListNode* result;

	
	arr[0].val = 0;
	arr[1].val = 2;
	arr[2].val = 5;

	lists.push_back(&arr[0]);
	lists.push_back(&arr[1]);
	lists.push_back(&arr[2]);

	result = obj.mergeKLists(lists);
	printList(result);
}