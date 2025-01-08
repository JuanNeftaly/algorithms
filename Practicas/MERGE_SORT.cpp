#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

void show_array(int *A, int n) {
	cout << "[ ";
	for (int i = 0; i < n; i++) {
		cout << A[i];
	}
	cout << " ]";
}

void MERGE(int *A, int p, int q, int r) {
	int i, j;

	int nl = q - p + 1;
	int nr = r - q;	 // r - (q + 1) + 1

	// necesito las dos filas
	int L[nl + 1];	// si una se vacia primero, no tengo para comparar
	int R[nr + 1];

	// llenar las pilas
	for (i = 0; i <= nl; i++) L[i] = A[p + i];

	L[nl] = INT_MAX;

	for (j = 0; j <= nr; j++) R[j] = A[q + 1 + j];

	R[nr] = INT_MAX;

	i = j = 0;
	// comparar para ordenar
	for (int k = p; k <= r; k++) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void MERGE_SORT(int *A, int p, int r) {
	// caso base
	if (p < r) {
		// mid
		int q = (p + r) / 2;

		// mandar mitades
		MERGE_SORT(A, p, q);
		MERGE_SORT(A, q + 1, r);

		MERGE(A, p, q, r);
	}
}

int main(void) {
	int A[] = {8, 4, 6, 9, 5, 3, 1};

	show_array(A, 7);

	MERGE_SORT(A, 0, 6);

	show_array(A, 7);

	return 0;
}