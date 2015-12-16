/*
https://leetcode.com/problems/recover-binary-search-tree/

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

#include "std_headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct {
	bool valid;
	int smallest;
	int largest;
}bstResult;


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if ((bool)p ^ (bool)q)
			return false;

		if (!p && !q)
			return true;

		if (p->val != q->val)
			return false;

		if ((bool)p->left ^ (bool)q->left)
			return false;

		if ((bool)p->right ^ (bool)q->right)
			return false;

		if (!isSameTree(p->left, q->left))
			return false;

		if (!isSameTree(p->right, q->right))
			return false;

		return true;
	}

	TreeNode* findLCA(TreeNode* root, bstResult& res) {
		bstResult leftRes = { 0 };
		bstResult rightRes = { 0 };
		TreeNode* LCA;

		if (!(root->left || root->right)) {
			res.valid = true;
			res.largest = root->val;
			res.smallest = root->val;
			return 0;
		}

		if (root->left) {
			LCA = findLCA(root->left, leftRes);
			if (LCA)
				return LCA;

			if (leftRes.valid && leftRes.largest > root->val) {
				leftRes.valid = false;				
			}
		}
		else
			leftRes.valid = true;

		if (root->right) {
			LCA = findLCA(root->right, rightRes);
			if (LCA)
				return LCA;

			if (rightRes.valid && rightRes.smallest < root->val) {
				res.valid = false;
			}
		}

		res.valid = (leftRes.valid && rightRes.valid);

		if (res.valid) {
			res.smallest = (root->left ? leftRes.smallest : root->val);
			res.largest = (root->right ? rightRes.largest : root->val);
		}

		if (!leftRes.valid && !rightRes.valid)
			return root;
		else
			return 0;

	}

	TreeNode* preOrder(TreeNode* root) {
		TreeNode* badNode;
		if (!root)
			return NULL;

		if (root->left && root->val < root->left->val)
			badNode = preOrder(root->left);
		else
			badNode = root->left;

		if (badNode)
			return badNode;

		if (root->right && root->val > root->right->val)
			badNode = preOrder(root->right);
		else
			badNode = root->right;

		if (badNode)
			return badNode;
		else
			return 0;
	}

	void recover(TreeNode* LCA) {
		TreeNode* tmp;
		TreeNode* left = preOrder(LCA->left);
		TreeNode* right = preOrder(LCA->right);

		tmp = left;
		left = right;
		right = tmp;
	}

	void recoverTree(TreeNode* root) {
		bstResult res;
		TreeNode* LCA = findLCA(root, res);
		recover(LCA);
	}	
};