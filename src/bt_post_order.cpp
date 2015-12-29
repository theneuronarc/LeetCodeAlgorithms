/*
https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

#include "std_headers.h"

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

typedef struct TreeNode TreeNode;

typedef struct Node {
	int val;
	TreeNode *root;
}Node;

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	if (!root) {
		*returnSize = 0;
		return 0;
	}

	Node* cur;
	int* postorder = (int*)malloc(sizeof(int) * 1024);
	int count = 0;
	Node* stack = (Node*)malloc(sizeof(Node) * 1024);
	int stackTop = 0;

	stack[0].val = 0;
	stack[0].root = root;
	printf("\nStart");
	while (stackTop >= 0) {
		cur = &(stack[stackTop--]);
		printf("\n%d %d", cur->root->val, stackTop);
		if (cur->val) {
			printf("\n%d", cur->val);
			postorder[count++] = cur->root->val;
		}
		else {
			stack[++stackTop].val = 1;
			stack[stackTop].root = cur->root;

			if (cur->root->right) {
				stack[++stackTop].val = 0;
				stack[stackTop].root = cur->root->right;
			}

			if (cur->root->left) {
				stack[++stackTop].val = 0;
				stack[stackTop].root = cur->root->left;
			}
		}
	}

	*returnSize = count;
	return postorder;
}