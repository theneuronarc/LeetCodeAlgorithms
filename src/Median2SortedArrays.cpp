/*
https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively.\
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

*/

#include "std_headers.h"

class MedianArrays {
	public:
		void merge(vector<int> &a, vector<int> &b, vector<int> &c) {
			int idxA = 0;
			int idxB = 0;
			int totalElements = a.size() + b.size();

			if (!totalElements)
				return;

			if (a.size() && b.size()) {
				(a.back() > b.back() ? b.push_back(a.back()) : a.push_back(b.back()));

				for (int i = 0; i < totalElements; i++) {
					c.push_back((a[idxA] < b[idxB] ? idxA++, a[idxA] : idxB++, b[idxB]));
				}
			}
			else {
				vector<int> &d = (a.size() ? a : b);
				for (int i = 0; i < d.size(); i++) {
					c.push_back(d[i]);
				}
			}
		}

		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			vector<int> mergedArr;
			int medianIdx;
			merge(nums1, nums2, mergedArr);
			medianIdx = (mergedArr.size() - 1) / 2
			return mergedArr[(mergedArr.size() - 1) / 2];
		}
};

int MedianArraysMain() {
	MedianArrays obj;
	vector<int> a;
	vector<int> b = { 1 };
	cout << obj.findMedianSortedArrays(a, b);
	return 0;
}