/*
*/

#include "std_headers.h"

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		// XOR (^) is both commutative and associative 
		// The numbers which appear twice will be cancelled
		// Only the number that appear singly time will survive 
		// Consider sequence of bits. there will be either one 0 or one 1 extra.
		// XORing all these bits will yield only extra bit
		// extend this to bitwise XOR
		int value = 0;
		int i, n;
		n = nums.size();
		for (i = 0; i<n; i++)
			value = value ^ nums[i];
		return value;
	}
};