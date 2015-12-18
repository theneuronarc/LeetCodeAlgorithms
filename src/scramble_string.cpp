#include "std_headers.h"


#define MAX_SIZE 128
class Solution {


public:
	bool isScrambleDFS(string s1, string s2, int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE]) {
		cout << "s1:" << s1 << "  " << "s2:" << s2 << endl;
		int n = s1.size();
		bool res[4];
		if (n == 0)
			return true;

		if (n == 1) {
			if (s1[0] == s2[0])
				return true;
			else
				return false;
		}

		for (int i = 0; i < n - 1; i++) {
			if (A[0][i])
				res[0] = A[0][i] == -1 ? false : true;
			else {
				res[0] = isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1));
				A[0][i] = res[0] ? 1 : -1;
			}

			if (res[0]) {
				if (A[i + 1][n - 1])
					res[1] = A[i + 1][n - 1] == -1 ? false : true;
				else {
					res[1] = isScramble(s1.substr(i + 1, n - i - 1), s2.substr(i+1, n - i - 1));
					A[i + 1][n - 1] = res[1] ? 1 : -1;
				}
			}
			cout << res[0] << " " << res[1] << endl;

			if (res[0] && res[1])
				return true;

			if (B[0][i])
				res[2] = B[0][i] == -1 ? false : true;
			else {
				res[2] = isScramble(s1.substr(0, i + 1), s2.substr(n - i - 1, i + 1));
				B[0][i] = res[2] ? 1 : -1;
			}
			if (res[2]) {
				if (B[i + 1][n - 1])
					res[3] = B[i + 1][n - 1] == -1 ? false : true;
				else {
					res[3] = isScramble(s1.substr(i + 1, n - i - 1), s2.substr(0, n - i - 1));
					B[i + 1][n - 1] = res[3] ? 1 : -1;
				}
			}

			cout << res[2] << " " << res[3] << endl;

			if (res[2] && res[3])
				return true;
		}

		return false;
	}

	bool isScramble(string s1, string s2) {
		int A[MAX_SIZE][MAX_SIZE] = { 0 };
		int B[MAX_SIZE][MAX_SIZE] = { 0 };
		return isScrambleDFS(s1, s2, A, B);

	}
};
void scrambledStringMain() {
	Solution obj;
	
		
	obj.isScramble("abcdefghij", "efghijcadb");
}