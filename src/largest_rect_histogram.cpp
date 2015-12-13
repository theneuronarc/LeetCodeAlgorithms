/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

#include "std_headers.h"

class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int size = height.size();
		int* range = new int[size];
		int* data = height.data();
		std::stack<int> boundary;

		boundary.push(0);
		range[0] = 0;

		for (int i = 1; i < size; i++) {
			if (height[boundary.top()] < height[i])
				boundary.push(i);
			else {
				while (!boundary.empty() && height[boundary.top()] >= height[i]) {
					range[i] = boundary.top();
					boundary.pop();
				}
			}
		}

		boundary.;


		for (int i = 1; i < size; i++) {
			if (height[boundary.top()] < height[i])
				boundary.push(i);
			else {
				while (!boundary.empty() && height[boundary.top()] >= height[i]) {
					range[i] = boundary.top();
					boundary.pop();
				}
			}
		}

	}
};

