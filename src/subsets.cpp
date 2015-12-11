/*
https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*/

#include "std_headers.h"

class Solution {
public:
	void subsetTree(int start, int n, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
		if (start >= n) {
			res.push_back(subset);
			return;
		}

		for (int i = start; i < n; i++) {
			subset.push_back(nums[i]);
			subsetTree(i + 1, n, nums, subset, res);
			subset.pop_back();
		}
		res.push_back(subset);
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		subsetTree(0, nums.size(), nums, subset, res);
		return res;
	}
};