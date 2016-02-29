/*
https://leetcode.com/problems/count-primes/
*/

bool isPrime(int n) {
	for (int i = 2; (i*i) <= n; i++) {
		if (n % i)
			continue;
		else
			return false;
	}
	return true;
}


int countPrimes(int n) {
	int* notPrime = (int*)calloc(n, sizeof(int));
	int count = 0;
	for (int i = 2; i*i < n; i++) {
		if (notPrime[i]) continue;

		for (int j = i*i; j < n; j += i) {
			notPrime[j] = true;
		}
	}

	for (int i = 2; i < n; i++) {
		if (!notPrime[i]) count++;
	}

	return count;
}
