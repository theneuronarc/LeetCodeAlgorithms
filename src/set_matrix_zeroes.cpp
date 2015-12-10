/*
https://leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include "std_headers.h"

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		bool row = false;
		bool col = false;

		for (int i = 0; i < cols; i++) {
			if (matrix[0][i] == 0) {
				row = true;
				break;
			}
		}

		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0) {
				col = true;
				break;
			}
		}

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = 1; i < cols; i++) {
			if (matrix[0][i] == 0) {
				for (int j = 1; j < rows; j++)
					matrix[j][i] = 0;
			}
		}

		for (int i = 1; i < rows; i++) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < cols; j++)
					matrix[i][j] = 0;
			}
		}

		if (row) {
			for (int i = 0; i < cols; i++) {
				matrix[0][i] = 0;
			}
		}

		if (col) {
			for (int i = 0; i < rows; i++) {
				matrix[i][0] = 0;
			}
		}
	}
};

void setMatZeroesMain() {
	Solution obj;
	vector<vector<int>> vec = { {-1, 0, 3},{4, 0, 6},{7, 8, -9}};
	obj.setZeroes(vec);
}