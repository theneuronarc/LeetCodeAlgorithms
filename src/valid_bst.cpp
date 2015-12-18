/*
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

#include "std_headers.h"


typedef struct {
	bool valid;
	int smallest;
	int largest;
}bstResult;

class Solution {
public:
	void isValidRec(TreeNode* root, bstResult& res) {
		bstResult leftRes = { 0 };
		bstResult rightRes = { 0 };

		if (!(root->left || root->right)) {
			res.valid = true;
			res.largest = root->val;
			res.smallest = root->val;
			return;
		}

		if (root->left) {
			isValidRec(root->left, leftRes);
			if (leftRes.valid && (leftRes.largest < root->val)) {
				res.valid = true;
				res.smallest = leftRes.smallest;
				res.largest = root->val;
			}
			else
				res.valid = false;
		}
		else
			res.valid = true;

		if (!res.valid)
			return;

		if (root->right) {
			isValidRec(root->right, rightRes);
			if (rightRes.valid && (rightRes.smallest > root->val)) {
				res.valid = true;
				res.smallest = (root->left ? res.smallest : root->val);
				res.largest = rightRes.largest;
			}
			else
				res.valid = false;
		}
	}

	bool isValidBST(TreeNode* root) {
		bstResult res;
		if (!root) return true;
		isValidRec(root, res);
		return res.valid;
	}
};