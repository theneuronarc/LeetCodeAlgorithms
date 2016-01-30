/*
https://leetcode.com/problems/reverse-words-in-a-string/
*/

#include "std_headers.h"

void removeExtraSpaces(char* s) {
	int start = 0, current = 0;
	int size = strlen(s);

	while (s[current] == ' ')
		current++;

	while (current < size) {
		if (s[current] == ' ') {
			current++;
			continue;
		}

		s[start] = s[current];
		start++;
		current++;

		if (current < size && s[current] == ' ') {
			s[start] = s[current];
			start++;
			current++;
		}
	}

	if (s[start - 1] == ' ')
		s[start - 1] = '\0';
	else
		s[start] = '\0';
}

void reverseString(char* s, int front, int back) {
	while (front < back) {
		swap(s[front], s[back]);
		front++;
		back--;
	}
}

void reverseWords(char *s) {	
	int size;
	int start = 0, current = 0;
	removeExtraSpaces(s);
	size = strlen(s);
	reverseString(s, 0, size - 1);

	while (current <= size) {
		if (current < size && s[current] != ' ') {
			current++;
			continue;
		}

		reverseString(s, start, current - 1);
		current++;
		start = current;
	}
}

void revWordsMain() {
	char s[1024] = "";
	reverseWords(s);
}