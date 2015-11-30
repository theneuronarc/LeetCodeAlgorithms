/*
*/

#include "std_headers.h"

class Solution {
public:
	void generator(string& str) {
		string res;
		char cur_sym = str[0];
		int count = 1;
		int write_idx = 0;

		for (int i = 1; i < str.size(); i++) {
			if (cur_sym == str[i]) {
				count++;
				continue;
			}

			res.push_back('0' + count);
			res.push_back(cur_sym);

			count = 1;
			cur_sym = str[i];
		}

		res.push_back('0' + count);
		res.push_back(cur_sym);

		str = res;
	}

	string countAndSay(int n) {
		string res = "1";
		if (n <= 1)
			return res;

		for (int i = 1; i < n; i++) {
			generator(res);
			cout << i << " => " << res << endl;
		}
		return res;
	}
};

void countSayMain() {
	Solution obj;
	obj.countAndSay(5);
}