/*
https://leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

#include "std_headers.h"

class Solution {
public:
	int lengthOfLastWord(string s) {
		int pos = -1;
		int len = 0;
		for (int i = s.size() - 1; i > 0 ; i--) {
			if (isspace(s[i])) {
				if (len)
					break;
				else
					continue;
			}

			len++;
		}

		return len;
	}
};

void lengthLastWordMain() {

}