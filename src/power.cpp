/*
https://leetcode.com/problems/powx-n/

Implement pow(x, n).
*/

#include "std_headers.h"

class Power {
public:
	double* table;
	bool* tableMap;

	double myPowRecurse(double x, int n) {
		double result = 1.0;
		if (tableMap[n]) {
			return table[n];
		}

		result = myPowRecurse(x, n / 2);
		table[n] = result * result;
		if (n % 2) {
			table[n] *= x;
		}
		tableMap[n] = true;
		
		return table[n];
	}
 
	double myPow(double x, int n) {
		bool sign = (n < 0);
		double result;

		n = abs(n);

		if (x == 0.0 || x == 1.0)
			return x;
		
		table = new double[n+1]();
		tableMap = new bool[n+1]();
		table[0] = 1.0;
		table[1] = x;
		tableMap[0] = tableMap[1] = true;
		result =  myPowRecurse(x, n);
		if (sign)
			return (1 / result);
		else
			return result;
	}
};


class Solution {
public:
	double myPow(double x, int n) {
		bool sign = (n < 0);
		double result;

		n = abs(n);

		if (x == 0.0 || x == 1.0)
			return x;



		if (sign)
			return (1 / result);
		else
			return result;
	}
};


void powerMain() {
	Power obj;
	cout << obj.myPow(0.00001, 2147483647);
}