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


class Solution1 {
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
};

class Solution {
public:
	TreeNode* recover(TreeNode* root, TreeNode* prev, TreeNode** first, TreeNode** second, bool& isFirst) {
		if (!root)
			return NULL;

		if (!root->left && !root->right) {
			if (prev != NULL) {
				if (prev->val > root->val) {
					if (isFirst) {
						*first = prev;
						*second = root;
						isFirst = false;
						//cout << "1 : " << prev->val << " " << root->val<< endl;
					}
					else {
						*second = root;
						//cout << "2 : " << root->val<< endl;
					}
				}
			}
			return root;
		}

		TreeNode* prevLeft = recover(root->left, prev, first, second, isFirst);
		prev = (prevLeft ? prevLeft : prev);
		if (prev != NULL) {
			if (prev->val > root->val) {
				if (isFirst) {
					*first = prev;
					*second = root;
					isFirst = false;
					//cout << "3 : " << prev->val << " " << root->val << endl;
				}
				else {
					*second = root;
					//cout << "4 : " << root->val<< endl;
				}
			}
		}

		prev = root;

		TreeNode* prevRight = recover(root->right, prev, first, second, isFirst);
		prevRight = (prevRight ? prevRight : root);
		return prevRight;
	}

	void recoverTree(TreeNode* root) {
		TreeNode *first = 0, *second = 0;
		bool isFirst = true;
		recover(root, NULL, &first, &second, isFirst);
		if (first && second) {
			int tmp = first->val;
			first->val = second->val;
			second->val = tmp;
		}
	}
};