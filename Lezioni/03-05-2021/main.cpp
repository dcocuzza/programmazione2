#include "ArrayDinamico.cpp"
#include "ArrayDinamico.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{

	ArrayDinamico a1(6);
	cout << a1 << endl;

	double d[3] = {1.1, 2.2, 3.3};
	ArrayDinamico a2(d, 3);
	cout << a2 << endl;

	ArrayDinamico a3(a2);
	a2[1] = 0.0;
	cout << a3 << endl;
	cout << a2 << endl;

	try
	{
		a2[5] = 10;
	}
	catch (exception &err)
	{

		cout << "Errore catturato:\n\t" << err.what() << endl;
	}

	cout << "Inserisco 15 elementi:" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << a2;
		a2.insert(i + 0.1);
	}
	cout << a2;

	cout << "Elimino 15 elementi:" << endl;
	for (int i = 0; i < 15; i++)
	{
		cout << a2;
		a2.remove(0);
	}
	cout << a2;

	return 0;
}