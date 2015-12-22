/*
https://leetcode.com/problems/pascals-triangle/
*/

#include"std_headers.h"

int** generate(int numRows, int** columnSizes, int* returnSize) {

	int** rows = (int**)malloc(sizeof(int*)*(numRows));
	*columnSizes = (int*)malloc(sizeof(int)*numRows);

	rows[0] = (int*)malloc(sizeof(int));
	*(rows[0]) = 1;
	(*columnSizes)[0] = 1;

	rows[1] = (int*)malloc(sizeof(int)*2);
	*(rows[1]) = 1;
	*(rows[1] + 1) = 1;
	(*columnSizes)[1] = 2;

	for (int i = 2; i < numRows; i++) {
		rows[i] = (int*)malloc(sizeof(int)*(i + 1));
		(*columnSizes)[1] = (i+1);
		*(rows[i]) = 1;
		*(rows[i] + i) = 1;
		for (int j = 1; j < i; j++) {
			*(rows[i] + j) = *(rows[i-1] + j - 1) + *(rows[i - 1] + j);
		}
	}
	*returnSize = numRows;

	return rows;
}

int* getRow(int rowIndex, int* returnSize) {
	int* data = (int*)calloc(rowIndex + 2, sizeof(int));
	int size = (rowIndex + 2);
	int startIdx = size - 3;
	data[startIdx + 1] = 1;
	data[startIdx + 2] = 1;

	for (int i = 2; i <= rowIndex; i++) {
		
		for (int j = 0; j < i; j++) {
			data[startIdx + j] = data[startIdx + j] + data[startIdx + j + 1];
		}
		startIdx--;
	}
	*returnSize = (rowIndex + 1);
	return (data + 1);
}

void pascalTriangleMain() {
	int size;
	getRow(3, &size);
}

void preOrderTriangle(int row, int col, int curSum, int* minSum, int** triangle, int triangleRowSize, int *triangleColSizes) {
	//printf("\n%d %d %d", row, col, curSum);
	if (row >= triangleRowSize || col >= triangleColSizes[row])
		return;

	int* curRow = triangle[row];

	if (row == triangleRowSize - 1) {
		if (curSum + curRow[col] < *minSum)
			*minSum = curSum + curRow[col];
	}

	preOrderTriangle(row + 1, col, curSum + curRow[col], minSum, triangle, triangleRowSize, triangleColSizes);
	preOrderTriangle(row + 1, col + 1, curSum + curRow[col], minSum, triangle, triangleRowSize, triangleColSizes);
}


int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
	if (!triangleRowSize || !triangleColSizes[0])
		return 0;
	int* path = (int*)malloc(sizeof(int)*triangleRowSize);
	int minSum = INT_MAX;
	preOrderTriangle(0, 0, 0, &minSum, triangle, triangleRowSize, triangleColSizes);
	return minSum;
}