#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() //Punteggio: 10/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");

    int k;
    char si, no;
    string s;
    for (int t = 0; t < 100; t++)
    {
        in >> si;
        in >> no;

        for (int i = 0; i < 3; i++)
        {
            in >> k;
            in >> s;
            if (s[0] == si || s[k - 1] == si)
            {
                if (s[0] != no && s[k - 1] != no)
                    out << s << " ";
            }
        }
        out << endl;
    }

    return 0;
}