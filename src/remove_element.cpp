/*
https://leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include "std_headers.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums, int value) {
		int cur_pos = 0;
		int* data = nums.data();
		int size = nums.size();

		if (!size) {
			return 0;
		}

		for (int i = 0; i < size; i++) {
			if (value == data[i])
				continue;
			else {
				if (cur_pos != i) {
					data[cur_pos] = data[i];
				}
				cur_pos++;
			}
		}
		return (cur_pos + 1);
	}
};