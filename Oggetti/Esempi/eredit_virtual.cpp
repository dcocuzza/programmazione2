#include <iostream>
using namespace std;
class A
{
public:
    int x = 5;
};

class B : public virtual A
{
};

class C : public virtual A
{
};

class D : public B, public C
{
};
int main()
{
    D d;
    //richiesta non più ambigua
    cout << d.x << endl;
    return 0;
}