/*
https://leetcode.com/problems/surrounded-regions/
*/

#include "std_headers.h"

#define printf(...)
typedef struct {
	int row;
	int col;
}Position;

int stackTop = -1;
Position* Stack;

#define board(row,col) *(board[row] + col)

#define test(row, col) (!(row >= 0 && row < boardRowSize) || !(col >= 0 && col < boardColSize) || board(row, col) == 'X' || board(row, col) == 'Y')

void dfs(char** board, int boardRowSize, int boardColSize) {
	Position top;
	int row, col;
	while (stackTop >= 0) {

		top = Stack[stackTop--];
		row = top.row;
		col = top.col;
		printf("\n%d %d %d", row, col, stackTop);

		//if (test(row, col))
		//	continue;

		printf(" Valid");

		//board(row, col) = 'Y';

		if (!test(row - 1, col)) {
			board(row - 1, col) = 'Y';
			stackTop++;
			Stack[stackTop].row = row - 1;
			Stack[stackTop].col = col;
		}

		if (!test(row, col - 1)) {
			board(row, col - 1) = 'Y';
			stackTop++;
			Stack[stackTop].row = row;
			Stack[stackTop].col = col - 1;
		}

		if (!test(row + 1, col)) {
			board(row + 1, col) = 'Y';
			stackTop++;
			Stack[stackTop].row = row + 1;
			Stack[stackTop].col = col;
		}

		if (!test(row, col + 1)) {
			board(row, col + 1) = 'Y';
			stackTop++;
			Stack[stackTop].row = row;
			Stack[stackTop].col = col + 1;
		}
	}
}

void solve(char** board, int boardRowSize, int boardColSize) {
	Stack = (Position*)malloc(sizeof(Position)*(boardRowSize * boardColSize));
	printf("\n%d %d", boardRowSize, boardColSize);
	if (boardRowSize <= 1)
		return;

	if (boardColSize <= 1)
		return;



	for (int i = 0; i < boardColSize; i++) {
		if (board(0, i) == 'O') {
			board(0, i) = 'Y';
			stackTop = 0;
			Stack[stackTop].row = 0;
			Stack[stackTop].col = i;
			dfs(board, boardRowSize, boardColSize);
		}
	}

	for (int i = 0; i < boardColSize; i++) {
		if (board(boardRowSize - 1, i) == 'O') {
			board(boardRowSize - 1, i) = 'Y';
			stackTop = 0;
			Stack[stackTop].row = boardRowSize - 1;
			Stack[stackTop].col = i;
			dfs(board, boardRowSize, boardColSize);
		}
	}

	for (int i = 0; i < boardRowSize; i++) {
		if (board(i, 0) == 'O') {
			board(i, 0) = 'Y';
			stackTop = 0;
			Stack[stackTop].row = i;
			Stack[stackTop].col = 0;
			dfs(board, boardRowSize, boardColSize);
		}
	}

	for (int i = 0; i < boardRowSize; i++) {
		if (board(i, boardColSize - 1) == 'O') {
			board(i, boardColSize - 1) = 'Y';
			stackTop = 0;
			Stack[stackTop].row = i;
			Stack[stackTop].col = boardColSize - 1;
			dfs(board, boardRowSize, boardColSize);
		}
	}
	printf("\nTested\n");
	for (int i = 0; i < boardRowSize; i++) {
		for (int j = 0; j < boardColSize; j++) {
			if (board(i, j) == 'Y')
				board(i, j) = 'O';
			else
				board(i, j) = 'X';
		}
	}

	for (int i = 0; i < boardRowSize; i++) {
		for (int j = 0; j < boardColSize; j++) {
			printf("%c ", board(i, j));
		}
		printf("\n");
	}
	printf("\nTested1");
	free(Stack);
}