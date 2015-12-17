/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/

#include "std_headers.h"

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		std::queue<TreeNode*> fifo;
		vector<int> level;
		vector<vector<int>> res;
		
		TreeNode* last = root;
		TreeNode* current;
		TreeNode* tmpLast;

		fifo.push(root);
		while (!fifo.empty()) {
			current = fifo.front();
			fifo.pop();
			level.push_back(current->val);
			if (current->left) {
				fifo.push(current->left);
				tmpLast = current->left;
			}

			if (current->right) {
				fifo.push(current->right);
				tmpLast = current->right;
			}

			if (current == last) {
				res.push_back(level);
				level.clear();
				last = tmpLast;
			}
		}

		return res;
		
	}
};