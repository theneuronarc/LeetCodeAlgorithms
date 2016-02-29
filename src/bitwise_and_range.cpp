/*
https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/

int rangeBitwiseAnd(int m, int n) {
	int log2n = 0;
	int res = n;
	while (res >>= 1) {
		log2n++;
	}

	if (m < (1 << log2n)) {
		return 0;
	}
	else {
		res = 1 << log2n;
		res |= rangeBitwiseAnd(m & ((1 << log2n) - 1), n & ((1 << log2n) - 1));
	}

	return res;
}

int rangeBitwiseAnd(int m, int n) {
	int log2n = 0;
	int res = n;
	while (res >>= 1) {
		log2n++;
	}

	res = 0;

	for (int i = log2n; i >= 0; i--) {
		int bit = 1 << i;
		if ((m & bit) == (n & bit)) {
			res |= (m&bit);
		}
		else
			break;
	}

	return res;
}