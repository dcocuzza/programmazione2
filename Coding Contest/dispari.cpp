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
        int N;
        in >> N;
        for (int i = 0; i < N; i++)
        {
            int a;
            in >> a;
            if (a % 2 != 0)
                out << a << " ";
        }
        out << endl;
    }

    return 0;
}
