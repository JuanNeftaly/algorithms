#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "hasta cuanto el facto mi rey?" << "\n";
	cin >> n;

	int memo[n];
	memo[0] = 1;
	memo[1] = 1;

	for (int i = 2; i <= n; i++) {
		memo[i] = i * memo[i - 1];
	}

	for (int i = 0; i <= n; i++) {
		cout << memo[i] << " - ";
	}
}