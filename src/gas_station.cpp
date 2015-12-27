/*
https://leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

#include "std_headers.h"

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

	}
};

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int sum = 0;	
	int cur = 0;
	int start = 0, end = 0;
	int init = 1;

	for (int i = 0; i < gasSize; i++) {
		cost[i] = gas[i] - cost[i];
	}

	while (init || (cur != end  && sum >= 0)) {
		sum += cost[cur];
		if (sum < 0) {
			if (start <= cur && cur < gasSize - 1) {
				cur++;
				start = cur;				
				end = start;
				sum = 0;
				init = 1;
				continue;
			}
			else {
				return -1;
			}
		}

		cur++;
		cur = (cur >= gasSize ? 0 : cur);
	}

	return start;
}