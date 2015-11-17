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
				//(a.back() > b.back() ? b.push_back(a.back()) : a.push_back(b.back()));

				for (int i = 0; (idxA < a.size() && idxB < b.size()); i++) {
					c.push_back((a[idxA] < b[idxB] ? a[idxA++] : b[idxB++]));
				}

				if (idxA < a.size()) {
					for (int i = idxA; i < a.size(); i++) {
						c.push_back(a[i]);
					}
				}

				if (idxB < b.size()) {
					for (int i = idxB; i < b.size(); i++) {
						c.push_back(b[i]);
					}
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
			int medianIdx1, medianIdx2;
			merge(nums1, nums2, mergedArr);
			medianIdx1 = (mergedArr.size() - 1) / 2;
			medianIdx2 = (mergedArr.size()) / 2;
			return (mergedArr[medianIdx1] + mergedArr[medianIdx2])/2.0;
		}
};

int MedianArraysMain() {
	MedianArrays obj;
	vector<int> a = { 1 };
	vector<int> b = { 1 };
	cout << obj.findMedianSortedArrays(a, b);
	return 0;
}