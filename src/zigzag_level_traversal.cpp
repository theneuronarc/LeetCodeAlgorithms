/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

#include "std_headers.h"

class Solution {
public:

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<TreeNode*> line[2];
		vector<vector<int>> res;
		vector<int> scan;

		if (!root)
			return res;

		bool curLine = 0;
		int curIdx = 0;
		bool dir = 1;
		TreeNode* node;

		res.push_back(vector<int>({ root->val }));

		if (root->left)
			line[curLine].push_back(root->left);

		if (root->right)
			line[curLine].push_back(root->right);

		curIdx = line[curLine].size() - 1;

		while (!line[curLine].empty()) {
			node = line[curLine][curIdx];
			scan.push_back(node->val);
			if (dir) {
				if (node->right)
					line[!curLine].push_back(node->right);
				if (node->left)
					line[!curLine].push_back(node->left);
			}
			else {
				if (node->left)
					line[!curLine].push_back(node->left);
				if (node->right)
					line[!curLine].push_back(node->right);
			}

			curIdx--;

			if (curIdx < 0) {
				res.push_back(scan);
				scan.clear();
				line[curLine].clear();
				dir = !dir;
				curLine = !curLine;
				curIdx = line[curLine].size() - 1;
			}
		}

		return res;
	}
};