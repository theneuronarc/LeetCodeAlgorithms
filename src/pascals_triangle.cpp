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