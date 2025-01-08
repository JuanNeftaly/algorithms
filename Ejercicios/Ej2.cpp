#include <iostream>

using namespace std;

int main()
{
    int m, n, p;

    cout << "Filas primera matriz (m)";
    cin >> m;

    cout << "Columnas primera (n) filas segunda (n)";
    cin >> n;

    cout << "Columnas segunda matriz (p)";
    cin >> p;

    int A[10][10], B[10][10], C[10][10];

    // leer primera matriz
    cout << "elementos primera matriz " << m << " x " << n << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    // leer segunda matriz
    cout << "elementos segunda matriz " << n << " x " << p << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            cin >> B[i][j];
        }
    }

    // tercera matriz a 0
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            C[i][j] = 0;
        }
    }

    // multiplicacion de matrices
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // imprimir resultado
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            cout << C[i][j] << endl;
        }
        cout << endl;
    }
}