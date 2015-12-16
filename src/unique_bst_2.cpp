#include "std_headers.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

	int numTrees(int n) {
		int* table = new int[n + 1];
		table[0] = 1;
		table[1] = 1;
		for (int i = 2; i <= n; i++) {
			table[i] = 0;
			for (int j = 0; j < i / 2; j++) {
				table[i] += (table[j] * table[i - 1 - j]);
			}
			table[i] <<= 1;
			if (i % 2)
				table[i] += (table[i / 2] * table[i / 2]);
		}

		return table[n];
	}

	void genTreesRec(int start, int end, vector<TreeNode*>& res) {
		vector<TreeNode*> leftTrees;
		vector<TreeNode*> rightTrees;
		

		for (int i = start; i <= end; i++) {
			leftTrees.clear();
			rightTrees.clear();
			if (i > start)
				genTreesRec(start, i - 1, leftTrees);
			else
				leftTrees.push_back(NULL);

			if (i < end)
				genTreesRec(i + 1, end, rightTrees);
			else
				rightTrees.push_back(NULL);

			for (int l = 0; l < leftTrees.size(); l++) {
				for (int r = 0; r < rightTrees.size(); r++) {
					TreeNode* cur = new TreeNode(i);
					cur->left = leftTrees.at(l);
					cur->right = rightTrees.at(r);
					res.push_back(cur);
				}
			}
		}
	}

	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		genTreesRec(1, n, res);
		return res;
	}
};