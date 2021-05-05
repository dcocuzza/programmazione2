#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
void func(T x)
{
    cout << "x(generico): " << x << endl;
}
template <>
void func<int>(int x)
{
    cout << "x(int): " << x << endl;
}
template <typename T = double, int N = 5>
class MyClass
{
    T arr[N];

public:
    MyClass()
    {
        for (int i = 0; i < N; i++)
            arr[i] = (double)rand() / RAND_MAX;
    }
    void stampa()
    {
        cout << "ARR: ";
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    int a = 5;
    char b = 'F';
    func(a);
    func(b);

    MyClass<> my;
    my.stampa();

    MyClass<double, 2> my2;
    my2.stampa();

    return 0;
}