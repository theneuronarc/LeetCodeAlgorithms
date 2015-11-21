/*
https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include "std_headers.h"



class RomanToInt {
public:
#define r2i(ch, val) {  \
		switch (ch) {   \
		case 'I':   \
			val = 1;   \
			break;   \
		case 'V':   \
			val = 5;   \
			break;   \
		case 'X':   \
			val = 10;   \
			break;   \
		case 'L':   \
			val = 50;   \
			break;   \
		case 'C':   \
			val = 100;   \
			break;   \
		case 'D':   \
			val = 500;   \
			break;   \
		case 'M':   \
			val = 1000;   \
			break;   \
		default:   \
			val = 0;   \
			break;   \
		}   \
	} 

	int romanToInt(string s) {
		int size = s.size();
		int result = 0;
		int first, second;

		for (int i = 0; i < size; i++) {
			r2i(s[i], first);
			r2i(s[i + 1], second);
			if (first < second) {
				result -= first;
				result += second;
				i++;
			}
			else {
				result += first;
			}
		}

		return result;
	}
};

void roman2Int() {
	string s;
	RomanToInt obj;

	s = "MDCLXXVI";
	cout << s << " => " << obj.romanToInt(s) << endl;
}