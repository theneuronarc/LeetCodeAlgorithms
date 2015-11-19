/*
https://leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.
*/

#include "std_headers.h"

class Solution {
public:

	int testPalindrome(int x, int depth, int maxDepth, bool& status) {
		int y = 0;
		if(depth != maxDepth)
			y = testPalindrome(x / 10, ++depth, maxDepth, status);
		else {
			int fh = 0, sh = 0;
			if (maxDepth % 2) {
				fh = x % 10;
				y = x/10;
				sh = y % 10;

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

		while (tmp) {
			tmp /= 10;
			numDigits++;
		}

		int midPoint = (numDigits >> 1);

		testPalindrome(x, 1, midPoint, status);

		return status;
	}
};

void numberPalindromeTest() {
	int x = 12344321;
	Solution obj;
	cout << x << " " << obj.isPalindrome(x) << endl;
}