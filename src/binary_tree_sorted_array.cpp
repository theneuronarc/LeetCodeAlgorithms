/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

#include "std_headers.h"

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	if (!numsSize)
		return NULL;
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = nums[numsSize / 2];
	root->left = sortedArrayToBST(nums, numsSize / 2);
	root->right = sortedArrayToBST(nums + numsSize/2 + 1, (numsSize-1) / 2);
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
	int count = 0;
	ListNode* current = head;
	while (current) {
		count++;
		current = current->next;
	}

	int* data = (int*)malloc(sizeof(int)*count);
	count = 0;
	while (current) {
		data[count] = current->val;
		count++;
		current = current->next;
	}

	return sortedArrayToBST(data, count);
}

int getHeight(TreeNode* root) {
	if (!root)
		return 0;

	int heightLeft = getHeight(root->left);
	if (heightLeft == -1)
		return -1;

	int heightRight = getHeight(root->right);
	if (heightRight == -1)
		return -1;

	if (abs(heightLeft - heightRight) > 1)
		return -1;

	int height = max(heightLeft, heightRight);
	return (height + 1);
}

bool isBalanced(struct TreeNode* root) {
	int height = getHeight(root);
	return (height != -1 ? true : false);
}

bool preorderSum(TreeNode* root, int curSum, int sum) {
	if (!root)
		return false;

	if (!root->left && !root->right) {
		if (curSum + root->val == sum)
			return true;
		else
			return false;
	}

	if (preorderSum(root->left, curSum + root->val, sum))
		return true;

	if (preorderSum(root->right, curSum + root->val, sum))
		return true;

	return false;
}

bool hasPathSum(struct TreeNode* root, int sum) {
	return preorderSum(root, 0, sum);
}

void preorderSum2(TreeNode* root, int* path, int level, int curSum, int sum,
	int** paths, int* columnSizes, int* returnSize) {
	if (!root)
		return;

	printf("\n%d %d", root->val, curSum);
	path[level] = root->val;

	if (!root->left && !root->right) {
		printf(" LEAF");
		if (curSum + root->val == sum) {
			paths[*returnSize] = (int*)malloc(sizeof(int)*(level + 1));
			for (int i = 0; i <= level; i++) {
				*(paths[*returnSize] + i) = path[i];
			}
			columnSizes[*returnSize] = level + 1;
			(*returnSize)++;
			printf(" %d", *returnSize);
		}
	}

	preorderSum2(root->left, path, level + 1, curSum + root->val, sum, paths, columnSizes, returnSize);

	preorderSum2(root->right, path, level + 1, curSum + root->val, sum, paths, columnSizes, returnSize);
}

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
	int path[1024] = { 0 };
	int** paths = (int**)malloc(sizeof(int*) * 1024);
	*columnSizes = (int*)malloc(sizeof(int) * 1024);
	*returnSize = 0;
	preorderSum2(root, path, 0, 0, sum, paths, *columnSizes, returnSize);
	printf("\n%d", *returnSize);
	return paths;
}