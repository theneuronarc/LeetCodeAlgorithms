/*
https://leetcode.com/problems/text-justification/
*/

#include "std_headers.h"

class Solution {
public:
	int groupWords(vector<string>& words, int start, int maxWidth, string& str) {
		int padding = 0;
		int wordCount = 0;
		int slotSize = 0;
		int extraSpace = 0;

		int size = words.size();
		str = "";
		int i = start;
		if (start >= size)
			return -1;

		int charCount = -1;
		while (i < size) {
			charCount += 1;
			charCount += words[i].size();
			if (charCount > maxWidth) {
				charCount -= 1;
				charCount -= words[i].size();
				break;
			}
			i++;
		}

		wordCount = i - start;
		padding = maxWidth - charCount + wordCount - 1;
		if (i == size) {
			slotSize = (padding) ? 1 : 0;
			extraSpace = 0;
			if (padding > wordCount - 1) {
				wordCount++;
				words.push_back(string(padding - wordCount + 1, ' '));
				i++;
			}
		}
		else {
			slotSize = (wordCount <= 1) ? padding : padding / (wordCount - 1);
			extraSpace = (wordCount <= 1) ? 0 : padding % (wordCount - 1);
		}

		string paddingStr(slotSize, ' ');

		for (int j = start; j < i; j++) {
			str += words[j].data();
			if (j == i - 1 && wordCount > 1)
				continue;
			str += paddingStr.data();
			if (extraSpace) {
				str += " ";
				extraSpace--;
			}
		}

		return i;
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		bool terminate = false;
		string str;
		int start = 0;
		vector<string>  res;
		if (words.empty() || !maxWidth) {
			res.push_back("");
			return res;
		}

		while (!terminate) {
			start = groupWords(words, start, maxWidth, str);
			if (start == -1) {
				terminate = true;
				continue;
			}
			res.push_back(str);
		}
		return res;
	}
};

void textJustificationMain() {
	Solution obj;
	vector<string> vec({ "This", "is", "an", "example", "of", "text"});
	obj.fullJustify(vec, 7);
}