/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

#include "std_headers.h"

#define max(a,b) (a>b?a:b)
typedef struct TreeNode TreeNode;

typedef struct {
	int pathSumMax;
	int pathSumRoot;
}Result;

Result maxPathDFS(TreeNode* root) {
	Result res = { 0 };
	Result leftTree, rightTree;

	if (!root)
		return res;

	if (!root->left && !root->right) {
		res.pathSumMax = root->val;
		res.pathSumRoot = root->val;
		return res;
	}

	if (root->left)
		leftTree = maxPathDFS(root->left);

	if (root->right)
		rightTree = maxPathDFS(root->right);

	if (root->left && root->right) {
		int tmp = max(leftTree.pathSumMax, rightTree.pathSumMax);
		tmp = max(tmp, root->val);
		tmp = max(tmp, leftTree.pathSumRoot + rightTree.pathSumRoot + root->val);
		tmp = max(tmp, leftTree.pathSumRoot + root->val);
		tmp = max(tmp, rightTree.pathSumRoot + root->val);
		res.pathSumMax = tmp;

		if (tmp == root->val)
			res.pathSumRoot = root->val;
		else
			res.pathSumRoot = max(leftTree.pathSumRoot, rightTree.pathSumRoot) + root->val;
	}
	else {
		res = (root->left ? leftTree : rightTree);
		int tmp = max(res.pathSumMax, (res.pathSumRoot + root->val));
		tmp = max(tmp, root->val);
		res.pathSumMax = tmp;
		if (tmp == root->val)
			res.pathSumRoot = root->val;
		else
			res.pathSumRoot += root->val;
	}

	return res;
}


int maxPathSum(struct TreeNode* root) {
	if (!root)
		return INT_MIN;
	Result res = maxPathDFS(root);
	return res.pathSumMax;
}