/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

#include "std_headers.h"

int findMin(int* nums, int numsSize) {
	int pivot = nums[0];
	int begin = 0, end = numsSize - 1, mid;

	while (end - begin > 1) {
		printf("\n%d %d", begin, end);
		mid = begin + (end - begin) / 2;

		if (nums[mid] < nums[end]) {
			end = mid;
		}
		else {
			begin = mid;
		}
	}

	return nums[begin] < nums[end] ? nums[begin] : nums[end];
}


int findMinDup(int* nums, int numsSize) {
	int pivot = nums[0];
	int begin = 0, end = numsSize - 1, mid;

	while (end - begin > 1) {
		//printf("\n%d %d", begin, end);
		mid = begin + (end - begin) / 2;

		if (nums[begin] == nums[end] && nums[begin] == nums[mid]) {
			begin++;
			continue;
		}
		if (nums[mid] <= nums[end]) {
			end = mid;
		}
		else {
			begin = mid;
		}
	}

	return nums[begin] < nums[end] ? nums[begin] : nums[end];
}

void minRotArr() {
	int nums[] = { 0,1,2,3,4,5,6,7,8 };
	findMin(nums, sizeof(nums) / sizeof(int));
}