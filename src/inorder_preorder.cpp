/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/
#include "std_headers.h"
typedef struct TreeNode TreeNode;

typedef struct TreeNode TreeNode;

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int pIdx = 0;
	int iIdx = 0;

	if (!preorderSize)
		return NULL;

	TreeNode *cur, *root, *top;
	root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = preorder[pIdx++];
	root->left = NULL;
	root->right = NULL;

	top = root;

	TreeNode** path = (TreeNode**)malloc(sizeof(TreeNode*)*(preorderSize + 1));
	int pathIdx = -1;
	bool isLeft = true;

	while (pIdx < preorderSize) {
		if (root->val == inorder[iIdx]) {
			iIdx++;
			if (pathIdx >= 0 && inorder[iIdx] == path[pathIdx]->val) {
				root = path[pathIdx];
				pathIdx--;
				continue;
			}
			else {
				isLeft = false;
			}
		}
		else {
			pathIdx++;
			path[pathIdx] = root;
			isLeft = true;
		}

		cur = (TreeNode*)malloc(sizeof(TreeNode));
		cur->val = preorder[pIdx];
		cur->left = NULL;
		cur->right = NULL;

		pIdx++;

		if (isLeft)
			root->left = cur;
		else
			root->right = cur;

		root = cur;
	}

	return top;
}

void inorederPreOrderMain() {
	int preorder[] = { 1,2,3};
	int inOrder[] = { 2,1,3};

	buildTree(preorder, 3, inOrder, 3);
}