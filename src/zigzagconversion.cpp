/*

https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

#include "std_headers.h"

class ugly {
public:
	string convert(string s, int numRows) {

		if (s.empty() || numRows <= 1)
			return s;
		vector<string> vec(numRows);
		string result;
		unsigned int groupSize = 2 * (numRows - 1);
		unsigned int strLen = s.size();
		unsigned int groupCount = (strLen + groupSize) / groupSize;

		for (unsigned int i = 0; i < groupCount - 1; i++) {
			for (unsigned int j = 0; j < numRows; j++) {
				if (j == 0 || j == (numRows - 1)) {
					vec[j].push_back(s[i*groupSize + j]);
				}
				else {
					vec[j].push_back(s[i*groupSize + j]);
					vec[j].push_back(s[i*groupSize + groupSize - j]);
				}
			}
		}

		for (unsigned int j = 0; j < numRows; j++) {
			int idx1 = (groupCount - 1)*groupSize + j;
			int idx2 = (groupCount - 1)*groupSize + groupSize - j;
			if (idx1 < strLen) {
				vec[j].push_back(s[idx1]);
			}

			if ((idx2 < strLen) && j > 0 && (j < numRows - 1)) {
				vec[j].push_back(s[idx2]);
			}
		}

		for (int i = 0; i < numRows; i++) {
			result.append(vec[i].c_str());
		}

		return result;
	}
};

int size(int i, int strLen, int groupSize, int groupCount, int numRows) { 
	int count = ((strLen - 1) % groupSize);
	int size = 0;
	int multiplier = 1;

	if (i > 0 && i < numRows - 1)
		multiplier = 2;
	else
		multiplier = 1;
	
	if (count >= (groupSize - i))
		size += 2;
	else if (count >= i)
		size += 1;
	else
		size = 0;

	size += (multiplier*(groupCount - 1));

	return size;
}

class ZigzagConversion {
public:
	char str[2048];
	char* table[1024];
	string convert(string s, int numRows) {
		typedef char* char_p;
		if (s.empty() || numRows <=1)
			return s;

		unsigned int groupSize = 2 * (numRows - 1);
		unsigned int strLen = s.size();
		unsigned int groupCount = (strLen + groupSize - 1) / groupSize;

		//char *result = (char*)malloc(strLen + 1);
		//char_p *offsetTable = (char_p *)malloc(numRows*sizeof(char_p));

		char *result = str;
		char_p *offsetTable = table;

		offsetTable[0] = result;

		for (int i = 1; i < numRows; i++) {
			offsetTable[i] = offsetTable[i - 1] + size(i - 1, strLen, groupSize, groupCount, numRows);			
		}

		for (unsigned int i = 0; i < groupCount - 1; i++) {
			for (unsigned int j = 0; j < numRows; j++) {
				if (j == 0 || j == (numRows - 1)) {
					*offsetTable[j] = s[i*groupSize + j];
					offsetTable[j]++;
				}
				else {
					*offsetTable[j] = s[i*groupSize + j];
					offsetTable[j]++;
					*offsetTable[j] = s[i*groupSize + groupSize - j];
					offsetTable[j]++;					
				}
			}
		}

		for (unsigned int j = 0; j < numRows; j++){
			int idx1 = (groupCount - 1)*groupSize + j;
			int idx2 = (groupCount - 1)*groupSize + groupSize - j;
			if (idx1 < strLen) {
				*offsetTable[j] = s[idx1];
				offsetTable[j]++;				
			}

			if ((idx2 < strLen) && j > 0 && (j < numRows - 1)) {
				*offsetTable[j] = s[idx2];
				offsetTable[j]++;				
			}			
		}

		result[strLen] = '\0';

		return string(result);
	}
};

void zigzagConcervion() {
	ZigzagConversion obj;
	string s = "PAYPALISHIRING";
	
	cout << s << " => " << obj.convert(s, 3) << endl;
	s = "A";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "AB";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABC";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCD";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDE";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDEF";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDEFG";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDEFGH";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDEFGHI";
	cout << s << " => " << obj.convert(s, 5) << endl;	
	s = "ABCDEFGHIJ";
	cout << s << " => " << obj.convert(s, 5) << endl;
	s = "ABCDEFGHIJK";
	cout << s << " => " << obj.convert(s, 5) << endl;
}