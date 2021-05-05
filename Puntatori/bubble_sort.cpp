#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#define MAX 10

void stampa(int *a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << **(a + i) << "  , ";
    }
    cout << endl;
}
void stampaInt(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ,  ";
    }
    cout << endl;
}
void bubbleSort(int *a[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // i ci dice quante passate devo fare non da dove deve partire
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            if (*a[k] > *a[k + 1])
            {
                int *temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[MAX] = {2, 6, 55, 8, 99, 74, 22, 14, 0, 3};
    int *b[MAX];

    for (int i = 0; i < MAX; i++)
        b[i] = a + i;

    cout << "il mio array A e' :    ";
    stampaInt(a, MAX);

    cout << "\n il mio array B e' :   ";
    stampa(b, MAX);

    bubbleSort(b, MAX);

    cout << "\nil mio array A ordinato e' :    ";
    stampaInt(a, MAX);

    cout << "\nil mio array B ordinato e' :    ";
    stampa(b, MAX);

    return 0;
}
