/*
https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

#include "std_headers.h"
#define MAX 100

#define MAX 100

class ThreeSum {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > result;

		if (nums.empty())
			return result;

		int posNum[MAX] = { 0 };
		int posNumCount = 0;
		int posBinMap[MAX] = { 0 };

		int negNum[MAX] = { 0 };
		int negNumCount = 0;
		int negBinMap[MAX] = { 0 };

		int targetSum = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= 0) {
				if (!posBinMap[nums[i]])
					posNum[posNumCount++] = nums[i];
				posBinMap[nums[i]]++;
			}
			else {
				if (!negBinMap[-nums[i]])
					negNum[negNumCount++] = -nums[i];
				negBinMap[-nums[i]]++;
			}
		}

		if (!posNumCount)
			return result;

		if (!negNumCount && posBinMap[0] >= 3) {
			result.push_back(vector<int>({ 0,0,0 }));
			return result;
		}

		int temp;

		for (int i = 0; i < negNumCount; i++) {
			targetSum = negNum[i];
			for (int j = 0; j < posNumCount; j++)
			{
				if (posNum[j] >(targetSum / 2))
					continue;

				temp = targetSum - posNum[j];
				if (temp >= 0 && posBinMap[temp] >= (temp == posNum[j] ? 2 : 1)) {
					result.push_back({ -targetSum, posNum[j], temp });
				}
			}
		}

		for (int i = 0; i < posNumCount; i++) {

			targetSum = posNum[i];

			for (int j = 0; j < negNumCount; j++)
			{
				if (negNum[j] >(targetSum / 2))
					continue;

				temp = targetSum - negNum[j];
				if (temp > 0 && negBinMap[temp] >= (temp == negNum[j] ? 2 : 1)) {
					result.push_back({ -temp, -negNum[j], targetSum });
				}
			}

		}

		if (posBinMap[0] >= 3)
			result.push_back({ 0,0,0 });

		return result;
	}
};

void print(vector<vector<int>>& res) {
	for (int i = 0; i < res.size(); i++) {
		cout << "(" << res[i][0] << "," << res[i][1] << "," << res[i][2] << ")" << endl;
	}

	cout << endl;
}

void threeSumMain() {
	ThreeSum obj;
	vector<int> vec = {-1,0,1,2,-1,-4};
	vector<vector<int>>& res = obj.threeSum(vec);
	print(res);

	vec = { 0,0,0,2,4 };
	res = obj.threeSum(vec);
	print(res);

	vec = { -1,0,1};
	res = obj.threeSum(vec);
	print(res);

	vec = { -2,0,1,1,2 };
	res = obj.threeSum(vec);
	print(res);

	vec = { -2,0,0,2,2 };
	res = obj.threeSum(vec);
	print(res);
}