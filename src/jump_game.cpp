/*
https://leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/


#include "std_headers.h"

class Solution {
public:
	bool canJump(vector<int>& nums) {
		bool findBridge = false;
		int crossIdx;
		for (int i = nums.size() - 2; i >= 0; i--) {			
			if (nums[i]) {
				if(!findBridge)
					continue;
				else {
					if ((crossIdx - i) < nums[i]) {
						findBridge = false;
					}
				}
			}
			else {
				if (!findBridge) {
					findBridge = true;
					crossIdx = i;
				}
			}		
		}

		if (findBridge)
			return false;
		else
			return true;
	}
};


void jumpGameMain() {
	Solution obj;
	{
		vector<int> vec = {2,0,1,0,1};
		printList(vec);
		cout << obj.canJump(vec) << endl;
	}

	{
		vector<int> vec = {2};
		printList(vec);
		cout << obj.canJump(vec) << endl;
	}
	{
		vector<int> vec = { 3,2,1,0,0 };
		printList(vec);
		cout << obj.canJump(vec) << endl;
	}

	{
		vector<int> vec = { 2,3,1,1,0 };
		printList(vec);
		cout << obj.canJump(vec) << endl;
	}


	{
		vector<int> vec = { 0,0,0 };
		printList(vec);
		cout << obj.canJump(vec) << endl;
	}
}