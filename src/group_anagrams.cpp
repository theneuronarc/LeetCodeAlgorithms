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

bool lexicalCompare(string& str1, string& str2) {
	int res = str1.compare(str2);

	if (res <= 0)
		return true;
	else
		return false;
}

class Solution {
public:

	int matchString(vector<string>& words, string& str) {
		for (int i = 0; i < words.size(); i++) {
			if (!words[i].compare(str))
				return i;
		}
		return -1;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		map<string, int> wordMap;
		int idx;
		int anagramIdx = 1;

		if (strs.empty())
			return result;

		result.push_back(vector<string>());

		for (int i = 0; i < strs.size(); i++) {
			string str = strs[i];
			std::sort(str.begin(), str.end());

			idx = wordMap[str];

			if (idx == 0)
				wordMap[str] = anagramIdx++;

			if (idx != 0) {
				result[idx].push_back(strs[i]);
			}
			else {
				result.push_back(vector<string>());
				result.back().push_back(strs[i]);
			}
		}

		for (int i = 0; i < result.size(); i++) {
			std::sort(result[i].begin(), result[i].end(), lexicalCompare);
		}

		return result;
	}
};

void groupAnagramMain() {
	Solution obj;
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	obj.groupAnagrams(strs);
}