/*
https://leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

#include "std_headers.h"

class Permutation2 {
public:

	bool noSwap(int* arr, int start, int cur) {
		for (int i = start; i < cur; i++) {
			if (arr[i] == arr[cur])
				return true;
		}
		return false;			
	}

	void permuteDFS(int* arr, int start, int end, vector<int>& set, vector<vector<int>>& res) {
		int tmp;
		if (start == end) {
			set.push_back(arr[start]);
			res.push_back(set);
			set.pop_back();
			printList(res.back());
			return;
		}

		for (int i = start; i <= end; i++) {
			if (noSwap(arr, start, i))
				continue;
			swap(arr[start], arr[i]);
			set.push_back(arr[start]);
			permuteDFS(arr, start + 1, end, set, res);
			swap(arr[start], arr[i]);
			set.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> set;
		permuteDFS(nums.data(), 0, nums.size() - 1, set, res);
		return res;
	}
};

void perm2Main() {
	Permutation2 obj;
	vector<int> nums = { 1,1,1 };
	obj.permuteUnique(nums);
}