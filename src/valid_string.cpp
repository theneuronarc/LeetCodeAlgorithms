#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include "std_headers.h"
typedef struct {
	int start;
	int end;
	int freq;
	int val;
}element;

int validStringMain() {
	string input;
	string output;
	vector<int> hg(26, 0);
	vector<element> res;
	int arr[26];
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		hg[input[i] - 'a']++;
	}

	sort(hg.begin(), hg.end());
	printList(hg);
	
	int i = 0;

	while (!hg[i])
		i++;

	element tmp;
	for (; i < hg.size(); i++) {
		if (hg[i] != hg[i - 1]) {
			res.push_back(element());
			res.back().start = i;
			res.back().end = i;
			res.back().val = hg[i];
			res.back().freq = 1;
		}
		else {
			res.back().end++;
			res.back().freq++;
		}
	}

	if (res.size() > 2) {
		output = "NO";
	}
	else if (res.size() == 1 || res.empty()) {
		output = "YES";
	}
	else {
		if ((res[0].freq == 1 || res[1].freq == 1) || (res[0].val == res[1].val))
			output = "YES";
		else {
			if (abs(res[0].val - res[1].val) > 1)
				output = "NO";
			else {
				element tmp = (res[0].val > res[0].val) ? res[0] : res[1];
				if (tmp.freq > 1)
					output = "NO";
				else
					output = "YES";
			}
		}
	}

	cout << output;

	return 0;
}
