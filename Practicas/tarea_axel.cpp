#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A[] = {3, -8, -16, 30, 32};
    int n = sizeof(A) / sizeof(A[0]);

    int max_current = A[0];
    int max_global = A[0];
    int sub_array = A[0];

    for (int i = 0; i < n; i++)
    {
        max_current = max(A[i], max_current + A[i]);
        sub_array = {max(A[i], 0)};

        if (max_current > max_global)
        {
            max_global = max_current;
        }
    }

    cout << "La suma maxima es: " << max_global << "\n";
    cout << "El subConjunto es: [" << sub_array << "]";

    return 0;
}
