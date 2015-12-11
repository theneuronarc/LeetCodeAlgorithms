#include "std_headers.h"

class Solution {
public:
	string minWindow(string s, string t) {
		int start = 0, end = 0;
		int total = 0;

		int sSize = s.size();
		int tSize = t.size();

		char startVal, endVal;


		const char* data = s.data();
		int patMap[256] = { 0 };
		int curMap[256] = { 0 };

		int minStart = -1, minEnd = -1;
		int minLen = 0;

		for (int i = 0; i < tSize; i++) {
			patMap[t[i]]++;
		}

		while (end < sSize) {			
			endVal = data[end];
			startVal = data[start];

			if (curMap[endVal] < patMap[endVal])
				total++;

			curMap[endVal]++;
			end++;

			while (!patMap[startVal] ||  (curMap[startVal] > patMap[startVal])){				
				curMap[startVal]--;
				start++;
				startVal = data[start];
				if (start == end)
					break;
			}

			if (total == tSize) {
				if (!minLen || (minLen > (end - start))) {
					minStart = start;
					minEnd = end;
					minLen = (end - start);
				}
			}
		}

		return (minLen ? s.substr(minStart, minLen) : "");
	}
};


void minWindMain() {
	Solution obj;
	string txt = "ADOBECODEABANC";
	string pat = "AABC";

	obj.minWindow(txt, pat);
}