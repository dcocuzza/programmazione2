#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() //Punteggio: 10/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");
    int k;
    string s, nuova;
    for (int t = 0; t < 100; t++)
    {
        for (int i = 0; i < 3; i++)
        {
            in >> k;
            in >> s;
            nuova = toupper(s[0]);
            for (int j = 1; j < k; j++)
            {
                nuova += s[j];
            }
            out << nuova << " ";
        }
        out << endl;
    }

    return 0;
}