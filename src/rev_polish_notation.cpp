/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

#include "std_headers.h"

class Solution {
public:
	typedef enum {
		ADD,
		SUB,
		MUL,
		DIV,
		INT
	}token;

	token isNumber(string& s) {
		if (s.length() > 1)
			return INT;
		else {
			switch (s[0]) {
			case '+':
				return ADD;
			case '-':
				return SUB;
			case '*':
				return MUL;
			case '/':
				return DIV;
			default:
				return INT;
			}
		}
	}

	int evalRPN(vector<string>& tokens) {
		std::stack<int> numStack;
		
		for (int i = 0; i < tokens.size(); i++) {
			int res;
			token t = isNumber(tokens[i]);
			if (t == INT) {
				int num = stoi(tokens[i]);
				numStack.push(num);
			}
			else {				
				int num1 = numStack.top();
				numStack.pop();
				int num2 = numStack.top();
				numStack.pop();

				switch (t) {
				case ADD:
					res = num2 + num1;
					break;
				case SUB:
					res = num2 - num1;
					break;
				case MUL:
					res = num2 * num1;
					break;
				case DIV:
					res = num2/num1;
					break;
				}
				numStack.push(res);
			}
		}
		return numStack.top();
	}
};