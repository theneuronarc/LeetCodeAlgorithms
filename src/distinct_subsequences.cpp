/*
https://leetcode.com/problems/distinct-subsequences/
*/

#include "std_headers.h"

int numDistinct(char* s, char* t) {
	int* table = (int*)calloc(strlen(t), sizeof(int));
	int sSize = strlen(s);
	int tSize = strlen(t);
	int prev;

	for (int i = 0; i < sSize; i++) {
		prev = table[0];
		if (s[i] == t[0])
			table[0]++;
		for (int j = 1; j < tSize; j++) {
			if (s[i] == t[j]) {
				prev = prev + table[j];
				swap(prev, table[j]);
			}
			else {
				prev = table[j];
			}
		}
	}
	return table[tSize - 1];
}