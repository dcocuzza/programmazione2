#include <iostream>
using namespace std;
template <typename T>
class Contenitore
{
    T dati[50];
    int elementi;

public:
    Contenitore() : elementi(0) {}
    void inserire(T el)
    {
        if (elementi >= 50)
            return;
        dati[elementi++] = el;
    };
    T estrarre()
    {
        return dati[--elementi];
    }
    int numero() { return elementi; }
    bool vuoto()
    {
        return (elementi == 0);
    }
};
int main()
{
    Contenitore<int> c1;
    c1.inserire(5);
    c1.inserire(7);
    cout << c1.estrarre() << endl;
    cout << c1.estrarre() << endl;
    cout << "Numero elementi: " << c1.numero() << endl;

    return 0;
}