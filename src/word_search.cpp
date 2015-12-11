/*
https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells 
are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include "std_headers.h"

#define TRAIL(row, col) *((trail) + (row)*(cols) + (col))

class Solution {
public:
	bool dfs(int rows, int cols, int row, int col, int wordIdx, 
		bool* trail, vector<vector<char>>& board, string& word) {
		
		if (wordIdx >= word.size())
			return true;

		if (board[row][col] != word[wordIdx])
			return false;
		else {
			if (wordIdx == word.size() - 1)
				return true;
		}


		for (int x = -1; x < 2; x += 2) {			
				if (row + x < 0 || row + x >= rows)
					continue;

				if (TRAIL(row + x,col))
					continue;

				TRAIL(row + x, col) = true;
				if (dfs(rows, cols, row + x, col, wordIdx + 1, trail, board, word))
					return true;			
				TRAIL(row + x, col) = false;
		}

		for (int y = -1; y < 2; y += 2) {
				if (col + y < 0 || col + y >= cols)
					continue;

				if (TRAIL(row, col+y))
					continue;

				TRAIL(row, col + y) = true;
				if (dfs(rows, cols, row, col + y, wordIdx + 1, trail,  board, word))
					return true;			
				TRAIL(row, col + y) = false;
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty())
			return false;

		int rows = board.size();
		int cols = board[0].size();
		if (!cols)
			return false;

		bool* trail = (bool*) calloc(rows*cols, sizeof(bool));

		vector<vector<bool>> trail(rows, vector<bool>(cols, false));
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				TRAIL(row, col) = true;
				if (dfs(rows, cols, row, col, 0, trail, board, word))
					return true;
				TRAIL(row, col) = false;
			}
		}

		return false;
	}
};

void wordSearchMain() {
	Solution obj;
	vector<vector<char>> board;
	board.data()
	obj.exist(board, "aaa");
}