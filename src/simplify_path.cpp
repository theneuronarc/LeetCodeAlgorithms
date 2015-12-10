/*
https://leetcode.com/problems/simplify-path/
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
*/

#include "std_headers.h"

class Solution {
public:
	char* simplifyPathC(char* path) {
		int size = strlen(path);
		int folders[1024] = { 0 };
		int folderIdx = 0;
		int start = 0;
		int length = 0;
		path[size] = '/';

		for (int i = 0; i <= size; i++) {
			if (path[i] == '/') {
				path[i] = '\0';
				if (length) {
					if (length == 1 && path[start] == '.')
						;
					else if (length == 2 && path[start] == '.' && path[start + 1] == '.') {
						if (folderIdx) folderIdx--;
					}
					else {
						folders[folderIdx++] = start;
					}
				}
				start = i + 1;
				length = 0;
				continue;
			}
			length++;
		}

		char* simplePath = path;
		int i = 0;
		length = 0;
		do {
			*simplePath = '/';
			simplePath++;
			if (i < folderIdx) {
				length = strlen(path + folders[i]);
				strcpy(simplePath, path + folders[i]);
				simplePath += length;
				i++;
			}
			else
				break;
		} while (i < folderIdx);

		*simplePath = '\0';
		cout << path;
		return path;
	}

	string simplifyPath(string path) {
		char* simple = simplifyPathC(const_cast<char*>(path.data()));
		return string(simple);
	}
};

void simplifyPathMain() {
	Solution obj;
	obj.simplifyPath("/home////foo");
}