#include "std_headers.h"


class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {

	}

	int numTrees(int n) {
		int* table = new int[n+1];
		table[0] = 1;
		table[1] = 1;
		int count = 0;
		for (int i = 2; i < n; i++) {
			table[i] = 0;
			for (int j = 0; j < i / 2; j++) {
				table[i] += (table[j] * table[i - 1 - j]);
			}
			table[i] <<= 1;
			if (i % 2) {
				table[i] += (table[i / 2] * table[i / 2]);
			}
		}

		return table[n];

	}
};

void uniqueBSTMain() {
	Solution obj;
	obj.numTrees(4);
}