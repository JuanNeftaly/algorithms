#include <iostream>
using namespace std;

int main() {
	// arreglo
	int A[] = {10, 1, 9, 7, 6, 5, 3, 1};

	// variables para recorrer
	int i, j, min = 0, aux = 0;
	int size = sizeof(A) / sizeof(A[0]);

	cout << "Arretglo original: ";
	for (i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	// recorrer el arreglo
	for (i = 0; i < size; i++) {
		min = i;  // convertimos el primero en el min
		for (j = i + 1; j < size; j++) {
			if (A[j] < A[min]) {
				min = j;  // convertirmos el encontrado en el
					  // nuevo min
			}
		}

		// intercambiar valores
		aux = A[i];	// aux guarda el valor del primero
		A[i] = A[min];	// el primer valor toma el valor del minimo
		A[min] = aux;	// el minimo encontrado toma el valor de aux
	}

	// Arreglo ordenado
	cout << "Arreglo ordenado: ";
	for (i = 0; i < size; i++) {
		cout << A[i] << " ";
	}

	return 0;
}