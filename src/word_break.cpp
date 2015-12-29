/*
https://leetcode.com/problems/word-break/
*/

#include "std_headers.h"

class Solution {
public:
	bool wordBreakCheck(string& s, unordered_set<string>& wordDict) {
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

	vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
		int size = s.size();
		vector<string> res;
		vector<vector<string>> tableDP(size, vector<string>());	
		if (!wordBreakCheck(s, wordDict))
			return res;

		if (wordDict.count(s.substr(size - 1, 1))) {
			tableDP[size - 1].push_back(s.substr(size - 1, 1));
		}

		for (int i = size - 2; i >= 0; i--) {
			if (wordDict.count(s.substr(i, size - i))) {
				tableDP[i].push_back(s.substr(i, size - i));
			}

			for (int j = i + 1; j < size; j++) {
				cout << i << " " << j << endl;
				if (!tableDP[j].empty() && wordDict.count(s.substr(i, j - i))) {
					for (int k = 0; k < tableDP[j].size(); k++) {
						string t = s.substr(i, j - i) + " " + tableDP[j][k];
						tableDP[i].push_back(t);
					}
				}
			}
		}
		
		return tableDP[0];
	}
};

void wordBreakMain() {
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string s = "catsanddog";
	unordered_set<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
	Solution obj;
	
	printList(obj.wordBreak2(s, wordDict));
}