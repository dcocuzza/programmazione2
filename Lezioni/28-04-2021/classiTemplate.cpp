
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
    ClasseArray() : an_array({0}) {} // setto tutti a zero
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

    MyPair<int, char> p(10, 'X');
    MyPair<int, int> p2(10, 5);
    p.stampa();
    p2.stampa();

    cout << "ClasseArray<>" << endl;
    ClasseArray<> def;
    def.printAll();
    cout << endl;

    ClasseArray<5> a;
    a.printAll();
    cout << endl;
    int *ls = a.getArray();
    for (int i = 0; i < a.getSize(); i++)
        ls[i] = i * i * i;
    a.printAll();

    cout << endl;

    ClasseArrayTipo<char, 5> ch_arr;
    char *ls_ch = ch_arr.getArray();
    for (int i = 0; i < ch_arr.getSize(); i++)
        ls_ch[i] = 'a' + char(i);

    ch_arr.printAll();

    return 0;
}
