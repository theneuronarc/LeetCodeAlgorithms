/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/


#include "std_headers.h"

class Solution {
public:
	int removeDuplicates(vector<int>& num) {
		if (num.empty())
			return 0;

		int start = 0;
		int end = 1;
		int freq = 2;
		int size = num.size();
		int* nums = const_cast<int*>(num.data());
		while (end < size) {
			if (nums[start] != nums[end]) {
				start++;
				if (start < end) {
					nums[start] = nums[end];
				}

				freq = 2;
			}
			else {
				freq--;
				if (freq > 0) {
					start++;
					if (start < end) {
						nums[start] = nums[end];
					}
				}
			}
			end++;
		}

		return (start + 1);
	}
};


void remDupMain() {
}