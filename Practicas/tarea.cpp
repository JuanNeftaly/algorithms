#include <iostream>
using namespace std;

int main() {
	// variables
	int A[5] = {3, -8, -16, 30, 32};
	int n = 5;

	int max_sum = A[0];
	int inicio = 0, fin = 0;

	int i = 0;
	while (i < n) {
		int j = i;
		while (j < n) {
			int current_sum = 0;

			// Usando un for para calcular la suma del subarreglo
			for (int k = i; k <= j; k++) {
				current_sum += A[k];
			}

			if (current_sum > max_sum) {
				max_sum = current_sum;
				inicio = i;
				fin = j;
			}
			j++;
		}
		i++;
	}

	// Mostrar los elementos que generan el valor máximo
	cout << "El intervalo con la suma maxima es: ";
	for (int j = inicio; j <= fin; j++) {
		cout << " [" << A[j] << "] ";
	}
	cout << endl;
	cout << "La suma maxima es: " << max_sum;

	return 0;
}