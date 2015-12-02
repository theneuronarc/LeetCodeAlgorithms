/*
https://leetcode.com/problems/powx-n/

Implement pow(x, n).
*/

class Power {
public:
	double table[32] = { 0.0 };
	bool tableMap[32] = { false };

	double myPowRecurse(double x, int n) {
		double result = 1.0;
		if (tableMap[n]) {
			return table[n];
		}

		result = myPowRecurse(x, n / 2);
		table[n] = result * result;
		if (n % 2) {
			table[n] *= x;
		}
		tableMap[n] = true;
		
		return table[n];
	}
 
	double myPow(double x, int n) {
		return myPowRecurse(x, n);
	}
};

void powerMain() {
	Power obj;
	obj.myPow(8.88023, 3);
}