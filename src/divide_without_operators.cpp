/*
https://leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

http://stackoverflow.com/questions/5386377/division-without-using
http://www.exploringbinary.com/binary-division/
*/

#include "std_headers.h"

unsigned divide(unsigned dividend, unsigned divisor) {

	unsigned denom = divisor;
	unsigned current = 1;
	unsigned answer = 0;

	if (denom > dividend)
		return 0;

	if (denom == dividend)
		return 1;

	while (denom <= dividend) {
		denom <<= 1;
		current <<= 1;
	}

	denom >>= 1;
	current >>= 1;

	while (current != 0) {
		if (dividend >= denom) {
			dividend -= denom;
			answer |= current;
		}
		current >>= 1;
		denom >>= 1;
	}
	return answer;
}

class Solution1 {
public:
	unsigned int ceilLogBase2(unsigned int n) {
		unsigned int res = 0;
		while (n) {
			res++;
			n >>= 1;
		}

		return res;
	}

	unsigned int multiply(unsigned int m, unsigned int n) {
		unsigned int shift = 0;
		unsigned int res = 0;
		while (n) {
			res += (n & 0x1 ? (m << shift) : 0);
			n >>= 1;
			shift++;
		}

		return res;
	}

	unsigned int quotient(unsigned int m, unsigned int pow) {
		return (m >> pow);
	}

	unsigned int divideRecurse(unsigned int dividend, unsigned int divisor) {
		if (dividend < divisor)
			return 0;

		if (divisor >(1 << 30))
			return 1;

		unsigned int lgDivisor = ceilLogBase2(divisor);

		if (dividend < (1 << lgDivisor))
			return 1;

		unsigned int q1 = quotient(dividend, lgDivisor);
		unsigned int mult = multiply(q1, divisor);
		unsigned int q2 = divideRecurse(dividend - mult, divisor);

		return q1 + q2;
	}

	int divide(int dividend, int divisor) {
		unsigned int res = 0;
		int sign = false;
		unsigned int m, n;

		if (!divisor)
			return INT_MAX;

		if (dividend < 0) {
			sign = !sign;
			m = 0 - dividend;
		}
		else
			m = dividend;

		if (divisor < 0) {
			sign = !sign;
			n = 0 - divisor;
		}
		else
			n = divisor;

		res = divideRecurse(m, n);


		if (sign) {
			if (res > INT_MAX + 1)
				res = INT_MAX + 1;
			return (0 - res);
		}
		else {
			if (res > INT_MAX)
				res = INT_MAX;
			return res;
		}

	}
};

class Solution {
public:
	unsigned int ceilLogBase2(unsigned int n) {
		unsigned int res = 0;
		while (n) {
			res++;
			n >>= 1;
		}

		return res;
	}

	unsigned int multiply(unsigned int m, unsigned int n) {
		unsigned int shift = 0;
		unsigned int res = 0;
		while (n) {
			res += (n & 0x1 ? (m << shift) : 0);
			n >>= 1;
			shift++;
		}

		return res;
	}

	unsigned int divideRecurse(unsigned int dividend, unsigned int divisor) {
		unsigned int q1 = 0, mult = 0, q2 = 0;
		unsigned int res = 0;
		unsigned int lgDivisor = ceilLogBase2(divisor);

		while (true) {
			if (dividend < divisor)
				return res;

			if (dividend == divisor)
				return ++res;

			if (divisor > (1 << 30))
				return ++res;
			
			if (dividend < (1 << lgDivisor))
				return ++res;

			q1 = (dividend >> lgDivisor);
			res += q1;
			mult = multiply(q1, divisor);
			dividend -= mult;
		}

		return res;
	}

	int divide(int dividend, int divisor) {
		unsigned int res = 0;
		int sign = false;
		unsigned int m, n;

		if (!divisor)
			return INT_MAX;

		if (dividend < 0) {
			sign = !sign;
			m = 0 - dividend;
		}
		else
			m = dividend;

		if (divisor < 0) {
			sign = !sign;
			n = 0 - divisor;
		}
		else
			n = divisor;

		res = divideRecurse(m, n);


		if (sign) {
			if (res > INT_MAX + 1)
				res = INT_MAX + 1;
			return (0 - res);
		}
		else {
			if (res > INT_MAX)
				res = INT_MAX;
			return res;
		}

	}
};


void divideMain() {
	Solution obj;
	int dividend, divisor;

	dividend = -2147483648;
	divisor = -2147483648;

	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = -1010369383;
	divisor = -2147483648;

	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend= 100;
	divisor = 3;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 0;
	divisor = 3;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 100;
	divisor = 0;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 100;
	divisor = 25;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 256;
	divisor = 16;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = -1654;
	divisor = -17;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 1;
	divisor = 1;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

	dividend = 1;
	divisor = 3;
	cout << "(" << dividend << "/" << divisor << ")" << " => " << obj.divide(dividend, divisor) << endl;

}