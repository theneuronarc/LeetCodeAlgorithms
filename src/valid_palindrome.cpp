/*
https://leetcode.com/problems/valid-palindrome/
*/


#include "std_headers.h"

bool isPalindrome(char* s) {
	int forward = 0;
	int backward = strlen(s);
	while (forward < backward) {
		if (!isalnum(s[forward])) {
			forward++;
			continue;
		}

		if (!isalnum(s[backward])) {
			backward--;
			continue;
		}

		//printf("\n%c %c", s[forward], s[backward]);
		if (tolower(s[forward]) == tolower(s[backward])) {
			forward++;
			backward--;
		}
		else {
			return false;
		}
	}
	return true;
}