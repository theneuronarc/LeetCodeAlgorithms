/*
https://leetcode.com/problems/binary-tree-right-side-view/
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

void rightSideViewRec(struct TreeNode* root, int level, int* levels, int* res, int* maxDepth) {
	if (!root)
		return;

	if (!levels[level]) {
		res[level] = root->val;
		levels[level] = 1;
	}

	*maxDepth = (*maxDepth < level ? level : *maxDepth);

	rightSideViewRec(root->right, level + 1, levels, res, maxDepth);
	rightSideViewRec(root->left, level + 1, levels, res, maxDepth);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
	if (!root) {
		*returnSize = 0;
		return 0;
	}

	int* levels = (int*)calloc(1024, sizeof(int));
	int* res = (int*)malloc(sizeof(int) * 1024);
	int level;
	rightSideViewRec(root, 0, levels, res, returnSize);

	free(levels);
	(*returnSize)++;
	return res;
}

