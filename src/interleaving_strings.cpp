/*
https://leetcode.com/problems/interleaving-string/
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include "std_headers.h"

class Solution {
public:
	bool interleaveBT(string& s1, int b1, string& s2, int b2, string& s3, int b3) {
		cout << s1.substr(b1);
		if (b1 == s1.size() || b2 == s2.size() || b3 == s3.size())
			return true;

		if (b3 < s3.size() && b1 < s1.size() && s1[b1] == s3[b3]) {
			if (interleaveBT(s1, b1 + 1, s2, b2, s3, b3 + 1))
				return true;
		}

		if (b3 < s3.size() && b2 < s2.size() && s1[b2] == s3[b3]) {
			if (interleaveBT(s1, b1, s2, b2 + 1, s3, b3 + 1))
				return true;
		}

		return false;
	}

	int InterleaveDP(string& s1, int b1, string& s2, int b2, string& s3, int b3, vector<vector<int>>& table) {
		//cout << "(" << b1 << "," << b2 << "," << b3 << ")" << endl;
		//cout << " s1 = " << s1.substr(0, b1) << " s2 = " << s2.substr(0, b2) << " s3 = " << s3.substr(0, b3) << endl;
		b1 = (b1 < 0) ? 0 : b1;
		b2 = (b2 < 0) ? 0 : b2;

		if (table[b1][b2] != 0) {
			//cout << "calculated = " << table[b1][b2] << endl;
			return table[b1][b2];
		}

		table[b1][b2] = -1;

		if (s1[b1 - 1] == s3[b3 - 1]) {
			if (InterleaveDP(s1, b1 - 1, s2, b2, s3, b3 - 1, table) == 1)
				table[b1][b2] = 1;
			else
				table[b1][b2] = -1;
		}

		if (table[b1][b2] == 1)
			return table[b1][b2];

		if (s2[b2 - 1] == s3[b3 - 1]) {
			if (InterleaveDP(s1, b1, s2, b2 - 1, s3, b3 - 1, table) == 1)
				table[b1][b2] = 1;
			else
				table[b1][b2] = -1;
		}

		return table[b1][b2];
	}

	bool isInterleave(string s1, string s2, string s3) {
		int size1 = s1.size();
		int size2 = s2.size();
		int size3 = s3.size();
		int res;
		vector<vector<int>> table(size1 + 1, vector<int>(size2 + 1, 0));

		if ((size1 + size2) != size3)
			return false;

		table[0][0] = 1;
		res = InterleaveDP(s1, size1, s2, size2, s3, size3, table);
		if (res == 1)
			return true;
		else
			return false;
	}
};


void interleavingStringsMain() {
	Solution obj;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	obj.isInterleave(s1, s2, s3);
}