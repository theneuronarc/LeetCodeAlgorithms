/*
https://leetcode.com/problems/decode-ways/
*/

#include "std_headers.h"

class Solution {
public:
	void combinations(vector<int>& s, int startIdx, vector<int>& subset, vector<vector<int>>& res, int& count) {
		if (startIdx >= s.size()) {
			//printList(subset);
			//res.push_back(subset);
			count++;
			return;
		}

		int nextNum = 0;

		for (int i = startIdx; i < s.size() && i < startIdx + 2; i++) {
			nextNum += s[i];
			if (nextNum > 0 && nextNum < 27) {
				subset.push_back(nextNum);
				combinations(s, i + 1, subset, res, count);
				subset.pop_back();
			}
			else
				continue;

			nextNum *= 10;
		}
	}

	int numDecodings(string s) {
		vector<int> subset;
		vector<vector<int>> res;
		vector<int> input;
		int count = 0;

		for (int i = 0; i < s.size(); i++) {
			input.push_back(s[i] - '0');
			if (input[i] > 9 || input[i]< 1)
				return 0;
		}
		combinations(input, 0, subset, res, count);
		return count;
	}
};