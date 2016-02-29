/*
https://leetcode.com/problems/number-of-1-bits/
*/

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n) {
	int res = 0;
	while (n) {
		if (n & 0x1)
			res++;

		n >>= 1;
	}
}

int hammingWeight(uint32_t n) {
	int res = 0;
	while (n) {
		res++;
		n &= (n - 1);
	}

	return res;
}