#include <iostream>
using namespace std;
class B
{
public:
    virtual void f1(){};
    ~B() {} //se lo dichiaro virtuale verrà chiamato ancheil distruttore di D quando elimino b con delete
};

class D1 : public B
{
public:
    void f1() final;
};
void D1::f1() {}

class D2 : public D1
{
public:
    //void f1(); non si può fare l'overide di un metodo final
};
int main()
{
    D1 d;
    B *b = new B();
    b = &d;
    delete b; //il distruttore di d non viene chiamato dal delete

    return 0;
}