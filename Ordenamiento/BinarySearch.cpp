#include <iostream>
using namespace std;

void printResult(int result) {
	if (result != -1)
		cout << "Elemento encontrado en el index: " << result << endl;
	else
		cout << "Elemento no encontrado en el arreglo." << endl;
}

int binarySearch(int arr[], int L, int R, int target) {
	while (L <= R) {
		int mid = L + (R - L) / 2;

		// si el elemento esta en el medio
		if (arr[mid] == target) {
			return mid;
		}

		// si target es mayor, ignoramos izquierda
		if (arr[mid] < target) {
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	return -1;
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);
	int target = 10;

	int result = binarySearch(A, 0, n - 1, target);

	printResult(result);
}
