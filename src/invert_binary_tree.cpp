/*
https://leetcode.com/problems/invert-binary-tree/
*/

struct TreeNode* invertTree(struct TreeNode* root) {
	if (!root)
		return root;

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}