#include "std_headers.h"

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int res;
		if (nums.empty())
			return 1;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= 0)
				nums[i] = 0;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > nums.size())
				nums[i] = 0;
			else {
				while (nums[i] && nums[i] != (i + 1)) {
					swap(nums[i], nums[nums[i] - 1]);

					if (nums[i] == (i + 1) || !nums[i])
						break;

					if (nums[i] == nums[nums[i] - 1]) {
						nums[i] = 0;
						break;
					}
				}
			}
		}

		for (res = 0; res < nums.size() && nums[res]; res++);		
		return (res + 1);
	}
};

void firstMissingPosMain() {
	Solution obj;
	vector<int> vec = { 2,1 };
    cout << obj.firstMissingPositive(vec);
}