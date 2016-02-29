/*
https://leetcode.com/problems/house-robber/
*/
#define max(a,b) (a < b ? b : a)
int rob(int* nums, int numsSize) {
	int max = 0;
	int prevMax[2] = { 0 };

	for (int i = 0; i < numsSize; i++) {
		int inc, notinc;
		inc = prevMax[0] + nums[i];
		notinc = max(prevMax[0],prevMax[1]);
		prevMax[1] = inc;
		prevMax[0] = notinc;
	}

	return max(prevMax[0], prevMax[1]);
}