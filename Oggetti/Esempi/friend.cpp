#include <iostream>
using namespace std;
class Point
{
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    //dichiarazione di amicizia
    friend bool operator==(Point a, Point b);

private:
    int x, y;
};
//accesso a membri privati anche a funzione o metodi di altre classi
bool operator==(Point a, Point b)
{
    if ((a.x != b.x) || (a.y != b.y))
        return false;
    else
        return true;
}
int main()
{
    Point p{2, 3}, q{2, 3};
    if (p == q)
        cout << "I punti sono uguali\n";
    return 0;
}