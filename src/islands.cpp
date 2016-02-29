/*
https://leetcode.com/problems/number-of-islands/
*/

void markIsland(char** grid, int gridRowSize, int gridColSize, int row, int col) {
	if (row >= gridRowSize || row < 0 || col < 0 || col >= gridColSize)
		return;

	if (grid[row][col] == '0')
		return;
	else
		grid[row][col] = '0';

	markIsland(grid, gridRowSize, gridColSize, row + 1, col);
	markIsland(grid, gridRowSize, gridColSize, row - 1, col);
	markIsland(grid, gridRowSize, gridColSize, row, col + 1);
	markIsland(grid, gridRowSize, gridColSize, row, col - 1);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
	int islandCount = 0;

	for (int i = 0; i < gridRowSize; i++) {
		for (int j = 0; j < gridColSize; j++) {
			if (grid[i][j] == '1') {
				islandCount++;
				markIsland(grid, gridRowSize, gridColSize, i, j);
			}
		}
	}

	return islandCount;
}