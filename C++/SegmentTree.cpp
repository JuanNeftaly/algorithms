#include <iostream>
using namespace std;

// construir segment tree
void build(int a[], int t[], int vortex, int leftL, int rightL) {
	// empty
	if (leftL == rightL) {
		t[vortex] = a[leftL];
	} else {
		int tm = (leftL + rightL) / 2;	// find mid
		// llamadas recursivas
		build(a, t, vortex * 2, leftL, tm);
		build(a, t, vortex * 2 + 1, tm + 1, rightL);

		t[vortex] = t[vortex * 2] + t[vortex * 2 + 1];
	}
}

// sumar [intervalos]

int main() {
	int A[] = {1, 3, -2, 8, -7};

	cout << A[1] << "\n";

	return 0;
}