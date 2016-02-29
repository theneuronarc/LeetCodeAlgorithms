/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

#define min(a,b) (a < b ? a : b);

int minSubArrayLen(int s, int* nums, int numsSize) {
	unsigned int sum = 0;
	int start = 0, end = 0;
	sum = nums[0];
	int count = (sum >= s ? 1 : INT_MAX);
	for (int i = 1; i < numsSize; i++) {
		sum += nums[i];
		end++;
		while (sum >= s) {
			count = min(count, (end - start + 1));
			sum -= nums[start];
			start++;
		}
	}

	return count > numsSize ? 0 : count;
}