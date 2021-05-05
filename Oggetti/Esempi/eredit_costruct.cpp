#include <iostream>
using namespace std;
class B
{
    int x, y;

public:
    B();
    B(int, int);
};
class D : public B
{
    int z;

public:
    D();
    D(int, int, int);
};
B::B()
{
    x = 0;
    y = 0;
}
B::B(int a, int b)
{
    x = a;
    y = b;
}
//Invocazione automatica di B()
D::D() { z = 0; }
//Invocazione esplicita di B(int, int)
D::D(int a, int b, int c) : B(a, b), z(c) {}
int main()
{
    return 0;
}