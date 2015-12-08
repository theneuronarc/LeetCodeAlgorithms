/*
https://leetcode.com/problems/spiral-matrix/


Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include "std_headers.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;

		if (matrix.empty())
			return res;

		int row = 0;
		int col = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();


		while (rows > 0 && cols > 0) {
			for (int i = 0; i < cols; i++)
				res.push_back(matrix[row][col + i]);
			for (int i = 1; i < rows; i++)
				res.push_back(matrix[row + i][col + cols - 1]);
			for (int i = 1; i < cols && rows > 1; i++)
				res.push_back(matrix[row + rows - 1][col + cols - i - 1]);
			for (int i = 1; i < rows - 1 && cols > 1; i++)
				res.push_back(matrix[row + rows - 1 - i][col]);

			row++;
			col++;

			rows -= 2;
			cols -= 2;
		}

		return res;
	}
};


class Solution1 {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n,0));
		 
		if (n == 0)
			return matrix;

		int row = 0;
		int col = 0;
		int rows = n;
		int cols = n;
		int count = 1;


		while (rows > 0 && cols > 0) {
			for (int i = 0; i < cols; i++)
				matrix[row][col + i] = count++;
			for (int i = 1; i < rows; i++)
				matrix[row + i][col + cols - 1] = count++;
			for (int i = 1; i < cols && rows > 1; i++)
				matrix[row + rows - 1][col + cols - i - 1] = count++;
			for (int i = 1; i < rows - 1 && cols > 1; i++)
				matrix[row + rows - 1 - i][col] = count++;

			row++;
			col++;

			rows -= 2;
			cols -= 2;
		}

		return matrix;
	}
};