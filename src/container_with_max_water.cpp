/*
https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include "std_headers.h"
#ifdef NOT_WORKING
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxCap = min(height[1], height[0]);
		int start = 0, end = 1;

		for (int i = 2; i < height.size(); i++) {
			int new_area, new_start;
			int area_start = min(height[i], height[start])*(i - start);
			int area_end = min(height[i], height[end])*(i - end);
			
			if (maxCap > area_start && maxCap > area_end) {
				;
			}
			else {
				int mid = start;
				new_area = 0;
				end = i;

				if (min(height[mid], height[i]) * (i - mid) >= new_area) {
					new_area = min(height[mid], height[i]) * (i - mid);
					start = mid;
					maxCap = new_area;
				}
				mid++;
			}		
		}

		return maxCap;
	}
};
#endif

class Solution {
public:
	int maxArea(vector<int>& height) {
		int start = 0, end = height.size();
		int maxArea = 0;
		while (start < end) {

		}
		return 0;
	}
};
void maxAreaMain() {
	vector<int> vec = { 2,3,10,5,7,8,9 };
	Solution obj;
	cout << obj.maxArea(vec) << endl;;
}