/*
https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ? a2 ? … ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

#include "std_headers.h"

class Solution1 {
public:
	void findSet(int arr[], int start, const int& end, vector<int>& subset, int sum, int target, vector<vector<int>>& res) {
		if (target == sum) {
			res.push_back(subset);
			return;
		}

		if (start > end || sum > target)
			return;

		for (int i = start; i <= end; i++) {
			subset.push_back(arr[i]);
			findSet(arr, i, end, subset, sum + arr[i], target, res);
			subset.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> subset;
		vector<vector<int>> result;

		if (candidates.empty())
			return result;

		std::sort(candidates.begin(), candidates.end());
		findSet(candidates.data(), 0, candidates.size() - 1, subset, 0, target, result);
		return result;
	}
};

class Solution {
public:
	void findSet(int arr[], int start, const int& end, int subset[], int size,  int target, int level, vector<vector<int>>& res) {
		if (target == 0) {
			res.push_back(vector<int>(subset, subset + size));
			return;
		}

		if (start > end || target < 0)
			return;

		for (int i = start; i <= end; i++) {
			subset[size] = arr[i];
			findSet(arr, i+1, end, subset, size + 1,  target - arr[i], level + 1, res);			
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {		
		vector<vector<int>> result;
		int *subset = new int[target];
		if (candidates.empty())
			return result;
		
		std::sort(candidates.begin(), candidates.end());
		findSet(candidates.data(), 0, candidates.size() - 1, subset, 0, target, 0,  result);
		return result;
	}
};

void combinationSumMain() {
	Solution obj;
	vector<int> vc = { 2,2,2 };
	vector<vector<int>> res;
	res = obj.combinationSum(vc, 4);

	for (int i = 0; i < res.size(); i++)
		printList(res[i]);
}