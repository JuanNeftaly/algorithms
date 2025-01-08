#include <iostream>
using namespace std;

int main() {
	// variables
	int A[5] = {3, -8, -16, 30, 32};
	int n = 5;

	int max_sum = A[0];
	int current_sum = 0;
	int inicio = 0, fin = 0, aux_start = 0;
	int i = 0;

	while (i < n) {
		current_sum += A[i];

		if (current_sum > max_sum) {
			max_sum = current_sum;
			inicio = aux_start;
			fin = i;
		}

		if (current_sum < 0) {
			current_sum = 0;
			aux_start = i + 1;
		}

		i++;
	}

	// mostrar los que generan el valor maximo
	cout << "El intervalo con la suma maxima es: ";
	for (int j = inicio; j <= fin; j++) {
		cout << A[j] << " - ";
	}
	cout << endl;
	cout << "La suma maxima es: " << max_sum;

	return 0;
}