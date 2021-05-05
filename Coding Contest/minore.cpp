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
        int min = 10001;
        string s;
        do
        {
            in >> s;
            if (s == "STOP")
            {
                break;
            }
            int n = stoi(s);
            if (n < min)
                min = n;

        } while (5);
        out << min << endl;
    }

    return 0;
}
