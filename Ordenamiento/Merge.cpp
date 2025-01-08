#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	cout << "Arreglo ordenado" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;  // tamanio sub arr izquierdo
	int n2 = right - mid;	  // tamanio sub arr derecho

	int* L = new int[n1];  // crear sub arr izquierdo
	int* R = new int[n2];  // crear sub arr derecho

	// copiar datos a los sub arr
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	// mezclar sub arr

	int i = 0;     // indice sub arr izquierdo
	int j = 0;     // indice sub arr derecho
	int k = left;  // indice sub arr combinado

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// copiar datos en sub arr izquierdo
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// copiar datos en sub arr derecho
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	// limpiar memoria
	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int left, int right) {
	// base case
	if (left < right) {
		int mid = left + (right - left) / 2;  // mid point

		// ordenar primera y segunda mitad
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// mezclar mitades ordenadas
		merge(arr, left, mid, right);
	}
}

int main() {
	int A[] = {2, 4, 5, 7, 10, 1};
	int n = sizeof(A) / sizeof(A[0]);
	mergeSort(A, 0, n - 1);
	printArray(A, n);
}