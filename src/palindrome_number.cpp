/*
https://leetcode.com/problems/palindrome-number/
*/

bool isPalindromeX(int x) {
	int count = 0;
	int mirror_x = x;

	if (x < 0)
		return false;
	if (!x)
		return true;

	while (mirror_x) {
		mirror_x /= 10;
		count++;
	}

	mirror_x = 0;
	for (int i = 0; i < (count + 1) / 2; i++) {
		mirror_x *= 10;
		mirror_x += (x % 10);
		x /= 10;
	}

	if (count % 2) {
		x *= 10;
		x += (mirror_x % 10);
	}


	if (mirror_x == x)
		return true;
	else
		return false;
}

bool isPalindrome(int x) {
	int mirror_x = 0;
	if (x < 0)
		return false;
	if (!x)
		return true;
	while (x) {
		mirror_x *= 10;
		mirror_x += (x % 10);

		if (!mirror_x)
			return false;

		if (x == mirror_x)
			return true;

		x /= 10;
		if (x == mirror_x)
			return true;
	}

	return false;
}
