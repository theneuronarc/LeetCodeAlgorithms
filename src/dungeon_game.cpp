/*
https://leetcode.com/problems/dungeon-game/
*/

#define rev(x)	-(x)
#define min(a,b) (a<b?a:b)

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int dungeonColSize) {
	int pathCost;
	int increment = 0;;
	for (int col = dungeonColSize - 1; col >= 0; col--) {
		for (int row = dungeonRowSize - 1; row >= 0; row--) {
			if (col + 1 < dungeonColSize && row + 1 < dungeonRowSize) {
				pathCost = min(dungeon[row + 1][col], dungeon[row][col + 1]);
			}
			else if (row + 1 < dungeonRowSize) {
				pathCost = dungeon[row + 1][col];
			}
			else if (col + 1 < dungeonColSize) {
				pathCost = dungeon[row][col + 1];
			}
			else {
				pathCost = 0;
			}

			if (dungeon[row][col] > 0) {
				if (dungeon[row][col] - pathCost > 0) {
					pathCost = 0;
				}
				else {
					pathCost -= dungeon[row][col];
					if (!row && !col)
						pathCost++;
				}
			}
			else {
				pathCost += rev(dungeon[row][col]);
				if (!row && !col)
					pathCost++;
			}

			dungeon[row][col] = pathCost;
		}
	}

	return dungeon[0][0] ? dungeon[0][0] : 1;
}