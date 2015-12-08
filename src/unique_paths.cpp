/*
https://leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/

#include "std_headers.h"

class Solution {
public:
	int uniquePaths(int m, int n) {
		long unsigned  matrix[100][100] = { 0 };
		for (int i = 0; i < m; i++) {
			matrix[i][n - 1] = 1;
		}

		for (int i = 0; i < n; i++) {
			matrix[m - 1][i] = 1;
		}

		matrix[m - 1][n - 1] = 1;

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
			}
		}

		return matrix[0][0];
	}
};

#define set(i,j,val) matrix[i][j] = (gridData[i][j] ? 0 : (val));
class Solution1 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int** gridData = new int*[m];

		for (int i = 0; i < m; i++) {
			gridData[i] = obstacleGrid[i].data();
		}

		int matrix[100][100] = { 0 };

		if (obstacleGrid[m - 1][n - 1])
			return 0;
		else
			matrix[m - 1][n - 1] = 1;

		for (int i = m - 2; i >= 0; i--) {
			set(i, n - 1, matrix[i + 1][n - 1]);
		}

		for (int i = n - 2; i >= 0; i--) {
			set(m - 1, i, matrix[m - 1][i + 1]);
		}

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				set(i, j, matrix[i + 1][j] + matrix[i][j + 1]);
			}
		}

		return matrix[0][0];
	}
};