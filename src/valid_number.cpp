/*
https://leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
*/

#include "std_headers.h"
typedef enum {
	INIT,
	SPACE_BEGIN,
	INT_SIGN,
	INT_PART,
	DEC_POINT,
	FRAC_PART,
	EXP_POINT,
	EXP_SIGN,
	EXP_MAG,
	SPACE_TERM,
	TERM
}states;

class Solution {
public:
	bool isNumber(string str) {
		states state = SPACE_BEGIN;
		states valid_state = INIT;
		const char* s = str.data();
		int next = 0;
		bool valid = true;	
		int size = str.size();
		while (state!=TERM) {
			switch (state) {
			case SPACE_BEGIN:
				if (s[next] == ' ') {
					next++;
					valid_state = SPACE_BEGIN;
				}
				else
					state = INT_SIGN;
				break;
			case INT_SIGN:
				if (s[next] == '+' || s[next] == '-') {
					next++;
					valid_state = INT_SIGN;
				}
				state = INT_PART;
				break;
			case INT_PART:
				if (isdigit(s[next])) {
					next++;
					valid_state = INT_PART;
				}
				else
					state = DEC_POINT;
				break;
			case DEC_POINT:
				if (s[next] == '.') {
					if(valid_state != INT_PART)
						valid_state = DEC_POINT;
					next++;
				}
				state = FRAC_PART;
				break;
			case FRAC_PART:
				if (isdigit(s[next])) {
					next++;
					valid_state = FRAC_PART;
				}
				else
					state = EXP_POINT;
				break;
			case EXP_POINT:
				if (valid_state != INT_PART && valid_state != FRAC_PART) {
					valid = false;
					state = TERM;
					break;
				}

				if (s[next] == 'e' || s[next] == 'E') {
					next++;
					valid_state = EXP_POINT;
				}
				state = EXP_SIGN;
				break;
			case EXP_SIGN:				
				if (s[next] == '+' || s[next] == '-') {
					if (valid_state != EXP_POINT) {
						valid = false;
						state = TERM;
						break;
					}
					next++;
				}
				state = EXP_MAG;
				break;
			case EXP_MAG:				
				if (isdigit(s[next])) {
					next++;
					valid_state = EXP_MAG;
				}
				else
					state = SPACE_TERM;

				if (valid_state == EXP_POINT || valid_state == EXP_SIGN) {
					valid = false;
					state = TERM;
					break;
				}
				break;
			case SPACE_TERM:
				if (s[next] == ' ') {
					next++;
					valid_state = SPACE_TERM;
				}
				else
					state = TERM;
				break;
			}

			if (state == TERM && next < size)
				valid = false;

		}

		return valid;
	}
};

void validNumbersMain() {
	Solution obj;
	obj.isNumber(".");
}
