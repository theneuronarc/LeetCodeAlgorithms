/*
https://leetcode.com/problems/happy-number/
*/

int sos(int n) {
	int res = 0;
	while (n) {
		res += ((n % 10)*(n % 10));
		n /= 10;
	}

	return res;
}

bool isHappy(int n) {
	char map[250] = { 0 };
	// After 1 sos maximum sum can not be larger than 243
	if ((n = sos(n)) == 1)
		return true;

	while (!map[n = sos(n)]) {
		map[n] = 1;
		if (n == 1)
			return true;
	}

	return false;
}