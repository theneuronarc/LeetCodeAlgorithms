/*
*/

#include "std_headers.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int cur_pos = 0;
		int mov_pos = 0;

		if (nums.empty()) {
			return 0;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (nums[cur_pos] == nums[i])
				continue;
			else {
				if (cur_pos != i) {
					nums[cur_pos + 1] = nums[i];
				}
				cur_pos++;
			}
		}
		return (cur_pos + 1);
	}
};


