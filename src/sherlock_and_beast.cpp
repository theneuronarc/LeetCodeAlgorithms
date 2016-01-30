#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int threes;
	int fives;
	bool invalid;
}Combination;

void init(Combination* table) {
	table[0].invalid = true;
	table[1].invalid = true;
	table[2].invalid = true;
	table[4].invalid = true;

	table[3].invalid = false;
	table[3].threes = 0;
	table[3].fives = 1;

	table[5].invalid = false;
	table[5].threes = 1;
	table[5].fives = 0;
}

void createTableEntry(Combination* table, int n) {
	table[n].threes = 0;
	table[n].fives = 0;
	table[n].invalid = true;
	for (int i = 1; i <= n / 2; i++) {
		if (table[i].invalid || table[n - i].invalid)
			continue;

		if (table[i].fives + table[n - i].fives > table[n].fives) {
			table[n].fives = table[i].fives + table[n - i].fives;
			table[n].threes = table[i].threes + table[n - i].threes;
			table[n].invalid = false;
		}
	}
}

Combination genSeq(int n) {
	Combination* table = new Combination[n + 1];
	Combination res;
	init(table);
	for (int i = 6; i <= n; i++) {
		createTableEntry(table, i);
	}
	cout << table[n].fives << " " << table[n].threes << endl;
	res = table[n];
	delete[] table;
	return res;
}


Combination genSeqX(int n) {
	Combination res;
	int t = n % 3;
	int f = n / 3;
	res.invalid = true;

	if (t == 1 && f >= 3) {
		f -= 3;
		t = 2;
		res.fives = f;
		res.threes = t;
		res.invalid = false;
	}
	else if(t == 2 && f >= 3) {
		f -= 1;
		t = 1;
		res.fives = f;
		res.threes = t;
		res.invalid = false;
	}
	else if (t == 0){
		res.fives = f;
		res.threes = t;
		res.invalid = false;
	}
	return res;
}

int xmain() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		Combination res;
		cin >> n;
		res = genSeq(n);

		if (res.invalid)
			cout << "-1";
		else {
			for (int i = 0; i < res.fives; i++) {
				cout << "555";
			}
			for (int i = 0; i < res.threes; i++) {
				cout << "33333";
			}
		}

		cout << endl;
	}
	return 0;
}