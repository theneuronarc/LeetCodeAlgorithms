/*
*/

#include "std_headers.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int cur_pos = 0;
		int* data = nums.data();
		int size = nums.size();

		if (!size) {
			return 0;
		}

		for (int i = 0; i < size; i++) {
			if (data[cur_pos] == data[i])
				continue;
			else {
				if (cur_pos != i) {
					data[cur_pos + 1] = data[i];
				}
				cur_pos++;
			}
		}
		return (cur_pos + 1);
	}
};