/*
https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

#include "std_headers.h"

typedef struct {
	int left;
	int right;
}walls;

class Solution {
public:
	int trap(vector<int>& height) {
		walls* maxWalls = new walls[height.size()];
		int maxLeft = 0;
		int maxRight = 0;
		int size = height.size();
		int cap = 0;

		for (int i = 0; i < size; i++) {
			maxWalls[i].left = maxLeft;
			maxLeft = max(maxLeft, height[i]);

			maxWalls[size - 1 - i].right = maxRight;
			maxRight = max(maxRight, height[size - 1 - i]);
		}

		for (int i = 0; i < size; i++) {
			int minHeight = min(maxWalls[i].left, maxWalls[i].right);
			cap += max(minHeight - height[i], 0);
		}

		return cap;
	}
};