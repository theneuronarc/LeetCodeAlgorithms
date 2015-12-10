/*
https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

#include "std_headers.h"

class Solution {
public:
	int binarySearch(vector<vector<int>>& matrix, bool row, int rows, int cols, int line, int target) {
		int l = 0;
		int r = (row ? cols -1 : rows - 1);
		int m;
		int val;		

		while (l <= r) {
			m = l + (r - l) / 2;
			val = (row ? matrix[line][m] : matrix[m][line]);
			if (val == target) return m;
			if (val < target) l = m + 1;
			else r = m - 1;
		}

		if (row)
			return -1;
		else
			return (val < target ? m : m - 1);
	}


	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;

		int rows = matrix.size();
		int cols = matrix[0].size();

		if (!rows || !cols)
			return false;

		int row = binarySearch(matrix, false, rows, cols, 0, target);
		if (row < 0)
			return false;

		if (matrix[row][0] == target)
			return true;

		int col = binarySearch(matrix, true, rows, cols, row, target);

		if (col == -1)
			return false;
		else {
			if (matrix[row][col] == target)
				return true;
			else
				return false;
		}
	}
};

void set2DMatrixMain() {
	Solution obj;
	//vector < vector<int>> vec = { {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 50} };
	vector < vector<int>> vec = { {} };
	cout << obj.searchMatrix(vec, 2);
}