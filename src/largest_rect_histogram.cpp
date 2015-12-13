/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

#include "std_headers.h"

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int size = height.size();
		int* leftRange = new int[size];
		int* rightRange = new int[size];
		int tmpIdx = 0;

		leftRange[0] = 0;
		rightRange[size - 1] = size - 1;

		for (int i = 1; i < size; i++) {
			if (height[i] <= height[i - 1]) {
				leftRange[i] = leftRange[i - 1];
				tmpIdx = leftRange[i - 1];
				while (tmpIdx >= 0 ) {
					if (height[i] <= height[tmpIdx]) {
						leftRange[i] = tmpIdx;
					}
					else
						break;
					tmpIdx--;
				}
			}
			else{
				leftRange[i] = i;
			}
		}

		for (int i = size - 2; i >= 0; i--) {
			if (height[i] > height[i + 1]) {
				rightRange[i] = i;
			}
			else {
				tmpIdx = rightRange[i + 1];
				rightRange[i] = rightRange[i + 1];
				while (tmpIdx < size) {
					if (height[i] <= height[tmpIdx]) {
						rightRange[i] = tmpIdx;
					}
					else
						break;
					tmpIdx++;
				}
			}
		}

		int maxArea = 0;
		for (int i = 0; i < size; i++) {
			maxArea = max(maxArea, height[i] * (rightRange[i] - leftRange[i] + 1));
		}

		return maxArea;
	}
};

