/*
https://leetcode.com/problems/fraction-to-recurring-decimal/
*/

#include "std_headers.h"

#include <map>

char* fractionToDecimalC(int numerator, int denominator) {
	int decPlaces = 0;
	int sign = (numerator * denominator) > 0 ? 0 : 1;
	numerator = (numerator > 0) ? numerator : -numerator;
	denominator = (denominator > 0) ? denominator : -denominator;
	char* res = (char*)malloc(sizeof(char) * 1024);
	char* tmp = (char*)malloc(sizeof(char) * 1024);

	//int* rem = (int*)malloc(sizeof(int)*denominator);
	std::map<int, int> rem;
	/*
	for (int i = 0; i < denominator; i++) {
		rem[i] = -1;
	}
	*/
	while (numerator%denominator && rem[numerator%denominator] == 0) {
		decPlaces++;
		rem[numerator%denominator] = decPlaces;
		numerator *= 10;
	}

	int q = numerator / denominator;
	int r = numerator % denominator;
	int len = 0;
	int idx = 0;
	while (q) {
		tmp[len] = q % 10 + '0';
		q /= 10;
		len++;
	}
	if (sign) {
		res[idx++] = '-';
	}
	if (decPlaces) {
		if (decPlaces == len) {
			res[idx++] = '0';
			res[idx++] = '.';
		}
		else {
			while (len > decPlaces) {
				res[idx++] = tmp[--len];
			}
			res[idx++] = '.';
		}
		while (len > 0) {
			if (r && decPlaces - len == rem[r] - 1) {
				res[idx++] = '(';
			}
			res[idx++] = tmp[--len];
		}

		if (r) {
			res[idx++] = ')';
		}
	}
	else {
		if (len == 0) {
			res[idx++] = '0';
		}

		while (len > 0) {
			res[idx++] = tmp[--len];
		}
	}

	res[idx] = '\0';
	return res;
}

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		cout << fractionToDecimalC(numerator, denominator);
		return "";
	}
};

void recDecimal() {
	Solution obj;
	obj.fractionToDecimal(1, 214748364);
}