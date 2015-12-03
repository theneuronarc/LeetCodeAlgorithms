/*
https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.
*/

#include "std_headers.h"

class Solution {
public:
	bool isConflict(int* curPos, int row) {		
		int col = curPos[row];
		for (int i = 1; i < row; i++) {
			if (curPos[i] == col || ((row - i) == abs(col - curPos[i])))
				return true;
		}

		return false;
	}

	void searchRecurse(int n, int row, int col, int* curPos,
					   vector<string>& dummy, vector<vector<string>>& result) {
		curPos[row] = col;

		if (isConflict(curPos, row)) {			
			return;
		}
		
		if (row == n) {
			result.push_back(dummy);
			for (int i = 1; i <= row; i++) {
				result.back()[i-1][curPos[i]] = 'Q';
			}
			printList(result.back());			
			return;
		}
		

		for (int i = 0; i < n; i++) {
			searchRecurse(n, row + 1, i, curPos, dummy, result);			
		}		
	}

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		string dots(n, '.');
		vector<string> dummy(n, dots);

		int* pos = new int[(n + 1)];

		if (n == 0)
			return res;

		if (n == 1) {
			res.push_back(vector<string>({ "Q" }));
			return res;
		}		

		searchRecurse(n, 0, -1, pos, dummy, res);
		return res;
	}
};

void NQueensMain() {
	Solution obj;
	int n;

	n = 4;
	cout << endl << n << endl;
	obj.solveNQueens(n);

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
}