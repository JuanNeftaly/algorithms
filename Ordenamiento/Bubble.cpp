#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	cout << "Arreglo ordenado" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);

	bubbleSort(A, n);
	printArray(A, n);
}
