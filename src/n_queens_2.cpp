/*
https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.
*/

#include "std_headers.h"

class NQueens2 {
	int count;
public:
	bool isConflict(int* curPos, int row) {
		int col = curPos[row];
		for (int i = 1; i < row; i++) {
			if (curPos[i] == col || ((row - i) == abs(col - curPos[i])))
				return true;
		}

		return false;
	}

	void searchRecurse(int n, int row, int col, int* curPos) {
		curPos[row] = col;

		if (isConflict(curPos, row)) {
			return;
		}

		if (row == n) {
			count++;
			return;
		}


		for (int i = 0; i < n; i++) {
			searchRecurse(n, row + 1, i, curPos);
		}
	}

	int totalNQueens(int n) {
		count = 0;

		int* pos = new int[(n + 1)];

		if (n <= 1)
			return n;

		searchRecurse(n, 0, -1, pos);
		return count;
	}
};

void NQueens2Main() {
	NQueens2 obj;

	int n = 4;
	cout << endl << n << " => " << obj.totalNQueens(n);

	n = 8;
	cout << endl << n << " => " << obj.totalNQueens(n);
	/*
	n = 1;
	cout << endl << n << endl;
	obj.solveNQueens(n);

	n = 4;
	cout << endl << n << endl;
	obj.solveNQueens(n);

	n = 2;
	cout << endl << n << endl;
	obj.solveNQueens(n);

	n = 3;
	cout << endl << n << endl;
	obj.solveNQueens(n);
	*/
}