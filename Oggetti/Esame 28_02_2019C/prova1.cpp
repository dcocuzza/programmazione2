#include <iostream>
#include <cstdlib>
#include <math.h>
#include <typeinfo>
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
        for (short i = 0; i < len; i++)
        {
            base[i] = (char)(rand() % ('z' - 'a' + 1)) + 'a';
        }
    }
    virtual string extract(short x) = 0;
    void stampa()
    {
        for (short i = 0; i < len; i++)
        {
            cout << base[i] << " ";
        }
        cout << endl;
    }
    short getLen()
    {
        return len;
    }
    virtual ostream &put(ostream &s) const
    {
        s << "[";
        for (short i = 0; i < len; i++)
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
class B : public A
{
private:
    string str;
    double k;

public:
    B(short m, double p) : A(m)
    {
        k = p;
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
        string s;
        for (short i = 0; i < x; i++)
        {
            s += get(rand() & getLen());
        }
        return s;
    }
    ostream &put(ostream &s) const
    {
        A::put(s);
        s << "str=" << str;
        s << ", k=" << k;
        return s;
    }
};
class C : public A
{
private:
    int y;

public:
    C(short n, int k) : A(n)
    {
        y = k;
    }
    string extract(short x)
    {
        int cont = 0;
        string s;
        for (short i = 0; i < getLen() && cont < x; i++)
        {
            switch (get(i))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                s += get(i);
                cont++;
                break;
            }
        }
        return s;
    }
    int getY()
    {
        return y;
    }
    double g(short w)
    {
        return sin(w + y);
    }
    ostream &put(ostream &s) const
    {
        A::put(s);
        s << "y=" << y;
        return s;
    }
    C operator++(int)
    {
        C aux = *this;
        aux.y++;
        return aux;
    }
};
ostream &operator<<(ostream &s, const A &a)
{
    return a.put(s);
}
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
    //overloading 41)C: base=[y t c a b z e b m d n t z d ], y=2, extract(3)=ytc
    //overloading 42)B: base=[k v s e p n v o m u l g ], str=eou, k=0.774659, extract(3)=vue
    for (short i = 0; i < DIM; i++)
    {
        cout << *vett[i] << ", extract(3)=" << vett[i]->extract(3) << endl;
    }
    //2. si calcoli una singola media di tutti i valori foo(5) e g(5) per tutti i gli oggetti di tipo B e C.
    double somma = 0, media, avg = 0;
    for (short i = 0; i < DIM; i++)
    {
        //typeid
        if (typeid(*vett[i]) == typeid(B))
        {
            somma += ((B *)vett[i])->foo(5);
        }
        else if (typeid(*vett[i]) == typeid(C))
        {
            somma += ((C *)vett[i])->g(5);
        }
        //dynamic cast
        B *ptr = dynamic_cast<B *>(vett[i]);
        if (ptr != nullptr)
        {
            avg += ptr->foo(5);
        }
        else
        {
            C *ptr1 = dynamic_cast<C *>(vett[i]);
            if (ptr1)
            {
                avg += ptr1->g(5);
            }
        }
    }
    media = somma / (double)(DIM);
    avg = avg / (double)(DIM);
    cout << "media typeid = " << media << endl;
    cout << "media dynamic cast = " << media << endl;

    //3. si implementi l'overloading dello operatore membro postfisso \++" per la classe C e lo si utilizzi nel main.
    C obj = *((C *)vett[1]);
    cout << obj.getY() << endl;
    obj = obj++;
    cout << obj.getY() << endl;

    return 0;
}