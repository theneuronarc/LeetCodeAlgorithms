/*
https://leetcode.com/problemset/algorithms/
Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in
words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include "std_headers.h"

class KMP {
	int* patFx;
public:
	void patternFunction(const string& pat) {
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

	int find(const string& text, const string& pat, vector<int>& res) {
		int txtSize = text.size();
		int patSize = pat.size();
		int j = 0;
		int i = 0;

		patternFunction(pat);

		while (i < txtSize) {
			if (text[i] == pat[j]) {
				i++;
				j++;
				if (j == patSize) {					
					res.push_back(i - j);
				}
			}
			else {
				if (j) {
					j = patFx[j - 1];
				}
				else {
					i++;
				}
			}
		}

		return res.size();
	}
};

class Solution {
public:
	vector<int> findSubstring(const string s, const vector<string>& words) {
		int wordCount = words.size();
		int txtSize = s.size();
		int wordSize = words[0].size();
		map<int, vector<int> > searchRes;
		int* patMap = (int*)calloc(txtSize, sizeof(int));
		vector<int> res;

		for (int i = 0; i < wordCount; i++) {
			KMP obj;
			if (obj.find(s, words[i], res)) {
				searchRes[i] = res;
				res.clear();
			}

			for (int j = 0; j < searchRes[i].size(); j++) {				
				patMap[searchRes[i][j]] = (i+1);
			}
		}
		res.clear();
		for (int i = 0; i < txtSize; i++) {
			vector<bool> testMap(wordCount+1, false);
			for (int j = 0; j < wordCount; j++) {
				if (!patMap[j*wordSize + i] || testMap[patMap[j*wordSize + i]])
					break;
				else {
					testMap[patMap[j*wordSize + i]] = true;
				}
				if (j == wordCount - 1)
					res.push_back(i);
			}
		}

		return res;
	}
};

void printList(const string& txt, const vector<string>&  words) {
	Solution obj;
	vector<int> res;
	res = obj.findSubstring(txt, words);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ", ";
	}

	cout << endl;

}

void ssCatMain() {

	{
		string txt;
		vector<string> words;
		for (int i = 0; i < 15; i++) {
			txt.push_back('a');
			words.push_back("a");
		}
	
		printList(txt, words);
	}

	{
		string txt = "barfoothefoobarman";
		vector<string> words;
		words.push_back("bar");
		words.push_back("foo");
		printList(txt, words);
	}

	{
		string txt = "abcdabcdabcdabcdaaaaaabcdabcd";
		vector<string> words;
		words.push_back("a");
		words.push_back("b");
		words.push_back("c");
		words.push_back("");
		printList(txt, words);
	}

	{
		string txt = "";
		vector<string> words;
		words.push_back("");
		printList(txt, words);
	}
}