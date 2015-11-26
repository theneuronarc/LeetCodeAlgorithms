/*
https://leetcode.com/problems/implement-strstr/

Implement strStr().
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
Implementation of KMP algorithm for string searching
*/

#include "std_headers.h"

void computeLPSArray(const char *pat, int M, int *lps)
{
	int len = 0;  // length of the previous longest prefix suffix
	int i;

	lps[0] = 0; // lps[0] is always 0
	i = 1;

	// the loop calculates lps[i] for i = 1 to M-1
	while (i < M)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0)
			{
				// This is tricky. Consider the example 
				// AAACAAAA and i = 7.
				len = lps[len - 1];

				// Also, note that we do not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

class KMP {
	int* patFx;
public:
	void patternFunction(string& pat) {
		int prevLen = 0;
		int size = pat.size();
		patFx = new int[size];
		patFx[0] = 0;
		for (int i = 1; i < size; i++) {
			prevLen = patFx[i - 1];
			if (pat[i] == pat[prevLen]) {
				patFx[i] = prevLen + 1;
			}
			else {
				while (prevLen) {
					prevLen = patFx[prevLen - 1];
					if (pat[prevLen] == pat[i]) {
						patFx[i] = prevLen;
						break;
					}						
				}
				patFx[i] = prevLen;
			}
		}
	}

	int find(string& text, string& pat) {
		int txtSize = text.size();
		int patSize = pat.size();
		int j = 0;
		int i = 0;

		patternFunction(pat);

		while (i < txtSize) {
			if (text[i] == pat[j]) {
				i++;
				j++;
				if (j == patSize)
					return (i -j);
			}
			else {
				if (j) {
					j = patFx[j-1];
				}
				else {
					i++;
				}
			}
		}

		return -1;
	}
};

class Solution {
public:

	int strStr(string& haystack, string& needle) {
		KMP obj;
		return obj.find(haystack, needle);

	}
};

void str(string pat) {
	return;
	KMP kmp;
	int lps[1024];
	kmp.patternFunction(pat);

	cout << endl;
	computeLPSArray(pat.c_str(), pat.size(), lps);

	for (int i = 0; i < pat.size(); i++) {
		cout << pat.substr(0, (i + 1)) << " => " << pat.substr(0, lps[i]) << endl;
	}
}

void strStrMain() {
	string txt;
	string pat;
	Solution obj;

	txt = "AAAAAAAAAAAAAAAAAB";
	pat = "AAAAB";
	cout << txt.substr(0, obj.strStr(txt, pat)) << endl;

	txt = "ABABABCABABABCABABABC";
	pat = "ABABAC";
	cout << txt.substr(0, obj.strStr(txt, pat)) << endl;

	str(pat);

	pat = "AABAACAABAA";
	str(pat);

	pat = "ABCDE";
	str(pat);

	pat = "AAAAA";
	str(pat);

	pat = "AAABAAA";
	str(pat);

	pat = "AAACAAAAAC";
	str(pat);
}