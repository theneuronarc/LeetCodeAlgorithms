/*
https://leetcode.com/problems/excel-sheet-column-title/
*/

#include "std_headers.h"

char* convertToTitle(int n) {
	char* res = (char*)malloc(sizeof(char) * 1024);
	int idx = 0;
	while (n) {
		res[idx++] = (n % 26) + 'A';
		n /= 26;
	}

	for (int i = 0; i < idx/2; i++) {
		char tmp = res[i];
		res[i] = res[idx - i - 1];
		res[idx - i - 1] = tmp;
	}

	return res;


}
