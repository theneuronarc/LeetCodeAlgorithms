/*
https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

#include "std_headers.h"

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	if (!root) {
		*returnSize = 0;
		return 0;
	}

	TreeNode* cur;
	int* preorder = (int*)malloc(sizeof(int) * 1024);
	int count = 0;
	TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode*) * 1024);
	int stackTop = 0;

	stack[0] = root;

	while (stackTop >= 0) {
		cur = stack[stackTop--];
		preorder[count] = cur->val;
		count++;
		if (cur->right)
			stack[++stackTop] = cur->right;
		if (cur->left)
			stack[++stackTop] = cur->left;
	}

	*returnSize = count;
	return preorder;
}