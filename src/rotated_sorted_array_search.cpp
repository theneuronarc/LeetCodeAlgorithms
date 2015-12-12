/*
*/

#include "std_headers.h"

class Solution {
public:
	int searchRec(int* data, int startIdx, int endIdx, int target) {
		if (startIdx > endIdx)
			return -1;

		int pivot = data[startIdx];
		int midPoint = startIdx + (endIdx - startIdx) / 2;
		int midVal = data[midPoint];

		if (target == pivot)
			return startIdx;

		if (target == midVal)
			return midPoint;

		if (midVal > pivot) {
			if (target > pivot) {
				if (target < midVal)
					endIdx = midPoint - 1;
				else
					startIdx = midPoint + 1;
			}
			else if (target < pivot) {
				startIdx = midPoint + 1;
			}
			else {
				return true;
			}
		}
		else if (midVal < pivot) {
			if (target < pivot) {
				if (target < midVal)
					endIdx = midPoint - 1;
				else
					startIdx = midPoint + 1;
			}
			else if (target > pivot) {
				endIdx = midPoint - 1;
			}
			else {
				return true;
			}
		}
		else {
			if (data[startIdx] == data[endIdx]) {
				startIdx++;
				endIdx--;
			}
			else
				startIdx = midPoint + 1;
		}

		return searchRec(data, startIdx, endIdx, target);

	}

	int search(vector<int>& nums, int target) {
		return searchRec(nums.data(), 0, nums.size() - 1, target);
	}
};

class Solution {
public:
	
	int binarySearch1(int arr[], int l, int r, int x)
	{
		while (l <= r)
		{
			int m = l + (r - l) / 2;

			if (arr[m] == x) return m;  // Check if x is present at mid

			if (arr[m] < x) l = m + 1; // If x greater, ignore left half

			else r = m - 1; // If x is smaller, ignore right half
		}
		return -1; // if we reach here, then element was not present
	}

	int searchRec(int *arr, int startIdx, int endIdx, int pivot, int target) {
		int midPoint = startIdx + (endIdx - startIdx) / 2;

		if (target == arr[midPoint])
			return midPoint;
		else {
			if (startIdx >= endIdx)
				return -1;
		}

		if (arr[midPoint] >= pivot) {
			if (target >= pivot && target <= arr[midPoint])
				return binarySearch(arr, startIdx, midPoint, target);
			else
				return searchRec(arr, midPoint + 1, endIdx, arr[midPoint], target);
		}
		else {
			if (target < pivot && target >= arr[midPoint])
				return binarySearch(arr, midPoint, endIdx, target);
			else
				return searchRec(arr, startIdx, midPoint - 1, pivot, target);
		}
	}


	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		return searchRec(nums.data(), 0, nums.size() - 1, nums[0], target);
	}
};

void rotSortedArrMain() {
	Solution obj;
	{
		vector<int> vec = { 5,1,2,3,4 };
		cout << obj.search(vec, 4) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 5,1,3 };
		cout << obj.search(vec, 2) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 3,7,9,1,2 };
		cout << obj.search(vec, 0) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 4,5,6,7,0,1,2,3,4 };
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;
	{
		vector<int> vec = {};
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 0 };
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
		cout << obj.search(vec, 0) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 0,1 };
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
		cout << obj.search(vec, 0) << endl;
	}
	cout << endl;
	{
		vector<int> vec = { 1,1,1,1,1,1,1,1};
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;

	{
		vector<int> vec = { 1,1,2,3,4,5,6,7,8,9,1,1,1,1,1,1,1,1 };
		cout << obj.search(vec, 10) << endl;
		cout << obj.search(vec, 1) << endl;
		cout << obj.search(vec, 4) << endl;
		cout << obj.search(vec, 1) << endl;
	}
	cout << endl;

}