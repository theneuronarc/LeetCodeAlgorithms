#include "std_headers.h"

#define MAX_SIZE 64

class Solution {
public:
	bool isScramble(string A, string B) {
		int n = A.size();
		int table[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0 };
		int len = 1;
		int partitionLen;
		if (!n)
			return true;

		for (int aStart = 0; aStart <= n - len; aStart++) {
			for (int bStart = 0; bStart <= n - len; bStart++) {
				if (A[aStart] == B[bStart])
					table[len - 1][aStart][bStart] = 1;
				else
					table[len - 1][aStart][bStart] = -1;
			}
		}

		len++;

		for (; len <= n; len++) {
			for (int aStart = 0; aStart <= n - len; aStart++) {
				for (int bStart = 0; bStart <= n - len; bStart++) {
					for (int partitionLen = 1; partitionLen < len; partitionLen++) {
						/*printf("\nl:%d, aStart = %d, bStart = %d pl = %d (1) (%d, %d) (%d,%d) (2) (%d, %d) (%d,%d)",
						len, aStart, bStart, partitionLen, aStart, bStart, aStart + partitionLen, bStart + partitionLen,
						aStart, bStart + len - partitionLen, aStart + partitionLen, bStart);*/
						if (
							(table[partitionLen - 1][aStart][bStart] == 1 &&
								table[len - partitionLen - 1][aStart + partitionLen][bStart + partitionLen] == 1) ||

							(table[partitionLen - 1][aStart][bStart + len - partitionLen] == 1 &&
								table[len - partitionLen - 1][aStart + partitionLen][bStart] == 1)
							)
						{
							table[len - 1][aStart][bStart] = 1;
							break;
						}
						else
						{
							table[len - 1][aStart][bStart] = -1;
						}
					}
					//printf("\n=> %d",table[len - 1][aStart][bStart]);
				}
			}
		}

		return (table[n - 1][0][0] == 1 ? true : false);
	}
};

void scrambledStringMain() {
	Solution obj;
	obj.isScramble("great", "rgtae");
}