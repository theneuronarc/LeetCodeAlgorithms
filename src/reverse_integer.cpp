/*
https://leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

*/

#include "std_headers.h"

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		long long result = 0;
		if (x < 0) {
			sign = -1;
			x *= -1;
		}

		do {
			result *= 10;
			result += (x % 10);
		} while (x /= 10);

		return sign*result;		
	}
};

void reverseInteger(){

	Solution obj;
	int x = 1534236469;
	cout << sizeof(long) << " " << sizeof(int) << endl;
	cout << x << " => " << obj.reverse(x) << endl;
	x = 0;
	cout << x << " => " << obj.reverse(x) << endl;
	x = 1;
	cout << x << " => " << obj.reverse(x) << endl;
	x = 12;
	cout << x << " => " << obj.reverse(x) << endl;
	x = -1234;
	cout << x << " => " << obj.reverse(x) << endl;
	x = 100000;
	cout << x << " => " << obj.reverse(x) << endl;
	x = -100000;
	cout << x << " => " << obj.reverse(x) << endl;

}