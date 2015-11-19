/*
https://leetcode.com/problems/string-to-integer-atoi/
*/

#include "std_headers.h"

int charToInt(char ch) {
	int digit = ch - '0';
	if (digit >= 0 && digit <= 9) {
		return digit;
	}
	else {
		return -1;
	}
}

int isOverflow(int result, int currentDigit) {
	if (result > INT_MAX / 10) {
		return 1;
	}

	if (result == INT_MAX / 10 && currentDigit > INT_MAX % 10) {
		return 1;
	}

	if (result < INT_MIN / 10) {
		return 1;
	}

	if (result == INT_MIN / 10 && currentDigit > (-1*(INT_MIN % 10))) {
		return 1;
	}	

	return 0;
}


int ignoreWhitespaces(const char* str) {
	for (int j = 0; j < strlen(str); j++) {		
		if (!isspace(str[j]))
			return j;
	}

	return 0;

}

int myAtoi(const char* str) {	
	int sign = 1;
	int result = 0;
	int i = 0;
	int invalid = 1;
	int len = strlen(str);

	i = ignoreWhitespaces(str);

	if (i >= len)
		return 0;

	if (str[i] == '-' && ++i)
		sign = -1;
	else if (str[i] == '+' && ++i)
		sign = 1;
	else if (isdigit(str[i]))
		sign = 1;
	else
		return 0;

	for ( ; i < len; i++) {
		if (!isdigit(str[i]))
			break;

		if (isOverflow(sign*result, charToInt(str[i]))) {
			return (sign >= 0) ? INT_MAX : INT_MIN;			
		}

		result *= 10;
		result += charToInt(str[i]);
	}

	return sign*result;
}

void myAtoiMain() {

	string s = "-2147483647";
	cout << s << " =>  " << myAtoi(s.c_str()) << " " << (INT_MIN % 10) << endl;

	 s = "     010";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	s = "hakd-123";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	
	s = "";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	s = "ABC";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	s = "1534236469";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	s = "999999999999999999999999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;

	s = "999ABC";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "9999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "999999999999999999999999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "999999999999999999999999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "999999999999999999999999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "999999999999999999999999";
	cout << s << " => " << myAtoi(s.c_str()) << endl;
	s = "-2147483649";
	cout << s << " => " << myAtoi(s.c_str()) <<  " " << -2147483649 << endl;
}