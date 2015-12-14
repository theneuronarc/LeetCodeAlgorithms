/*
https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
*/

#include "std_headers.h"

class Solution {
public:
	bool ssdDfs(int* nums, int size, int start, vector<int>& subset, vector<vector<int>>& res) {
		int prev;
		if (start == size)
			return true;

		for (int i = start; i < size; i++) {
			if (i > start && nums[i] == prev)
				continue;

			subset.push_back(nums[i]);
			res.push_back(subset);
			ssdDfs(nums, size, i + 1, subset, res);
			subset.pop_back();
			prev = nums[i];
		}

		return true;
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		res.push_back(subset);
		int size = nums.size();
		std::sort(nums.begin(), nums.end());
		ssdDfs(nums.data(), size, 0, subset, res);

		return res;
	}
};

void ssdMain() {
	Solution obj;
	vector<int> vec = { 1,1,2,2,4,3};

	obj.subsetsWithDup(vec);
}