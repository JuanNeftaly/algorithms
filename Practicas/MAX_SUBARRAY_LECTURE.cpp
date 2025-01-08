#include <iostream>
#include <cmath>
#include <climits> // calcula valores extremos en la maquina
using namespace std;

// funciones
void MAX_CROSS_SUBARRAY(int *A, int low, int mid, int high, int *R)
{
    int pos_left, pos_right;

    int sum = 0;
    int max_left = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > max_left)
        {
            max_left = sum;
            pos_left = i;
        }
    }

    sum = 0;
    int max_right = INT_MIN;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += A[j];
        if (sum > max_right)
        {
            max_right = sum;
            pos_right = j;
        }
    }

    R[0] = pos_left;
    R[1] = pos_right;
    R[2] = max_left + max_left;
}

void MAX_SUBARRAY(int *A, int low, int high, int *R)
{
    // escribir condicion de paro
    if (low == high)
    {
        R[0] = low;
        R[1] = high;
        R[2] = A[low]; // acceder a low o high porque son iguales
    }
    else
    {
        // partirlo a la mitad
        int mid = floor((low + high) / 2);

        // volver a partir
        int left[3];                     // arreglito que guarda la respuesta
        MAX_SUBARRAY(A, low, mid, left); // envia la izquierda

        int right[3];                          // guarda la respuesta
        MAX_SUBARRAY(A, mid + 1, high, right); // envia la derecha

        int cross[3];                                 // guarda el que cruza la frontera
        MAX_CROSS_SUBARRAY(A, low, mid, high, cross); // funcion que calcula la frontera

        if (left[2] >= right[2] && left[2] >= cross[2]) // aqui gana left
        {
            R[0] = left[0];
            R[1] = left[1];
            R[2] = left[2];
        }
        else
        {
            if (right[2] >= left[2] && right[2] >= cross[2]) // aqui gana right
            {
                R[0] = right[0];
                R[1] = right[1];
                R[2] = right[2];
            }
            else // aqui gana cross
            {
                R[0] = cross[0];
                R[1] = cross[1];
                R[2] = cross[2];
            }
        }
    }
}

int main(void)
{
    int A[8] = {-2, -3, 4, -1, -2, 1, 5, -3};

    int answer[3]; // arreglo para los 3 datos respuesta

    MAX_SUBARRAY(A, 0, 7, answer); // eficiencia de esta linea es la de la funcion

    cout << "La suma maxima es: " << answer[2] << " y ocurre en el subarreglo [" << answer[0] << "," << answer[3] << "]" << endl;

    return 0;
}