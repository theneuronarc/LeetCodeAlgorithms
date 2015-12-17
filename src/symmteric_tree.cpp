/*
https://leetcode.com/problems/symmetric-tree/
*/

#include "std_headers.h"

class Solution {
public:
	bool preOrder(TreeNode* tree1, TreeNode* tree2) {
		if ((bool)tree1 ^ (bool)tree2) {
			return false;
		}
		if (!tree1 || !tree2)
			return true;

		//cout << tree1->val << "  "<< tree2->val << endl;

		if (tree1->val != tree2->val)
			return false;

		if (!preOrder(tree1->left, tree2->right))
			return false;

		if (!preOrder(tree1->right, tree2->left))
			return false;

		return true;

	}
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return preOrder(root->left, root->right);
	}
};