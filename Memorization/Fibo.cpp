#include <iostream>
using namespace std;

int fibo(int n) {
	int memo[n];

	memo[0] = 1;
	memo[1] = 1;

	for (int i = 2; i < n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];

		cout << memo[i] << "\n";
	}
}

int main() {
	int n;
	cin >> n;

	fibo(n);
	return 0;
}