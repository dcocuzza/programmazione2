#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int fattoriale(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fattoriale(n - 1);
}
int n_fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n_fibonacci(n - 1) + n_fibonacci(n - 2);
}
void carica_vettore2(int *v, int n, int i)
{
    if (i >= n)
        return;
    else
    {
        cin >> v[i];
        carica_vettore2(v, n, i + 1);
    }
}
void stampa_vettore2(int *v, int n, int i)
{
    if (i >= n)
        return;
    else
    {
        cout << v[i] << " ";
        stampa_vettore2(v, n, i + 1);
    }
}
int somma_array(int *v, int n)
{
    if (n <= 0)
        return 0;
    else
        return v[n - 1] + somma_array(v, n - 1);
}
int prod_array(int *v, int n)
{
    if (n <= 0)
        return 1;
    else
        return v[n - 1] * prod_array(v, n - 1);
}
double media_array(int *v, int n, bool s)
{
    if (n <= 0)
        return 0;
    else if (s == 1)
        return (v[n - 1] + media_array(v, n - 1, 0)) / n;
    else if (s == 0)
        return v[n - 1] + media_array(v, n - 1, 0);
}
int max_array(int *v, int n, int max)
{
    if (n <= 1)
        return max;
    else if (v[n - 1] > max)
        return max_array(v, n - 1, v[n - 1]);
    else
        return max_array(v, n - 1, max);
}
int min_array(int *v, int n, int min)
{
    if (n <= 1)
        return min;
    else if (v[n - 1] < min)
        return min_array(v, n - 1, v[n - 1]);
    else
        return min_array(v, n - 1, min);
}
bool ricerca_elemento(int *v, int n, int x)
{
    if (n <= 0)
        return false;
    else if (v[n - 1] == x)
        return true;
    else
        return ricerca_elemento(v, n - 1, x);
}
int cont_occorrenze(int *v, int n, int x)
{
    if (n <= 0)
        return 0;
    else if (v[n - 1] == x)
        return 1 + cont_occorrenze(v, n - 1, x);
    else
        return cont_occorrenze(v, n - 1, x);
}
int scalar_prod(int *a, int *b, int n)
{
    if (n <= 0)
        return 0;
    else
        return ((a[n - 1] * b[n - 1]) + scalar_prod(a, b, n - 1));
}
bool is_primo(int n, int i)
{
    if (i > sqrt(n))
        return true;
    else if (n % i == 0)
        return false;
    else
        return is_primo(n, i + 1);
}
int main()
{
    int n;
    cout << "Inserisci un numero naturale \n";
    cin >> n;
    int v[n];
    cout << fattoriale(n) << endl;
    cout << n_fibonacci(n) << endl;
    cout << "Inseriesci " << n << " elementi\n";
    carica_vettore2(v, n, 0);
    stampa_vettore2(v, n, 0);
    cout << endl
         << "Somma elementi array: " << somma_array(v, n) << endl;
    cout << endl
         << "Prodotto elementi array: " << prod_array(v, n) << endl;
    cout << endl
         << "Media elementi array: " << media_array(v, n, 1) << endl;
    cout << endl
         << "Il massimo è: " << max_array(v, n, v[0]) << endl;
    cout << endl
         << "Il minimo è: " << min_array(v, n, v[0]) << endl;
    cout << endl
         << "L'elemento: " << 5 << " È presente: " << ricerca_elemento(v, n, 5) << endl;
    cout << endl
         << "L'elemento: " << 5 << " È presente: " << cont_occorrenze(v, n, 5) << " volte" << endl;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 10;
    }
    stampa_vettore2(b, n, 0);
    cout << endl
         << "Il prodotto scalare è: " << scalar_prod(v, b, n) << endl;

    cout << endl
         << "Il numero: " << n << " è primo: " << is_primo(n, 2) << endl;

    return 0;
}