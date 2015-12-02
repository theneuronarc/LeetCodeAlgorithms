/*
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?

Solution : Rotate periphery of squares from outside to inside
*/

#include "std_headers.h"

class RotateImage {
public:
	void rotateSquarePeriphery(int row, int col, int n, vector<vector<int>>& matrix) {
		if (n <= 1)
			return;

		int tmp;
		for (int i = 0; i < n - 1; i++) {
			tmp = matrix[row][col + i];
			matrix[row][col + i] = matrix[row + n - i - 1][col];
			matrix[row + n - i - 1][col] = matrix[row + n - 1][col + n - i - 1];
			matrix[row + n - 1][col + n - i - 1] = matrix[row + i][col + n - 1];
			matrix[row + i][col + n - 1] = tmp;
		}

		rotateSquarePeriphery(row + 1, col + 1, n - 2, matrix);
	}

	void rotate(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return;

		rotateSquarePeriphery(0, 0, matrix.size(), matrix);
	}
};

void rotateImageMain() {
	RotateImage obj;
	vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
	obj.rotate(matrix);
}