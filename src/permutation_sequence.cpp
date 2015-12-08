/*
https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include "std_headers.h"

class Solution {
public:
	string getPermutation(int n, int k) {
		int fct[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
		char data[] = "123456789";
		k--;
		string res;
		int nextIdx;
		for (int i = n-1; i >= 0; i--) {
			nextIdx = k / fct[i];
			res.push_back(data[nextIdx]);
			data[nextIdx] = '\0';
			strcat(data, data + nextIdx + 1);
			k = k%fct[i];		
		}

		return res;
	}
};

void permSeqMain() {
	Solution obj;
	cout << obj.getPermutation(7, 519);
}