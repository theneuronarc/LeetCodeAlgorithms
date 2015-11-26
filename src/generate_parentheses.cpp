/*
https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()(
*/

#include "std_headers.h"

class Solution {
		
public:
	bool genFx(bool isOpen, int sum,  int countOpen, int countClose,
				int depth, int n, vector<string>& result, string& pat) {
		if (isOpen) {
			if (countOpen == 0 || ++sum > n)
				return false;

			countOpen--;
		}
		else {
			if (countClose == 0 || --sum < 0)
				return false;

			countClose--;
		}
		pat.push_back((isOpen ? '(' : ')'));

		if (++depth == 2 * n) {
			//cout << pat << endl;
			result.push_back(pat);
			return true;
		}

		if(genFx(true, sum, countOpen, countClose, depth, n, result, pat))
			pat.pop_back();

		if(genFx(false, sum, countOpen, countClose, depth, n, result, pat))
			pat.pop_back();

		return true;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string pat;
		genFx(true, 0, n, n, 0, n, result, pat);
		return result;
	}
};

void printList(vector<string>& res) {
	cout << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}

void genParenthesesMain() {
	vector<string> result;
	Solution obj;
	result = obj.generateParenthesis(3);
	printList(result);
	result.clear();
	result = obj.generateParenthesis(1);
	printList(result);
	result = obj.generateParenthesis(2);
	printList(result);
	result = obj.generateParenthesis(0);
	printList(result);
}