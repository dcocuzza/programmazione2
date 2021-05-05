#include <iostream>
using namespace std;
template <typename T, typename U>
class MyPair
{
public:
    MyPair(T first, U second)
    {
        a = first;
        b = second;
    }
    T getFist()
    {
        return a;
    }
    U getSecond()
    {
        return b;
    }

private:
    T a;
    U b;
};
int main()
{
    MyPair<char, int> p('c', 7);
    cout << p.getFist() << endl;

    MyPair<int, int> p2(8, 9);
    cout << p2.getSecond() << endl;
    return 0;
}