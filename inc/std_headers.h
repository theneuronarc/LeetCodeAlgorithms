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
#include "min_heap.h"


using namespace std;

#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

template<typename T>
void printList(T& lst) {
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
}