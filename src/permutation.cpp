/*
https://leetcode.com/problems/permutations/

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include "std_headers.h"

class Solution {
public:
	void permuteDFS(int* arr, int start, int end, vector<int>& set, vector<vector<int>>& res) {
		if (start == end) {
			set.push_back(arr[start]);
			res.push_back(set);
			set.pop_back();
			printList(res.back(	));
			return;
		}		

		for (int i = start; i <= end; i++) {
			swap(arr[start], arr[i]);
			set.push_back(arr[start]);
			permuteDFS(arr, start + 1, end, set, res);
			swap(arr[start], arr[i]);
			set.pop_back();
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> set;
		permuteDFS(nums.data(), 0, nums.size() - 1, set, res);
		return res;
	}
};

void permMain() {
	Solution obj;
	vector<int> nums = { 1,2,3};
	obj.permute(nums);
}