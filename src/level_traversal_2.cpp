/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/

#include "std_headers.h"

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *columnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
typedef struct TreeNode TreeNode;
#define max(a,b) (a>b?a:b)

void preorder(TreeNode* root, int level, int* levelCount, int* maxDepth, int** levels) {
	if (!root)
		return;

	if (levels) {
		*(levels[*maxDepth - level] + levelCount[*maxDepth - level]) = root->val;
		levelCount[*maxDepth - level]++;
	}
	else {
		levelCount[level]++;
		*maxDepth = max(*maxDepth, level);
	}

	preorder(root->left, level + 1, levelCount, maxDepth, levels);
	preorder(root->right, level + 1, levelCount, maxDepth, levels);
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if (!root)
		return NULL;
	int* levelCount = (int*)calloc(1024, sizeof(int));
	int** levels = 0;
	int maxDepth = 0;
	preorder(root, 0, levelCount, &maxDepth, levels);
	levels = (int**)malloc(sizeof(int*)*(maxDepth + 1));

	for (int i = maxDepth; i >= 0; i--) {
		levels[maxDepth - i] = (int*)malloc(sizeof(int)*levelCount[i]);
		levelCount[i] = 0;
	}

	preorder(root, 0, levelCount, &maxDepth, levels);
	*columnSizes = levelCount;
	*returnSize = maxDepth + 1;
	return levels;
}