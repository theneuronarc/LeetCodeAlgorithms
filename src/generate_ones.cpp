void generate(int n) {
	int rem = 1;
	cout << "1";
	while (rem) {
		rem *= 10;
		rem += 1;
		rem = rem%n;
		cout << "1";
	}
}