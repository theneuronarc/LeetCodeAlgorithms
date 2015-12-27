#include "std_headers.h"

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		if (s.empty())
			return res;
		int size = s.size();
		res.push_back(vector<string>(1, string(1, s[0])));
		for (int i = 1; i < size; i++) {
			int resSize = res.size();
			for (int j = 0; j < resSize; j++) {
				int palCount = res[j].size();
				vector<string> tmp = res[j];
				string str{ s[i] };
				res[j].push_back(str);

				tmp[palCount - 1].push_back(s[i]);

				if (res[j][palCount - 1].size() == 1 && res[j][palCount - 1][0] == s[i]) {
					res.push_back(tmp);
				}

				if (palCount == 1)
					continue;

				tmp[palCount - 2] += tmp[palCount - 1];
				tmp.pop_back();

				if (res[j][palCount - 2].size() == 1 && res[j][palCount - 2][0] == s[i]) {
					res.push_back(tmp);
				}
			}
		}

		return res;
	}
};



class Solution1 {
public:
	int minCut(string s) {
		int* partitions = new int[s.size()+2];
		int size = s. size();
		int cuts = 0;
		const char* str = s.data();
		bool isSame = true;

		for (int i = 1; i < size; i++) {
			if (cuts == 0) {
				if (isSame && str[i] == str[i - 1])
					;
				else {
					isSame = true;
					cuts++;
					partitions[cuts - 1] = i;
				}
				continue;
			}
			else {
				int size_1 = (cuts == 1 ? partitions[cuts - 1] : partitions[cuts - 1] - partitions[cuts - 2]);
				int size_2 = (i - partitions[cuts - 1]);
				if (size_1 == 1 && str[partitions[cuts - 1] - 1] == s[i]) {
					cuts--;
				}
				else if (isSame && str[i] == str[i-1]) {
					;
				}
				else if(str[partitions[cuts-1] - 1] == str[i] && size_1 == 2){
					partitions[cuts - 1] = partitions[cuts - 1] - 1;
				}
				else {
					isSame = true;
					cuts++;
					partitions[cuts - 1] = i;
				}
			}
		}
		
		for (int i = 0; i < cuts; i++) {
			cout << partitions[i] << " ";
		}
		return cuts;
	}
};
// cabababcbc
void palPartMain() {
	Solution obj;
	vector<vector<string>> res = obj.partition("abababababab");
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].size() << " ";
		printList(res[i]);
	}
	Solution1 obj1;
	cout << endl << obj1.minCut("cabababcbc") << endl;
}