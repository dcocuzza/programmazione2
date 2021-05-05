
#include <iostream>
using namespace std;

class MyClass
{
private:
    int uno, due, tre;

public:
    MyClass()
    {
    }
    MyClass(int _uno, int _due, int _tre)
    {
        uno = _uno;
        due = _due;
        tre = _tre;
    }

    void printThis()
    {
        cout << "This:\t" << this << endl;
    }
};

int main()
{
    MyClass a{};
    a.printThis();
    cout << "&a:\t" << &a << endl;

    MyClass *pa = &a;
    cout << "pa:\t" << pa << endl;
}
