#include <iostream>
#define DIM 20
using namespace std;

void scambia(int &a, int &b)
{
	int aux = a; //variabile da tramite per lo scambio

	a = b;
	b = aux;
}

void Stampa1(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Stampa2(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
	cout << endl;
}

void Stampa3(int a[], int n)
{
	int *p = a;

	for (int i = 0; i < n; i++)
	{
		cout << *p << " ";
		p++;
	}
	cout << endl;
}

int main()
{
	int vettore[DIM] = {12, 3, 6, 5, 131, 7, 43, 89, 54, 34, 11, 21, 13, 4, 90, 15, 16, 71, 19, 31};

	cout << "\nVettore iniziale    ";
	Stampa1(vettore, DIM);

	cout << "\nSecondo Vettore     ";
	Stampa2(vettore, DIM);

	cout << "\nTerzo Vettore       ";
	Stampa3(vettore, DIM);
}
