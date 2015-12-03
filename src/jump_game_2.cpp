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

		if (size <= 1)
			return 0;

		int maxJump = -1;
		int maxJumpIdx = -1;
		int lastIdx = 0;
		int lastIdxJump = nums[0];
		int curIdx = 1;
		int jumps = 1;

		while (curIdx < size) {

			if ((curIdx - lastIdx) > lastIdxJump) {
				jumps++;
				lastIdx = maxJumpIdx;
				lastIdxJump = nums[maxJumpIdx];
				maxJump = -1;
				maxJumpIdx = -1;
			}

			if (maxJump <= (nums[curIdx] + (curIdx - lastIdx))) {
				maxJump = (nums[curIdx] + (curIdx - lastIdx));
				maxJumpIdx = curIdx;
			}

			curIdx++;
		}

		return jumps;
	}
};



void jumpGameMain() {
	Solution obj;
	vector<int> vec = { 1,1,1,1 };
	obj.jump(vec);
}