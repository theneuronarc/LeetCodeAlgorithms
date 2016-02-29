/*
https://leetcode.com/problems/isomorphic-strings/
*/

bool isIsomorphic(char* s, char* t) {
	char map[26] = { 0 };
	int r1, r2;

	map[s[0] - 'a'] = t[0];

	for (int i = 1; i < strlen(s); i++) {
		if (map[s[i] - 'a'] && map[s[i] - 'a'] != t[i])
			return false;

		r1 = s[i] - s[i - 1] >= 0 ? 1 : 0;
		r2 = t[i] - t[i - 1] >= 0 ? 1 : 0;

		if (r1 != r2)
			return false;
	}
}