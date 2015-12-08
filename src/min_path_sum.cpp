/*
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include "std_headers.h"

class Solution {
public:
	int minPathSum(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		for (int i = m-2; i >= 0; i--) {
			matrix[i][n - 1] += matrix[i+1][n-1];
		}

		for (int i = n-2; i >= 0; i--) {
			matrix[m - 1][i] += matrix[m - 1][i + 1];
		}		

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				matrix[i][j] += min(matrix[i + 1][j], matrix[i][j + 1]);
			}
		}

		return matrix[0][0];
	}
};