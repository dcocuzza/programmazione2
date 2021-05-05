#include <iostream>

using namespace std;

double inversi(int k)
{
    if(k!=0) return 1.0/k;
    else return 0;
}

double quadrati(int k)
{
    return (double)k*k;
}

double somma(int n,double(*f)(int k))
{
    double s=0;
    for(int i=1; i<=n; i++) s+=f(i);

    return s;
}

int main()
{
    cout << "La somma degli inversi dei primi 5 numeri e'    "<<somma(5,inversi) << endl;

    cout << "\nLa somma dei quadrati dei primi 4 numeri e'    "<<somma(4,quadrati) << endl;

    return 0;
}
