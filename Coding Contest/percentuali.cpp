#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() //Punteggio: 0/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");

    for (int t = 0; t < 100; t++)
    {
        string caratteri;
        string stringhe;
        for (int i = 0; i < 4; i++)
        {
            string app;
            in >> app;
            stringhe += app;
        }
        int a[stringhe.length()];
        for (int i = 0; i < stringhe.length(); i++)
        {
        }
    }

    return 0;
}
