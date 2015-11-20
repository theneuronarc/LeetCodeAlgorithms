/*
https://leetcode.com/problems/regular-expression-matching/

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/

#include "std_headers.h"




class Solution {
	bool isMatching;
	char matchCharacter;
	typedef bool (Solution::*stateF)(const char* regExp, int regExpIdx, const char* str, int strIdx);
public:
	stateF findNextState(const char* regExp, int& regExpIdx) {
		stateF nextState;

		if( (regExpIdx < strlen(regExp) - 1) && (regExp[regExpIdx + 1] == '*')) {
				nextState = stateGreedyPlaceholder;
				regExpIdx += 2;
		}
		else if (regExp[regExpIdx] == '.') {
				nextState = stateDotPlaceholder;
				regExpIdx++;
		}
		else {
				nextState = stateSingleCharacter;
				regExpIdx++
		}

		matchCharacter = regExp[regExpIdx];
		return nextState;
	}

	bool parse(string s, string p){
		if (s.empty() || p.empty()) {
			return false;
		}
		stateBegin(s.c_str(), 0, p.c_str(), 0);

		return isMatching;
	}

	bool stateBegin(const char* regExp, int regExpIdx, const char* str, int strIdx) {
		stateF nextState;
		 nextState(regExp, regExpIdx, str, strIdx);
	}
	bool stateSingleCharacter(const char* regExp, int regExpIdx, const char* str, int strIdx){}
	bool stateDotPlaceholder(const char* regExp, int regExpIdx, const char* str, int strIdx){}
	bool stateGreedyPlaceholder(const char* regExp, int regExpIdx, const char* str, int strIdx){}

	void stateTerminate(){}

	bool isMatch(string s, string p) {
		return parse(s, p);
	}
};

void regularExpressionMain() {

}