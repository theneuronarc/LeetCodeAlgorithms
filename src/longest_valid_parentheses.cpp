#include "std_headers.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		std::stack<int> data;
		int start = 0, end = 0;
		int maxLength = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				data.push(i);
			else {
				start = data.top();
				data.pop();
				end = i;
			}
		}
	}
};


void longestValidParMain() {
	Solution obj;
	string s;

}
