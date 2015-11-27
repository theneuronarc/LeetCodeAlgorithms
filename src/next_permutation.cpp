/*
https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ? 1,3,2
3,2,1 ? 1,2,3
1,1,5 ? 1,5,1
*/

#include "std_headers.h"

class Solution {
public:

	int find(int* data, int count) {
		int pivot = data[0];
		int nextIdx = 0;
		int min = 0;
		for (int i = 1; i < count; i++) {
			if (data[i] <= pivot)
				continue;
			else {
				if (data[i] < min) {
					nextIdx = i;
				}

				if (!min) {
					min = data[i];
					nextIdx = i;
				}
			}
		}

		return nextIdx;
	}

	bool nextPerRecursive(int* data, int startIdx, int count) {
		int nextIdx;
		if (count == 1)
			return false;

		if (nextPerRecursive(data, startIdx + 1, count - 1))
			return true;
		else {
			nextIdx = find(data + startIdx, count) + startIdx;
			if (data[nextIdx] == data[startIdx])
				return false;
			else {
				int tmp = data[startIdx];
				data[startIdx] = data[nextIdx];
				data[nextIdx] = tmp;
				std::sort(data + startIdx + 1, data + startIdx + 1 + count - 1, std::less<int>());
				return true;
			}
		}

	}

	void nextPermutation(vector<int>& nums) {
		if (nextPerRecursive(nums.data(), 0, nums.size()))
			return;
		else {
			std::sort(nums.begin(), nums.end(), std::less<int>());
			return;
		}
	}
};

void nextPerMain() {
	Solution obj;
	vector<int> nums = { 1,1,5 };
	obj.nextPermutation(nums);
	printList(nums);
}

