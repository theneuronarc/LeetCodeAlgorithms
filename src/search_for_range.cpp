/*
https://leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include "std_headers.h"

class Solution {
public:

	int binarySearch(int arr[], int l, int r, int x, bool first)
	{
		int pos = -1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;

			if (arr[m] == x) {
				pos = m;
				if (first)
					r = m - 1;
				else
					l = m + 1;
			}
			else if (arr[m] < x) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		return pos;
	}

	vector<int> searchRange(vector<int>& nums, int target) {		
		vector<int> result;
		result.push_back(binarySearch(nums.data(), 0, nums.size() - 1, target, true));
		result.push_back(binarySearch(nums.data(), 0, nums.size() - 1, target, false));
		return result;
	}


};


void searchRangeMain() {
	Solution obj;
	vector<int> vec = { 5, 7, 7, 8, 8, 10 };
	printList(obj.searchRange(vec, 1));
}



