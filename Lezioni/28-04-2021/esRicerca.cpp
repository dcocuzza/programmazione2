#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <typename T>
int ricerca(T dato, T *v, int n)
{
    for (int i = 0; i < n; i++)
        if (dato == v[i])
            return i;
    return -1;
}

class Punto
{
    int x, y;

public:
    Punto() : x(0), y(0) {}
    Punto(int _x, int _y) : x(_x), y(_y) {}
    void stampa()
    {
        cout << "x: " << x << " ";
        cout << "y: " << y << endl;
    }
    void setPunto(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator==(const Punto &p) const
    {
        if (x == p.x && y == p.y)
            return true;
        return false;
    }
};
int main()
{
    srand(time(NULL));
    const int n = 5;
    int v_int[n];
    char v_char[n];
    for (int i = 0; i < n; i++)
    {
        v_int[i] = rand() % 10;
        v_char[i] = (char)((rand() % (122 - 97 + 1)) + 97);
    }
    cout << "Array(int): ";
    for (int i = 0; i < n; i++)
        cout << v_int[i] << " ";
    cout << endl;

    cout << "Array(char): ";
    for (int i = 0; i < n; i++)
        cout << v_char[i] << " ";
    cout << endl;

    int x = 5;
    cout << "L'elemento: " << x << " è presente: " << ricerca<int>(x, v_int, n) << endl;
    char c = 'a';
    cout << "L'elemento: " << c << " è presente: " << ricerca<char>(c, v_char, n) << endl;
    cout << endl;
    Punto vett_punto[n];
    Punto p(5, 10);
    for (int i = 0; i < n; i++)
    {
        vett_punto[i].setPunto(rand() & 10, rand() % 10);
    }
    for (int i = 0; i < n; i++)
        vett_punto[i].stampa();

    vett_punto[0].setPunto(5, 10);
    cout << "L'elemento: ";
    p.stampa();
    cout << " è presente: " << ricerca<Punto>(p, vett_punto, n) << endl;
    return 0;
}