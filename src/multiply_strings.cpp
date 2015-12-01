/*
https://leetcode.com/problems/multiply-strings/

Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
*/

#include "std_headers.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define strrev(str) std::reverse(str, str + strlen(str));

static int charToInt(char a) {
	return (a - 48);
}

static char intToChar(int a) {
	return (a + 48);
}

static void multiply(char* upper, int digit, char* result) {
	int carry = 0;
	int i = 0;

	if (digit == 0) {
		result[0] = '0';
		result[0] = '\0';
		return;
	}


	for (i = 0; i < strlen(upper); i++) {
		int a = charToInt(upper[i]);
		int product = a*digit + carry;
		result[i] = intToChar(product % 10);
		carry = product / 10;
	}
	if (carry) {
		result[i] = intToChar(carry);
		result[i + 1] = '\0';
	}
	else
		result[i] = '\0';


	strrev(result);
	printf("\nMultiply of %s and %d is %s", upper, digit, result);
}

void sumStrings(char* n1, char* n2, char* rs) {
	int c1, c2;

	int i, j, m, cmax, sum;
	printf("\nSumStrings : %s, %s, %s", n1, n2, rs);

	c1 = strlen(n1);
	c2 = strlen(n2);

	strrev(n1);
	strrev(n2);

	cmax = c1;
	if (c1<c2) {
		cmax = c2;
	}

	m = 0;
	for (i = 0; i< cmax; i++) {
		if (c1 == c2 || (i < c1 && i < c2)) {
			sum = m + charToInt(n1[i]) + charToInt(n2[i]);
		}
		else if (i >= c1) {
			sum = m + charToInt(n2[i]);
		}
		else if (i >= c2) {
			sum = m + charToInt(n1[i]);
		}
		rs[i] = intToChar(sum % 10);
		m = sum / 10;
	}

	if (m) {
		rs[i] = intToChar(m);
		i++;
	}
	rs[i] = '\0';
	strrev(rs);
	printf("\nResult = %s", rs);
	strrev(n2);
}


void add(char* acc, char* num, int factor) {
	char* tmpAcc = (char*)malloc(strlen(acc) + 1);
	strcpy(tmpAcc, acc);

	int prevLength = strlen(num);
	char* p = (num + prevLength);
	for (int i = 0; i < factor; i++) {
		*p = '0';
		p++;
	}
	*p = '\0';
	acc[0] = '\0';

	sumStrings(tmpAcc, num, acc);
	num[prevLength] = '\0';
	free(tmpAcc);
}

string multiplyMain(string num1, string num2) {	
	char* a = new char[num1.size()+1];
	strcpy(a, num1.data());

	char* b = new char[num2.size() + 1];
	strcpy(b, num2.data());

	int size = num1.size() + num2.size() + 1;
	
	char* c = new char[size];
	c[0] = '0';
	c[1] = '\0';

	char* map = new char[10 * size];

	bool fetch[10] = { false };

	char *upper, *lower;
	
	strrev(a);
	strrev(b);

	if (strlen(a) > strlen(b)) {
		upper = a;
		lower = b;
	}
	else {
		upper = b;
		lower = a;
	}

	for (int i = 0; i < strlen(lower); i++) {
		int lowerDigit = charToInt(lower[i]);

		if (!fetch[lowerDigit]) {
			multiply(upper, lowerDigit, (map + lowerDigit*size));
			fetch[lowerDigit] = true;
		}
		printf("\nSum of %s and %s is", c, (map +lowerDigit*size));
		add(c, (map + lowerDigit*size), i);
		printf(" %s",  c);
	}

	delete[] a;
	delete[] b;
	delete[] map;

	return string(c);
}

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.empty() || num2.empty())
			return "";		

		return multiplyMain(num1, num2);
	}
};

void multiplyStringsMain() {
	string num1 = "0";
	string num2 = "9";
	Solution obj;
	obj.multiply(num1, num2);
}

