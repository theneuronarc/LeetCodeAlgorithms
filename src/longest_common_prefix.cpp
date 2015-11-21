/*
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
*/


#include "std_headers.h"

class LCP {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		if (strs.empty())
			return "";

		int lastIdx = strs[0].size() - 1;
		int refIdx = 0;

		for (int i = 0; i < strs.size(); i++) {
			if (lastIdx < strs[i].size() - 1) {
				refIdx = i;
				lastIdx = strs[i].size() - 1;
			}
		}

		for (int i = 0; i < strs.size(); i++) {
			int idx = 0;
			while (idx < strs[i].size() && idx <= lastIdx)
			{
				if (strs[refIdx][idx] != strs[i][idx])
					break;
				idx++;
			}
			lastIdx = idx - 1;
		}

		if (lastIdx >= 0)
			return strs[refIdx].substr(0, lastIdx+1);
		else
			return "";
	}
};

void longestCommonPrefix() {
	LCP obj;

	vector<string> strs;
	strs.push_back("a");
	cout << obj.longestCommonPrefix(strs) << endl;

}