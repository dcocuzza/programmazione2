#include <iostream>
#include <math.h>
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
        for (int i = 0; i < len; i++)
            base[i] = (char)(rand() % ('z' - 'a' + 1)) + 'a';
    }
    virtual string extract(short x) = 0;

    short getLen()
    {
        return len;
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
    B(short m, double p) : A(m), k(p)
    {
        for (int i = 0; i < getLen(); i++)
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
    string extract(short x)
    {
        string scal;
        for (int i = 0; i < x; i++)
        {
            scal += get(rand() % getLen());
        }
        return scal;
    }
    double foo(short s)
    {
        return sin(k + s) / log(s + 1);
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
        string ret;
        for (int i = 0; i < x && i < getLen(); i++)
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
                ret += get(i);
                break;
            }
        }
        return ret;
    }
};
int main()
{
    B b{4, 5.2};
    cout << b.extract(5) << endl;
    return 0;
}