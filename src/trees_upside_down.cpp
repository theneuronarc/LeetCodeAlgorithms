/*
http://www.careercup.com/question?id=6266917077647360
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

struct TreeNode* upsideDown(struct TreeNode* root) {
	struct TreeNode* node;
	if (root->left) {
		upsideDown(root->left);
		root->left->right = root;
		root->left->left = root->right;
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}