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
	int regExpLen;
	int strLen;

	typedef bool (Solution::*stateF)(const char* regExp, int& regExpIdx, const char* str, int& strIdx);

	//stateF nextState;

public:
	
	stateF findNextState(const char* regExp, int& regExpIdx, const char* str, int& strIdx) {
		stateF nextState;
		int len = regExpLen;
		
		if (len == 0 && regExpIdx >= len) {			
			matchCharacter = '\0';
			return &Solution::stateTerminate;
		}

		if( (regExpIdx < regExpLen - 1) && (regExp[regExpIdx + 1] == '*')) {
				nextState = &Solution::stateGreedyPlaceholder;
				matchCharacter = regExp[regExpIdx];
				regExpIdx += 2;
		}
		else if (regExp[regExpIdx] == '.') {
				nextState = &Solution::stateDotPlaceholder;
				matchCharacter = regExp[regExpIdx];
				regExpIdx++;
		}
		else {
				nextState = &Solution::stateSingleCharacter;
				matchCharacter = regExp[regExpIdx];
				regExpIdx++;
		}
		
		return nextState;
	}

	bool process(const char* regExp, int& regExpIdx, const char* str, int& strIdx) {
		if (regExpIdx == regExpLen && strIdx == strLen)
			return true;
		else if (!(regExpIdx < regExpLen && strIdx < strLen)) {
			isMatching = false;
			return true;
		}

		stateF nextState = findNextState(regExp, regExpIdx, str, strIdx);
		isMatching =  (this->*nextState)(regExp, regExpIdx, str, strIdx);
		return false;
	}

	bool parse(string s, string p){		
		if (s.empty() || p.empty()) {
			return false;
		}

		const char* regExp = p.c_str();
		int regExpIdx = 0;
		regExpLen = p.size();

		const char* str = s.c_str();
		int strIdx = 0;
		strLen = s.size();
		
		bool terminate = false;

		while (!terminate) {
			terminate = process(regExp, regExpIdx, str, strIdx);
		}

		return isMatching;
	}	

	bool stateSingleCharacter(const char* regExp, int& regExpIdx, const char* str, int& strIdx){
		int len = strLen;
		if (len == 0 || strIdx >= len)
			return false;
		else {
			if (matchCharacter == str[strIdx++])
				return true;
			else
				return false;
		}
	}

	bool stateDotPlaceholder(const char* regExp, int& regExpIdx, const char* str, int& strIdx){
		int len = strLen;
		if (len == 0 || strIdx >= len)
			return false;
		else {
			strIdx++;
			return true;			
		}
	}

	bool stateGreedyPlaceholder(const char* regExp, int& regExpIdx, const char* str, int& strIdx){
		int len = strLen;
		if (len == 0 || strIdx >= len)
			return false;
		else {		

			while (strIdx < len) {
				/*
				if (matchCharacter != '.' && matchCharacter != str[strIdx]) 
					break;
				
				*/

				if (regExpIdx < regExpLen && regExp[regExpIdx] == str[strIdx])
					regExpIdx++;
				else {
					if (matchCharacter != '.' && matchCharacter != str[strIdx])
						break;
				}

				strIdx++;

			}			
			return true;				
		}
	}

	bool stateTerminate(const char* regExp, int& regExpIdx, const char* str, int& strIdx){
		return false;
	}

	bool isMatch(string s, string p) {
		return parse(s, p);
	}
};

void regularExpressionMain() {
	Solution obj;
	string str;
	string reg;

	str = "aaaa";
	reg = "a*";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "aa";
	reg = "a";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "aa";
	reg = "aa";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "aaa";
	reg = "aa";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "aaaa";
	reg = ".*";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "ab";
	reg = ".*";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;

	str = "aab";
	reg = "c*a*b";
	cout << "(" << str << " , " << reg << ")  => " << obj.isMatch(str, reg) << endl;
}