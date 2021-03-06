/*
https://leetcode.com/problems/repeated-dna-sequences/
*/
#include "std_headers.h"
#define val(c) (c == 'A' ? 0 : (c == 'C' ? 1 : (c == 'G' ? 2 : (c == 'T' ? 3 : 0))))

char** findRepeatedDnaSequences(char* s, int* returnSize) {
	const int stringCount = (1 << 20 - 1);
	const int stringLen = 10;
	int len = strlen(s);
	char** res = (char**)malloc(len*sizeof(char*));
	int resIdx = 0;


	int* hashMap = (int*)calloc(stringCount,sizeof(int));
	int stringId = 0;
	
	for (int i = 0; i < stringLen; i++) {
		stringId *= 4;
		stringId += s[i];
	}

	hashMap[stringId] = stringLen;

	for (int i = stringLen; i < len; i++) {
		stringId <<= 2;
		stringId -= (val(s[i - stringLen]) * (1 << 20));
		stringId += val(s[i]);

		if (hashMap[stringId] > 0 && hashMap[stringId] <= i) {
			char* str = (char*)malloc((stringLen+1)*sizeof(char));
			for (int j = 0; j < stringLen; j++) {
				str[stringLen -j - 1] = s[i - j];
			}
			str[stringLen] = '\0';
			res[resIdx++] = str;
			hashMap[stringId] = len + 1;
		}
		else {
			hashMap[stringId] = i + 1;
		}
	}

	*returnSize = resIdx;
	return res;
}