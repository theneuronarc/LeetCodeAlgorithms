/*
https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include "std_headers.h"

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty() && b.empty())
			return "0";

		string& large = (a.size() > b.size() ? a : b);
		string& small = (a.size() > b.size() ? b : a);

		int idxSmall = small.size() - 1;
		int idxLarge = large.size() - 1;

		char carry = '0';

		while (idxSmall >= 0) {
			if (large[idxLarge] == '0') {
				large[idxLarge] = carry;
				carry = '0';
			}
			else if (carry == '0')
				;
			else
				large[idxLarge] = '0';

			if (small[idxSmall] == '0')
				;
			else if (large[idxLarge] == '0')
				large[idxLarge] = small[idxSmall];
			else {
				large[idxLarge] = '0';
				carry = '1';
			}

			idxLarge--;
			idxSmall--;
		}

		while (idxLarge >= 0) {
			if (large[idxLarge] == '0') {
				large[idxLarge] = carry;
				carry = '0';
			}
			else if (carry == '0')
				;
			else
				large[idxLarge] = '0';

			idxLarge--;
		}

		if (carry == '1') {
			large = carry + large;
		}

		return large;

	}
};