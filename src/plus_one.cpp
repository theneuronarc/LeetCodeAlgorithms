/*
https://leetcode.com/problems/plus-one/
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/

#include "std_headers.h"

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
		int idx = digits.size() - 1;
		int* data = digits.data();

		while (carry && idx >= 0) {
			carry = (data[idx] + 1) / 10;
			data[idx] = (data[idx] + 1) % 10;
			idx--;
		}

		if (carry) {			
			digits.push_back(0);
			data = digits.data();
			for (int i = digits.size() - 1; i > 0; i--) {
				data[i] = data[i - 1];
			}
			data[0] = 1;
		}

		return digits;
	}
};