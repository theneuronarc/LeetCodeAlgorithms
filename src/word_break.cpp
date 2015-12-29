/*
https://leetcode.com/problems/word-break/
*/

#include "std_headers.h"

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int size = s.size();
		vector<bool> tableDP(size, false);
		for (int i = 0; i < size; i++) {
			if (wordDict.count(s.substr(0, i+1)))
				tableDP[i] = true;
			else {
				for (int j = i - 1; j >= 0; j--) {
					if (tableDP[j] && wordDict.count(s.substr(j + 1, i - j))) {
						tableDP[i] = true;
						break;
					}					
				}
			}
		}

		return tableDP[size - 1];
	}
};

void wordBreakMain() {
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string s = "leetcode";
	unordered_set<string> wordDict = { "leet", "code" };
	Solution obj;
	cout << "result = " << obj.wordBreak(s, wordDict) << endl;
}