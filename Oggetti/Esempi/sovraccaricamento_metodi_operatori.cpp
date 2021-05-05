#include <iostream>
#include <math.h>
using namespace std;
class Array
{
private:
    int size;
    int *data;

public:
    Array(int size)
    {
        this->size = size;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = 10;
        }
    };
    // l'operatore == non può modificare nulla
    bool operator==(const Array &right) const;
    int &operator[](int index);
};
bool Array::operator==(const Array &right) const
{
    if (size != right.size)
        return false;
    for (int i = 0; i < size; i++)
        if (data[i] != right.data[i])
            return false;
    return true;
}
int &Array::operator[](int index)
{
    return data[index];
}
int main()
{
    Array a{5}, b{5};
    if (a == b)
        cout << "Gli array sono uguali\n";
    else
        cout << "Gli array sono diversi\n";
    return 0;
}