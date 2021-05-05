#include "ArrayDinamico.h"
#include "ArrayDinamico.cpp"
int main()
{
    ArrayDinamico a{6};
    cout << a << endl;

    ArrayDinamico b{a};
    cout << b << endl;

    double arr[3] = {3.14, 2.5, 0.15};
    ArrayDinamico c{arr, 3};
    cout << c << endl;

    a.insert(10);
    cout << a << endl;

    a.insert(15);
    a.insert(15);
    cout << a << endl;
    a.remove(2);
    a.remove(3);
    cout << a;

    try
    {
        cout << "Stampa con overloading operatore: " << a[5] << endl;
    }
    catch (exception &err)
    {
        cout << "Errore: " << err.what() << endl;
    }

    a[5] = 4;

    try
    {
        cout << "Stampa con overloading operatore: " << a[5] << endl;
    }
    catch (exception &err)
    {
        cout << "Errore: " << err.what() << endl;
    }
    return 0;
}