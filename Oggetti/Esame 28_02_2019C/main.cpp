#include <iostream>
#include <cstdlib>
#include <math.h>
#define DIM 5
using namespace std;
class A
{
private:
    char *base;
    short len;

public:
    A(short m)
    {
        len = m;
        base = new char[len];
        for (short i = 0; i < m; i++)
        {
            base[i] = (char)(rand() % ('z' - 'a' + 1)) + 'a';
        }
        //double n = (double)rand() / RAND_MAX;  genera numero compresi tra 0 e 1
    }
    virtual string extract(short x) = 0; //questo è un metodo virtuale puro, la classe diventa astratta e non sarà possibile fare istanze della classe
    short getLen()
    {
        return len;
    }
    virtual ostream &put(ostream &s) const
    {
        //overriding put in B e C
        s << "[";
        for (int i = 0; i < len; i++)
        {
            s << base[i] << " ";
        }
        s << "]";
        return s;
    }

protected:
    char get(short i)
    {
        return base[i % len];
    }
};
ostream &operator<<(ostream &s, const A &a)
{
    return a.put(s);
}
class B : public A
{
private:
    string str;
    double k;

public:
    B(short m, double p) : A(m), k(p)
    { //A(m) chiama il costruttore di A
        for (short i = 0; i < getLen(); i++)
        {
            switch (get(i))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                str += get(i);
                break;

            default:
                break;
            }
        }
    }
    double foo(short s)
    {
        return sin(k + s) / log(s + 1);
    }
    string extract(short x)
    {
        string ret;
        for (short i = 0; i < x; i++)
        {
            ret += get(rand() % getLen());
        }
        return ret;
    }
    ostream &put(ostream &s) const
    {
        //overriding put in B e C
        A::put(s); //invia allo stream i dati contenuti nell'array base
        s << "str=" << str;
        return s;
    }
};
class C : public A
{
private:
    int y;

public:
    C(short n, int k) : A(n), y(k)
    {
    }
    string extract(short x)
    {
        string str;
        short counter = 0;
        for (short i = 0; i < getLen() && counter < x; i++)
        {
            switch (get(i))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                //str += get(i); vocali
                break;

            default:
                //consonanti
                str += get(i);
                counter++;
                break;
            }
        }
        return str;
    }
    double g(short w)
    {
        return sin(w + y);
    }
    ostream &put(ostream &s) const
    {
        //overriding put in B e C
        A::put(s); //invia allo stream i dati contenuti nell'array base
        s << "y=" << y;
        return s;
    }
};
int main()
{
    srand(5);
    A *vett[DIM];

    for (int i = 0; i < DIM; i++)
    {
        short n = 10 + rand() % 10;
        switch (rand() % 2)
        {
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
        }
    }
    //inizio punto 1
    for (short i = 0; i < DIM; i++)
    {
        cout << *vett[i] << ", extract (3)=" << vett[i]->extract(3) << endl;
    }
    //fine punto 1
}