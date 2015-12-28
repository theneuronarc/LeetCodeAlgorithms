/*
https://leetcode.com/problems/candy/
*/

#include "std_headers.h"

int candy(int* ratings, int ratingsSize) {
	int candyCount = (ratingsSize > 1 && ratings[0] > ratings[1] ? 0 : 1);
	int curPos = 1;
	int peakPos = 0;
	int prev = 1;
	while (curPos < ratingsSize) {
		//printf("\n%d %d", curPos, candyCount);
		if (ratings[curPos] > ratings[curPos - 1]) {
			prev++;
			if ((curPos == ratingsSize - 1) || ratings[curPos] <= ratings[curPos + 1]) {
				candyCount += prev;
			}
			else {
				peakPos = curPos;
			}
		}
		else if (ratings[curPos] < ratings[curPos - 1]) {
			if ((curPos == ratingsSize - 1) || ratings[curPos] <= ratings[curPos + 1]) {
				// Trough
				int posCount = (curPos - peakPos + 1);
				candyCount += (posCount*(posCount + 1)) >> 1;
				if (prev > posCount) {
					candyCount += (prev - posCount);
				}
				prev = 1;
			}
		}
		else {
			prev = 1;
			if ((curPos == ratingsSize - 1) || ratings[curPos] <= ratings[curPos + 1]) {
				candyCount++;
			}
			else {
				peakPos = curPos;
			}
		}
		curPos++;
	}

	return candyCount;
}