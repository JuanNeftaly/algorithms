#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	cout << "Arreglo ordenado" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;

		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		// swap
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);

	selectionSort(A, n);
	printArray(A, n);
}