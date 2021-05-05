#include "ArrayDinamico.h"
#include <iostream>
#include <stdexcept>
using namespace std;
ArrayDinamico::ArrayDinamico(int n)
{

	if (n <= 0)
	{
		cout << "Errore: size deve essere maggiore di zero" << endl;
		exit(1);
	}

	maxSize = n + BUF_SIZE;
	size = n;

	ptr = new double[maxSize];
	for (int i = 0; i < maxSize; i++)
		ptr[i] = 0.0;
}

ArrayDinamico::ArrayDinamico(const ArrayDinamico &a)
{
	maxSize = a.maxSize;
	size = a.size;
	ptr = new double[maxSize];
	for (int i = 0; i < maxSize; i++)
		ptr[i] = a.ptr[i];
}

ArrayDinamico::ArrayDinamico(const double a[], int n)
{
	maxSize = n + BUF_SIZE;
	size = n;
	ptr = new double[maxSize];
	for (int i = 0; i < n; i++)
		ptr[i] = a[i];
}

ArrayDinamico::~ArrayDinamico()
{
	delete[] ptr;
}

void ArrayDinamico::insert(double elem)
{
	//    [ 3, 3, 23, 11, 55, - - - - - ]
	//       0  1    2   3     4
	//    size = 5     maxSize = 10
	if (size == maxSize)
	{
		cout << endl
			 << "Estendo l'array..." << endl;
		maxSize += BUF_SIZE + 1;
		double *tmp = new double[maxSize];
		for (int i = 0; i < size; i++)
			tmp[i] = ptr[i];

		double *toDelete = ptr;
		ptr = tmp;
		delete[] toDelete;
	}

	ptr[size] = elem;
	size += 1;
}

void ArrayDinamico::remove(int idx)
{ // elimina ptr[idx]

	if (idx >= size || idx < 0)
	{
		cout << "Indice errato" << endl;
		exit(1);
	}
	// sovrascrivo l'elemento di indice idx con quelli successivi
	for (int i = idx; i < size - 1; i++)
		ptr[i] = ptr[i + 1];
	ptr[size] = 0.0;
	size -= 1;

	// [ 2, 3, 44, 2, 4, - - - - - ]
	// [ 2, 3, 2, 4, - - - - - - ]
	// [2, - - -- - - - - - - - - - - - -- -]
	// se spreco spazio... riduco l'array (fisico)
	if (size <= maxSize - 2 * BUF_SIZE)
	{
		cout << endl
			 << "Riduco l'array..." << endl;
		maxSize -= BUF_SIZE;

		double *tmp = new double[maxSize];
		for (int i = 0; i < size; i++)
			tmp[i] = ptr[i];

		double *toDelete = ptr;
		ptr = tmp;
		delete[] toDelete;
		cout << "Nuova dim. massima ---> " << maxSize << endl;
	}
}

double ArrayDinamico::operator[](int idx) const
{ // a[i] sola lettura
	// exception <- logic_error <- out_of_range
	if (idx < 0 || idx >= size)
	{
		throw out_of_range("ArrayDinamico::operator[] -> indice fuori dal range");
	}
	return ptr[idx];
}
double &ArrayDinamico::operator[](int idx)
{ // a[i] = x
	if (idx < 0 || idx >= size)
	{
		throw out_of_range("ArrayDinamico::operator[] -> indice fuori dal range");
	}
	return ptr[idx];
}

ostream &operator<<(ostream &out, const ArrayDinamico &a)
{
	// [ 3, 3, 2, 33, -  - - -  - ]
	out << "[ ";
	for (int i = 0; i < a.maxSize; i++)
	{
		if (i < a.size)
			out << a.ptr[i] << " ";
		else
			out << "- ";
	}
	out << "]" << endl;
	return out;
}
