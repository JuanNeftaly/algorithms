#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	cout << "Arreglo ordenado" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);

	insertionSort(A, n);
	printArray(A, n);
}