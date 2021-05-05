#include <iostream>
#define DIM 10
using namespace std;
int somma_puntatori(int *a[], int n)
{
    int somma = 0;
    for (int i = 0; i < n; i++)
    {
        somma += **(a + i);
    }
    return somma;
}
int chiamata(int *a[], int n)
{
    int (*ptn)(int *a[], int n);
    ptn = somma_puntatori;
    return ptn(a, n);
}
int main()
{
    int a[DIM] = {2, 3, 5, 7, 7, 8, 9, 10, 5, 0};
    int *b[DIM];
    for (int i = 0; i < DIM; i++)
    {
        b[i] = (a + i);
    }
    cout << somma_puntatori(b, DIM) << endl;
    cout << chiamata(b, DIM) << endl;
    return 0;
}
