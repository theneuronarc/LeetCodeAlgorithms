/*
https://leetcode.com/problems/combinations/


Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is :

[
	[2, 4],
	[3, 4],
	[2, 3],
	[1, 2],
	[1, 3],
	[1, 4],
]

*/

#include "std_headers.h"

class Solution {
public:
	void combinationTree(int start, int k, int n, int depth, vector<int>& subset, vector<vector<int>>& res) {
		if (depth >= k) {
			res.push_back(subset);
			return;
		}

		for (int i = start; i < n && ((n - i) >= (k - depth)); i++) {
			subset.push_back(i + 1);
			combinationTree(i + 1, k, n, depth + 1, subset, res);
			subset.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<int> subset;
		vector<vector<int>> res;
		if (!k) {
			res.push_back(subset);
			return res;
		}


		if (!n || k > n)
			return res;

		combinationTree(0, k, n, 0, subset, res);

		return res;
	}
};

void combinationMain() {
	Solution obj;
	obj.combine(4, 2);
}