/*
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include "std_headers.h"

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		while (n) {
			if (m && (nums1[m - 1] > nums2[n - 1])) {
				nums1[m + n - 1] = nums1[m - 1];
				m--;
			}
			else {
				nums1[m + n - 1] = nums2[n - 1];
				n--;
			}
		}
	}
};