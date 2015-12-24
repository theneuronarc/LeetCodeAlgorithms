/*
https://leetcode.com/problems/triangle/
*/

#include "std_headers.h"

// O(n2) solution with O(n) space

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
	int* data = (int*)malloc(sizeof(int)*triangleRowSize);
	int* curRow;
	int prev , minSum;

	data[0] = *(triangle[0]);
	
	for (int row = 1; row < triangleRowSize; row++) {
		curRow = triangle[row];
		prev = data[0];
		data[0] += curRow[0];
		minSum = data[0];
		for (int col = 1; col < triangleColSizes[row] - 1; col++) {			
			prev =  min(prev, data[col]) + curRow[col];
			swap(prev, data[col]);
			minSum = min(minSum, data[col]);
		}
		data[triangleColSizes[row] - 1] = prev + curRow[triangleColSizes[row] - 1];
		minSum = min(minSum, data[triangleColSizes[row] - 1]);
	}
	free(data);
	return minSum;
}