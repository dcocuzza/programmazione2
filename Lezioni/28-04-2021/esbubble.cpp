#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void bubbleSort(T *a, int n)
{
    bool scambio;
    do
    {
        scambio = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                mySwap(a[i], a[i + 1]);
                scambio = true;
            }
        }

    } while (scambio);
}
class Rettangolo
{
    int b, h;
    int n;
    int *v_int;
    char *v_char;

public:
    Rettangolo()
    {
        n = 5;
        b = rand() % 100;
        h = rand() % 100;
        v_int = new int[n];
        v_char = new char[n];
    }
    Rettangolo(int n)
    {
        this->n = n;
        b = rand() % 100;
        h = rand() % 100;
        v_int = new int[n];
        v_char = new char[n];
    }
    void inserisci()
    {
        for (int i = 0; i < n; i++)
        {
            v_int[i] = rand() % 100;
            v_char[i] = (char)((rand() % (122 - 97 + 1)) + 97);
        }
    }
    void stampaInt()
    {
        cout << "Array(int): ";
        for (int i = 0; i < n; i++)
            cout << v_int[i] << " ";
        cout << endl;
    }
    void stampaChar()
    {
        cout << "Array(char): ";
        for (int i = 0; i < n; i++)
            cout << v_char[i] << " ";
        cout << endl;
    }
    void stampaBaseAltezza()
    {
        cout << "base: " << b << " ";
        cout << "altezza: " << h;
    }
    void ordina()
    {
        bubbleSort<int>(v_int, n);
        bubbleSort<char>(v_char, n);
    }
    bool operator>(const Rettangolo &r) const
    {
        return (b * h) > (r.b * r.h);
    }
};
int main()
{
    srand(time(NULL));
    Rettangolo r;
    r.inserisci();
    r.stampaInt();
    r.stampaChar();

    Rettangolo arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i].stampaBaseAltezza();
        cout << endl;
    }
    bubbleSort<Rettangolo>(arr, 4);
    r.ordina();
    cout << "Vettori ordinati\n";
    r.stampaInt();
    r.stampaChar();
    for (int i = 0; i < 4; i++)
    {
        arr[i].stampaBaseAltezza();
        cout << endl;
    }

    return 0;
}