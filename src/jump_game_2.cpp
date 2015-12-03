/*
https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
#include "std_headers.h"

class Solution {
public:
	int jump(vector<int>& nums) {
		int size = nums.size();
		int farthestIdx = size - 1;
		int jumps = 0;

		while (farthestIdx) {
			int nextFarthestIdx = farthestIdx;
			for (int i = farthestIdx; i >= 0; i--) {
				if (((farthestIdx - i) <= nums[i]) && i < nextFarthestIdx) {
					nextFarthestIdx = i;
				}
			}

			farthestIdx = nextFarthestIdx;
			cout << farthestIdx << " ";
			jumps++;
		}

		return jumps;
	}
};

void jumpGame2Main() {

}