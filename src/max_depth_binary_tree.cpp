/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

#include "std_headers.h"

class Solution {
public:
	void inOrder(TreeNode* root, int depth, int& maxDepth) {
		if (!root->left && !root->right) {
			maxDepth = max(maxDepth, depth);
			return;
		}

		if (root->left) {			
			inOrder(root->left, depth + 1, maxDepth);			
		}

		if (root->right) {
			inOrder(root->right, depth + 1, maxDepth);
		}
	}

	int maxDepth(TreeNode* root) {
		int maxDepth = -1;
		if (!root)
			return 0;
		inOrder(root, 1, maxDepth);
		return maxDepth;
	}

	void inOrderMin(TreeNode* root, int depth, int& minDepth) {
		if (!root->left && !root->right) {
			minDepth = min(minDepth, depth);
			return;
		}

		if (root->left) {
			inOrder(root->left, depth + 1, minDepth);
		}

		if (root->right) {
			inOrder(root->right, depth + 1, minDepth);
		}
	}

	int minDepth(TreeNode* root) {
		int minDepth = INT_MAX;
		if (!root)
			return 0;
		inOrder(root, 0, minDepth);
		return minDepth;
	}
};