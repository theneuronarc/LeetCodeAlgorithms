/*
https://leetcode.com/problems/restore-ip-addresses/
*/

#include "std_headers.h"


class Solution {
public:
	void combinations(vector<int>& nums, int depth, int startIdx, vector<int>& subset, vector<vector<int>>& res) {
		if (depth > 4 && startIdx < nums.size())
			return;

		int nextNum = 0;

		for (int i = startIdx; i < nums.size() && i < startIdx + 3; i++) {
			nextNum += nums[i];
			if (!nums[startIdx] && i > startIdx)
				continue;

			if (nextNum <= 255) {
				subset.push_back(i + 1);
				combinations(nums, depth + 1, i + 1, subset, res);
				if (depth == 4 && i == nums.size() - 1) {
					//printList(subset);
					res.push_back(subset);
				}
				subset.pop_back();
			}
			else
				continue;

			nextNum *= 10;
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<int> subset;
		vector<vector<int>> dotPos;
		vector<int> input;
		vector<string> res;

		if (s.size() > 12)
			return res;

		for (int i = 0; i < s.size(); i++) {
			input.push_back(s[i] - '0');
		}
		combinations(input, 1, 0, subset, dotPos);

		for (int i = 0; i < dotPos.size(); i++) {
			string add;

			add += s.substr(0, dotPos[i][0]);
			add.push_back('.');
			add += s.substr(dotPos[i][0], dotPos[i][1] - dotPos[i][0]);
			add.push_back('.');
			add += s.substr(dotPos[i][1], dotPos[i][2] - dotPos[i][1]);
			add.push_back('.');
			add += s.substr(dotPos[i][2], dotPos[i][3] - dotPos[i][1]);

			res.push_back(add);

		}
		return res;
	}
};



void resIPMain(){
	Solution obj;
	obj.restoreIpAddresses("255255111111");
}