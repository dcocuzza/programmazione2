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
    MyClass(int uno, int due, int tre)
    {
        this->uno;
        this->due;
        this->tre;
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
    return 0;
}