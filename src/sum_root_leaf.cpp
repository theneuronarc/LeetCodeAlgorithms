/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

#include "std_headers.h"

void dfs(TreeNode* root, int branchSum, int* totalSum) {
	if (!root)
		return;

	if (!root->left && !root->right) {
		branchSum += root->val;
		*totalSum += branchSum;
		return;
	}

	dfs(root->left, (branchSum * 10 + root->val), totalSum);
	dfs(root->right, (branchSum * 10 + root->val), totalSum);
}

int sumNumbers(struct TreeNode* root) {
	int totalSum = 0;	
	dfs(root, 0, &totalSum);
	return totalSum;
}