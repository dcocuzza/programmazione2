#include <iostream>
using namespace std;
template <typename T, typename U>
class MyPair
{
    T a;
    U b;

public:
    MyPair(T first, U second) : a(first), b(second) {}
    T getFirst() { return a; }
    U getSecond() { return b; }
    void stampa();
};
template <typename T, typename U>
void MyPair<T, U>::stampa()
{
    cout << "(" << a << ", " << b << ")" << endl;
}
template <int N = 8>
class ClasseArray
{
    int an_array[N];

public:
    ClasseArray()
    {
        for (int i = 0; i < N; i++)
            an_array[i] = 0;
    } // setto tutti a zero
    int getSize() { return N; }
    int *getArray() { return an_array; }
    void printAll()
    {
        for (int i = 0; i < N; i++)
            cout << i << ")\t" << an_array[i] << endl;
    }
};
template <typename T, int N = 5>
class ClasseArrayTipo
{
    T an_array[N];

public:
    int getSize() { return N; }
    T *getArray() { return an_array; }
    void printAll()
    {
        cout << "ClasseArrayTipo::printAll()" << endl;
        for (int i = 0; i < N; i++)
            cout << i << ")\t" << an_array[i] << endl;
    }
};
int main()
{
    MyPair<char, int> paio{'c', 5};
    cout << paio.getFirst() << endl;
    paio.stampa();

    ClasseArray<> ar;
    ar.printAll();

    int *ls = ar.getArray();
    for (int i = 0; i < ar.getSize(); i++)
        cout << ls[i] << " ";
    cout << endl;

    ClasseArrayTipo<char> tipo;
    tipo.printAll();
    char *vet = tipo.getArray();
    for (int i = 0; i < tipo.getSize(); i++)
        vet[i] = 'a' + char(i);
    tipo.printAll();
    return 0;
}