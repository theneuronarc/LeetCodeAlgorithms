/*
https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [?2,1,?3,4,?1,2,1,?5,4],
the contiguous subarray [4,?1,2,1] has the largest sum = 6.
*/

#include "std_headers.h"

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sumMax;
		int sumPostMax;
		int sumIncMax;
		int curMax;

		if (nums.empty())
			return INT_MIN;

		sumMax = sumIncMax = sumPostMax = nums[0];		

		for (int i = 1; i < nums.size(); i++) {			
			sumPostMax = max((sumPostMax + nums[i]), nums[i]);
			sumIncMax += nums[i];

			if (sumPostMax > sumIncMax) 
				curMax = sumPostMax;			
			else
				curMax = sumIncMax;

			if (curMax > sumMax) {
				sumMax = curMax;
				sumIncMax = sumMax;
				sumPostMax = 0;
			}
		}

		return sumMax;

	}
};

void maxSubarrayMain() {
	Solution obj;

	{
		vector<int> vec = { 0,0,0,0,-1,0,0,0,0 };
		printList(vec);
		cout << obj.maxSubArray(vec) << endl;
	}
	{
		vector<int> vec = { 1 };
		printList(vec);
		cout << obj.maxSubArray(vec) << endl;
	}
	{
		vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		printList(vec);
		cout << obj.maxSubArray(vec) << endl;
	}
	{
		vector<int> vec = { -2, -1 };
		printList(vec);
		cout << obj.maxSubArray(vec) << endl;
	}
}