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
        char inizio;
        in >> inizio;
        for (int i = 0; i < 3; i++)
        {
            int k;
            in >> k;
            string s;
            in >> s;
            if (s[0] == inizio)
            {
                out << s << " ";
            }
        }
        out << endl;
    }

    return 0;
}