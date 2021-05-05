#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() //Punteggio: 10/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");

    for (int t = 0; t < 100; t++)
    {
        string s;
        in >> s;
        if (s.length() % 2 == 0)
            out << s;
        else
        {
            out << s.substr(0, s.length() - 1);
        }
        out << endl;
    }

    return 0;
}