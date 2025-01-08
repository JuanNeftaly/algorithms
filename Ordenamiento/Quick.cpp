#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	cout << "Arreglo ordenado" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int arr[], int i, int j) {
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

int partition(int arr[], int L, int R) {
	int x = arr[R];
	int i = L - 1;

	for (int j = L; j < R; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, R);
	return i + 1;
}

void quickSort(int arr[], int L, int R) {
	if (L < R) {
		int p = partition(arr, L, R);

		quickSort(arr, 1, p - 1);
		quickSort(arr, p + 1, R);
	}
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);

	quickSort(A, 0, n - 1);
	printArray(A, n);
}