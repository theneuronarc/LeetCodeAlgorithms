#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <functional>
#include <algorithm>
#include <queue>
#include <limits>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include "min_heap.h"


using namespace std;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define swap(a,b) {int tmp = a;a = b;b = tmp; }

template<typename T>
void printList(T& lst) {
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
}