#include "std_headers.h"

typedef struct TreeNode TreeNode;

int search(int* data, int size, int val) {
	for (int i = 0; i < size; i++) {
		if (data[i] == val)
			return i;
	}
	return -1;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
	if (!inorderSize)
		return NULL;
	int pIdx = postorderSize - 1;
	int partition;
	int leftCount, rightCount;
	TreeNode* top = (TreeNode*)malloc(sizeof(TreeNode));
	top->val = postorder[pIdx];
	top->right = NULL;
	top->left = NULL;

	partition = search(inorder, inorderSize, top->val);
	if (partition == -1)
		return top;

	leftCount = partition;
	rightCount = inorderSize - leftCount - 1;

	if (leftCount) {
		top->left = buildTree(inorder, leftCount, postorder, leftCount);
	}

	if (rightCount) {
		top->right = buildTree(inorder + leftCount + 1, rightCount, postorder + leftCount, rightCount);
	}

	return top;
}