/*
https://leetcode.com/problems/compare-version-numbers/
*/

#include <string.h>

#define printf(...)

int versionSub(char* ver, int* pos) {
	int res = 0;
	int len = strlen(ver);
	if (*pos >= len) {
		return 0;
	}
	while (*pos < len && ver[*pos] != '.') {
		printf("\n%c", ver[*pos]);
		res *= 10;
		res += ver[*pos] - '0';
		(*pos)++;
	}
	if (*pos != len)
		(*pos)++;
	return res;
}

int compareVersion(char* version1, char* version2) {
	int i1 = 0, i2 = 0;
	int v1, v2;
	int len1 = strlen(version1);
	int len2 = strlen(version2);
	while (i1 < len1 || i2 < len2) {
		v1 = versionSub(version1, &i1);
		v2 = versionSub(version2, &i2);
		printf("\n%d %d", i1, i2);
		if (v1 > v2)
			return 1;
		else if (v1 < v2)
			return -1;
		else
			continue;
	}
	return 0;
}

void compareVersionMain() {
	char v1[] = "1.1.1";
	char v2[] = "1.1";
	compareVersion(v1, v2);
}