/*
https://leetcode.com/problems/largest-number/
*/

#include "std_headers.h"
#define swap(a,b) {tmp = a;a = b;b = tmp; }

void itos(int num, char** arr, int len) {
	char* str = *arr;
	str[--len] = '\0';
	(!num ? str[--len] = '0' : 0);
	while (num) {
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	*arr = str + len;
}

int comparison(char* strA, char* strB) {
	int lenA = strlen(strA);
	int lenB = strlen(strB);
	int i;
	int res;
	for (i = 0; i < lenA && i < lenB; i++) {
		if (strA[i] > strB[i]) {
			return 1;
		}
		else if (strA[i] < strB[i]) {
			return -1;
		}
		else {
			continue;
		}
	}

	if (i == lenA && i == lenB)
		return 0;

	if (i == lenA)
		return (res = comparison(strA, strB + i)) == 0 ? 1 : res;
	else
		return (res = comparison(strA + i, strB)) == 0 ? 1 : res;
}

void quickSort(char** arr, int start, int end) {
	char* pivot = arr[end];
	int lt = start, gt = start - 1;
	if (start >= end)
		return;
	char* tmp;
	for (int i = start; i < end; i++) {
		if (comparison(arr[i], pivot) < 0) {
			swap(arr[lt], arr[i]);
			lt++;
		}
	}

	swap(arr[lt], arr[end]);

	quickSort(arr, start, lt - 1);
	quickSort(arr, lt + 1, end);
}



char* largestNumber(int* nums, int numsSize) {
	char* data = (char*)malloc(numsSize * 64);
	char** arr = (char**)malloc(numsSize*sizeof(char*));
	char* str = (char*)malloc(numsSize * 64);
	str[0] = '\0';
	int allZero = 1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i])
			allZero = 0;
		arr[i] = (data + 64 * i);
		itos(nums[i], (arr + i), 64);
		//printf("\n%s", arr[i]);
	}

	quickSort(arr, 0, numsSize - 1);

	for (int i = numsSize - 1; i >= 0; i--) {
		//printf("\n%s", arr[i]);
		strcpy(str + strlen(str), arr[i]);
	}

	if (allZero)
		str[1] = '\0';

	return str;
}