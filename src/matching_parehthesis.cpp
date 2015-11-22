/*
https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include "std_headers.h"

class ValidParentheses {
public:
	bool isValid(string s) {
		std::stack<char> data;
		const char* str = s.c_str();

		for (int i = 0; i < s.size(); i++) {
			if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
				if (data.empty())
					return false;
				else {
					if ((str[i] == ')' && data.top() != '(') ||
						(str[i] == '}' && data.top() != '{') ||
						(str[i] == ']' && data.top() != '['))
						return false;
					else
						data.pop();
				}
			}
			else {
				data.push(str[i]);
			}
		}

		if (data.empty())
			return true;
		else
			return false;
	}
};


void validParentheses(){
	string s;
	ValidParentheses obj;

	s = "()";
	cout << s << " => " << obj.isValid(s) << endl;
}