/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

iven a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include "std_headers.h"

const char* keypad[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
int keypadSize[] = { 0,0,3,3,3,3,3,4,3,4 };

class Solution {
public:


	bool generator(const char arr[], int size, int index, char com[], vector<string>& res) {
		if (index == size) {
			res.push_back(com);
			return true;
		}

		if (arr[index] == '1' || arr[index] == '0') {
			return false;
		}

		int num = arr[index] - '0';

		for (int i = 0; i < keypadSize[num]; i++) {
			com[index] = keypad[num][i];
			com[index + 1] = '\0';
			if (generator(arr, size, index + 1, com, res))
				continue;
			else
				return false;
		}

		return true;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty())
			return res;
		char* combination = new char[digits.size() + 1];
		generator(digits.data(), digits.size(), 0, combination, res);
		return res;
	}
};

void phoneNumbersMain() {
	Solution obj;
	string digits = "823";
	printList(obj.letterCombinations(digits));
}