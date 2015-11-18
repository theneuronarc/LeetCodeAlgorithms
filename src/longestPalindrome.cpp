/*
https://leetcode.com/problems/longest-palindromic-substring/
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include "std_headers.h"

class LongestPalindrome_ugly {
	public:

		void findPalindrome(string& s, int idxB, int idxF, string& result) {
			while (idxB >= 0 && idxF < s.size()) {
				if (s[idxB] == s[idxF]) {
					idxB--;
					idxF++;
				}
				else {
					break;
				}
			}

			idxB++;
			idxF--;

			if (result.size() < (idxF - idxB + 1))
				result = s.substr(idxB, (idxF - idxB + 1));
		}


		void testPalindrome(string& s, int i, string& result) {
			int idxB = 0, idxF = 0;
			bool notPresent = true;
			if (s[i - 1] == s[i + 1]) {
				findPalindrome(s, (i - 1), (i + 1), result);
				notPresent = false;
			}

			if (s[i] == s[i + 1]) {
				findPalindrome(s, i, (i + 1), result);
				notPresent = false;
			}

			if (notPresent)
				return;
		}



		string longestPalindrome(string s) {

			bool notPresent = true;
			string result = "";
			if (s.size() <= 1)
				return s;

			if (s[0] == s[1]) {
				result = s.substr(0, 2);
			}

			for (unsigned int i = 1; i < s.size() - 1; i++) {
				testPalindrome(s, i, result);
			}

			return result;
		}
};

class LongestPalindrome {
public:
	string longestPalindrome(string str) {
		char* s = (char*)str.c_str();
		int strLen = strlen(s);
		int idxB = 0, idxF = 0;
		bool present = false;
		unsigned int start = 0, end = 0, maxLen = 1;

		for (unsigned int i = 0; i < strLen; i++) {
			present = false;
			idxB = i;
			idxF = i + 1;

			while (idxB >= 0 && idxF < strLen && (s[idxB] == s[idxF])) {
				idxB--;
				idxF++;
				present = true;
			}

			if (present) {
				idxB++;
				idxF--;

				if (maxLen < (idxF - idxB + 1)) {
					start = idxB;
					end = idxF;
					maxLen = (idxF - idxB + 1);
				}
			}



			idxB = i - 1;
			idxF = i + 1;
			present = false;

			while (idxB >= 0 && idxF < strLen && (s[idxB] == s[idxF])) {
				idxB--;
				idxF++;
				present = true;
			}

			if (present) {
				idxB++;
				idxF--;

				if (maxLen < (idxF - idxB + 1)) {
					start = idxB;
					end = idxF;
					maxLen = (idxF - idxB + 1);
				}
			}
		}

		return str.substr(start, maxLen);
	}
};

char* longestPalindrome(char* s) {	
	int strLen = strlen(s);
	int idxB = 0, idxF = 0;
	bool present = false;
	unsigned int start = 0, end = 0, maxLen = 1;
	
	for (unsigned int i = 0; i < strLen; i++) {
		present = false;
		idxB = i;
		idxF = i + 1;

		while (idxB >= 0 && idxF < strLen && (s[idxB] == s[idxF])) {
			idxB--;
			idxF++;
			present = true;
		}

		if (present) {
			idxB++;
			idxF--;

			if (maxLen < (idxF - idxB + 1)) {
				start = idxB;
				end = idxF;
				maxLen = (idxF - idxB + 1);
			}
		}

		

		idxB = i - 1;
		idxF = i + 1;
		present = false;

		while (idxB >= 0 && idxF < strLen && (s[idxB] == s[idxF])) {
			idxB--;
			idxF++;
			present = true;
		}

		if (present) {
			idxB++;
			idxF--;

			if (maxLen < (idxF - idxB + 1)) {
				start = idxB;
				end = idxF;
				maxLen = (idxF - idxB + 1);
			}
		}		
	}

	s[end + 1] = '\0';
	return (s + start);
}

void longestpalindromeMain() {
	LongestPalindrome obj;
	string s = "adsbkjhqwertyytrewq";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "abc";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "baac";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "baab";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "daadx";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "gcaacx";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "gcadacx";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "fadafx";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "yfadaf";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "aaaaa";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "aaaa";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;

	s = "ccd";
	cout << obj.longestPalindrome(s) << endl;
	cout << longestPalindrome((char*)s.c_str()) << endl;
}

