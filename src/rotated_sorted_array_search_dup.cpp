/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
https://leetcode.com/problems/search-in-rotated-sorted-array/

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.


*/

#include "std_headers.h"

class Solution {
public:
	int searchRec(int* data, int startIdx, int endIdx, int target) {
		if (startIdx > endIdx)
			return -1;

		int pivot = data[startIdx];
		int midPoint = startIdx + (endIdx - startIdx) / 2;
		int midVal = data[midPoint];

		if (target == pivot)
			return startIdx;

		if (target == midVal)
			return midPoint;

		if (midVal > pivot) {
			if (target > pivot) {
				if (target < midVal)
					endIdx = midPoint - 1;
				else
					startIdx = midPoint + 1;
			}
			else if (target < pivot) {
				startIdx = midPoint + 1;
			}
			else {
				return true;
			}
		}
		else if (midVal < pivot) {
			if (target < pivot) {
				if (target < midVal)
					endIdx = midPoint - 1;
				else
					startIdx = midPoint + 1;
			}
			else if (target > pivot) {
				endIdx = midPoint - 1;
			}
			else {
				return true;
			}
		}
		else {
			if (data[startIdx] == data[endIdx]) {
				startIdx++;
				endIdx--;
			}
			else
				startIdx = midPoint + 1;
		}

		return searchRec(data, startIdx, endIdx, target);

	}

	bool search(vector<int>& nums, int target) {
		if (searchRec(nums.data(), 0, nums.size() - 1, target) == -1)
			return false;
		else
			return true;
	}
};