/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

int searchLCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, TreeNode** LCA) {
	int c = 0;
	if (!root)
		return 0;

	if (root == p || root == q) {
		c = 1;
	}

	int a = searchLCA(root->left, p, q, LCA);
	if (a == 2)
		return a;

	if (a == 1 && c == 1) {
		*LCA = root;
		return 2;
	}

	int b = searchLCA(root->right, p, q, LCA);
	if (b == 2)
		return b;

	if (b == 1 && c == 1) {
		*LCA = root;
		return 2;
	}

	if (a == 1 && b == 1) {
		*LCA = root;
	}

	return (a + b + c);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	TreeNode* LCA;
	searchLCA(root, p, q, &LCA);
	return LCA;
}



struct TreeNode* searchLCA(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct TreeNode* LCA;

	if (!root)
		return 0;

	if (root->val >= p->val && root->val <= q->val)
		return root;
	
	if (LCA = searchLCA(root->left, p, q))
		return LCA;

	if (LCA = searchLCA(root->right, p, q))
		return LCA;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (p->val > q->val) {
		struct TreeNode* tmp = p;
		p = q;
		q = tmp;
	}
	return searchLCA(root, p, q);
}