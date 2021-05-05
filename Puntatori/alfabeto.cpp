#include <iostream>

using namespace std;

char c; //variabile globale

int main()
{
    char *primo;
    primo = &c;

    for (c = 'A'; c <= 'Z'; c++)
    {
        cout << *primo << ", ";
    }
    cout << endl;

    return 0;
}
