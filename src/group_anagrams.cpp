/*
https://leetcode.com/problems/anagrams/
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

*/

#include "std_headers.h"

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, int> wordMap;
		int idx;

		if (strs.empty())
			return result;

		for (int i = 0; i < strs.size(); i++) {
			string str(strs[i]);
			std::sort(str.begin(), str.end());

			idx = wordMap[str];

			if (idx != 0) {
				result[idx - 1].push_back(strs[i]);
				std::sort(result[idx-1].begin(), result[idx-1].end());
			}
			else {
				result.push_back(vector<string>({ strs[i] }));
				wordMap[str] = result.size();
			}
		}
		return result;
	}
};

void groupAnagramMain() {
	Solution obj;
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	obj.groupAnagrams(strs);
}