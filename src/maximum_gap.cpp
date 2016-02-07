/*
https://leetcode.com/problems/maximum-gap/
*/

#define max(a,b) ((a)>(b)?(a):(b))
#define printf(...)

#include <stdio.h>
void countSort(int** a, int** b, int n, int mask) {
	int C[2] = { 0 };
	int* A = *a, *B = *b;

	int* tmp;

	for (int i = 0; i < n; i++) {
		C[A[i] & mask ? 1 : 0]++;
	}

	C[1] += C[0];

	if (!C[1] || !C[0]) {
		tmp = *a; *a = *b; *b = tmp;
		return;
	}

	for (int i = n - 1; i >= 0; i--) {
		printf("\nCS:: %d", C[A[i] & mask ? 1 : 0]);
		B[C[A[i] & mask ? 1 : 0] - 1] = A[i];
		C[A[i] & mask ? 1 : 0]--;
	}
}

void radixSort(int* A, int n, int d) {
	int* B = (int*)malloc(sizeof(int)*n);
	int* tmp;
	for (int i = 0; i < d; i++) {
		int mask = 1 << i;
		printf("\nRS :: %d %x", i, mask);
		countSort(&A, &B, n, mask);
		tmp = A; A = B; B = tmp;
	}

	tmp = A; A = B; B = tmp;
	printf("\nDone");
}

int maximumGap(int* nums, int numsSize) {
	int maxGap;
	if (numsSize < 2) {
		return 0;
	}

	radixSort(nums, numsSize, 32);
	maxGap = nums[1] - nums[0];
	for (int i = 2; i < numsSize; i++) {
		printf("%d ", nums[i]);
		maxGap = max(maxGap, (nums[i] - nums[i - 1]));
	}
	printf("\nDone");
	return maxGap;
}