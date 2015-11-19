/*
https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.
*/

#include "std_headers.h"

class NiceNumberPalindrome {
public:

	bool check(int x, int &y) {
		if (x == 0) { return true; }
		if (check(x / 10, y)) {
			if (x % 10 == y % 10) {
				y = y / 10;
				return true;
			}
		}
		return false;
	}
	bool isPalindrome(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if (x<0) { return false; }
		return check(x, x);
	}
};

class NumberPalindrome {
public:

	int testPalindrome(int x, int depth, int maxDepth, bool equal, bool& status) {
		int y = 0;
		if(depth != maxDepth)
			y = testPalindrome(x / 10, depth + 1, maxDepth, equal, status);
		else {
			int fh = 0, sh = 0;
			if (equal) {
				fh = x % 10;
				y = x/10;
				sh = y % 10;
				y = y / 10;

				if (fh == sh)
					status = true;
				else
					status = false;
			}
			else {
				status = true;
				y = x / 10;
			}

			return y;
		}

		if (!status)
			return y/10;

		if (x % 10 == y % 10)
			status = true;
		else
			status = false;

		return y / 10;

	}

	bool isPalindrome(int x) {
		int tmp = x;
		int numDigits = 0;
		bool status;

		if (x < 0)
			return false;

		if (!x)
			return true;

		while (tmp) {
			tmp /= 10;
			numDigits++;
		}

		int midPoint = ((numDigits+1) >> 1);

		testPalindrome(x, 1, midPoint, !(numDigits % 2) , status);

		return status;
	}
};

void numberPalindromeTest() {	
	NumberPalindrome obj;

	int x = 1;
	cout << x << " " << obj.isPalindrome(x) << endl;

	int x = 12344321;
	cout << x << " " << obj.isPalindrome(x) << endl;

	x = 123454321;
	cout << x << " " << obj.isPalindrome(x) << endl;

	x = 1;
	cout << x << " " << obj.isPalindrome(x) << endl;

	x = INT_MIN;
	cout << x << " " << obj.isPalindrome(x) << endl;

	x = INT_MAX;
	cout << x << " " << obj.isPalindrome(x) << endl;
}