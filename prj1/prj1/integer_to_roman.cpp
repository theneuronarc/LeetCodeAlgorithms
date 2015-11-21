/*
https://leetcode.com/problems/integer-to-roman/
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "std_headers.h"

class Solution {
public:
	string intToRoman(int num) {
		char roman[4][2] = { {'I', 'V'}, {'X','L'}, {'C', 'D'}, {'M','M'} };
		string result;

		for (int i = 0; i < 4; i++) {
			int digit = num % 10;
			if (digit) {
				if (digit < 4) {
					while (digit--)
						result.push_back(roman[i][0]);
				}
				else if (digit == 4) {
					result.push_back(roman[i][1]);
					result.push_back(roman[i][0]);					
				}
				else if (digit == 5) {
					result.push_back(roman[i][1]);
				}
				else if (digit < 9) {
					digit -= 5;
					while (digit--)
						result.push_back(roman[i][0]);
					result.push_back(roman[i][1]);
				}
				else {
					result.push_back(roman[i + 1][0]);
					result.push_back(roman[i][0]);					
				}
			}
			
			num /= 10;
		}

		std::reverse(result.begin(), result.end());

		return result;

	}
};

void integerToRoman() {
	Solution obj;

	int x = 1676;
	cout << x << "  =>  " << obj.intToRoman(x) << endl;

	x = 3999;
	cout << x << "  =>  " << obj.intToRoman(x) << endl;

	x = 0;
	cout << x << "  =>  " << obj.intToRoman(x) << endl;

	x = 8;
	cout << x << "  =>  " << obj.intToRoman(x) << endl;

	x = 9;
	cout << x << "  =>  " << obj.intToRoman(x) << endl;
}