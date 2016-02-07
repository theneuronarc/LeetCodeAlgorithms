/*
https://leetcode.com/problems/find-peak-element/
*/

int findPeakElement(int* nums, int numsSize) {
	int begin = 0, end = numsSize - 1;
	int mid;
	int peakFound = 0;
	int left, right;

	while (begin <= end) {
		mid = begin + (end - begin) / 2;
		if (!mid)
			left = 0;
		else {
			left = (nums[mid - 1] > nums[mid] ? 1 : 0);
		}

		if (mid == numsSize - 1)
			right = 0;
		else {
			right = (nums[mid + 1] > nums[mid] ? 1 : 0);
		}

		if (!left && !right) {
			return mid;
		}
		else {
			if (left) {
				end = mid;
			}
			else {
				begin = mid;
			}
		}
	}
}