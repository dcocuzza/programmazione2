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
            double x;
            in >> x;
            int temp = x;
            double y = x - temp;
            out << y << " ";
        }
        out << endl;
    }

    return 0;
}
