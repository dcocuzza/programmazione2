#include <iostream>
using namespace std;
template <typename T>
T massimo(T x, T y)
{
    return (x > y ? x : y);
}
int main()
{
    cout << massimo(5, 9) << endl;
    cout << massimo('h', 'a') << endl;

    cout << massimo<int>(-8, -6) << endl;
    cout << massimo<char>('q', 'g') << endl;
    return 0;
}