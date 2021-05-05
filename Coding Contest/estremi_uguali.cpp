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
        int cont = 0;
        for (int i = 0; i < 3; i++)
        {
            int k;
            in >> k;
            string s;
            in >> s;
            if (s[0] == s[k - 1])
            {
                cont++;
            }
        }
        out << cont << endl;
    }

    return 0;
}