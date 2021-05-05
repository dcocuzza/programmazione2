#include <iostream>
using namespace std;
class Base
{
public:
    void meth1()
    {
    }

protected:
    void meth2()
    {
    }
};
class Derived : public Base
{
public:
    void meth3()
    {
        meth2();
    }
};
class DerivedDerived : public Derived
{
public:
    void meth4()
    {
        meth2();
    }
};
int main()
{
    Derived d1;
    d1.meth1();
    d1.meth3();
    //d1.meth2(); non si può chiamare perché protected, può essere invocato all'interno di Derived ma non fuori
    DerivedDerived d2;
    d2.meth4();

    return 0;
}