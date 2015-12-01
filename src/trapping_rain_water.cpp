#include "std_headers.h"

typedef struct {
	int left;
	int right;
}walls;

class Solution {
public:
	int trap(vector<int>& height) {
		walls* maxWalls = new walls[height.size()];
		int maxLeft = 0;
		int maxRight = 0;
		int size = height.size();
		int cap = 0;

		for (int i = 0; i < size; i++) {
			maxWalls[i].left = maxLeft;
			maxLeft = max(maxLeft, height[i]);

			maxWalls[size - 1 - i].right = maxRight;
			maxRight = max(maxRight, height[size - 1 - i]);
		}

		for (int i = 0; i < size; i++) {
			int minHeight = min(maxWalls[i].left, maxWalls[i].right);
			cap += max(minHeight - height[i], 0);
		}

		return cap;
	}
};