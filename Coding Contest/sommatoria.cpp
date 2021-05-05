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
        int k;
        in >> k;
        double somma = 0.0;
        for (int i = 0; i < k; i++)
        {
            double num;
            in >> num;
            somma += num;
        }
        out << somma << endl;
    }

    return 0;
}
