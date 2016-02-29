#include <iostream>
#include <string>
using namespace std;

void preProcessString(string& s, long* table) {
	//int table[256] = { 0 };
	char curChar = '\0';
	long curCharFreq = 0;

	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			curCharFreq *= 10;
			curCharFreq += (s[i] - '0');

			//cout << curChar << " " << curCharFreq << endl;;
		}
		else {

			table[curChar] += curCharFreq;
			//cout << curChar << " " << table[curChar] << endl;
			curChar = s[i];
			curCharFreq = 0;
		}
	}

	table[curChar] += curCharFreq;
	//cout << curChar << " " << table[curChar] << endl;

	for (int i = 1; i < 256; i++) {
		table[i] += table[i - 1];
		//cout << i << " " << table[i] << endl;
	}

}

int main()
{
	string s;
	long Q;
	long k;
	long table[256] = { 0 };
	cin >> s;
	cin >> Q;

	preProcessString(s, table);

	for (int i = 0; i < Q; i++) {
		cin >> k;
		int j;
		//cout << k << endl;
		for (j = 1; j < 256 && table[j] < k; j++) {


		}

		if (j >= 256) {
			cout << -1;
		}
		else {
			cout << (char)j;
		}

		cout << endl;
	}
	return 0;
}

System.out.println("11");
System.out.println("abcde");
System.out.println("ab");
System.out.println("aaa");
System.out.println("a");
System.out.println("aaaaaa");
System.out.println("cccvvvvtvvvvvccc");
System.out.println("33333333333333");
System.out.println("AAABBBAAA");
System.out.println("BEEEB");
System.out.println("beeeb");
System.out.println("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

