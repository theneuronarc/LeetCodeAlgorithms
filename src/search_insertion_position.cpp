/*
https://leetcode.com/problems/search-insert-position/
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ? 2
[1,3,5,6], 2 ? 1
[1,3,5,6], 7 ? 4
[1,3,5,6], 0 ? 0
*/

#include "std_headers.h"

class Solution {
public:
	int binarySearch(int arr[], int l, int r, int x)
	{
		while (l <= r)
		{
			int m = l + (r - l) / 2;

			if (arr[m] == x) {
				return  m;		
			}
			else if (arr[m] < x) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		return l;
	}

	int searchInsert(vector<int>& nums, int target) {
		return binarySearch(nums.data(), 0, nums.size()-1, target);
	}
};

