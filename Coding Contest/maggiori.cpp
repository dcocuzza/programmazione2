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
        int X;
        in >> X;
        int v[N];
        int num = 0;
        for (int i = 0; i < N; i++)
        {
            int a;
            in >> a;
            if (a > X)
            {
                v[num] = a;
                num++;
            }
        }
        out << num << " ";
        for (int i = 0; i < num; i++)
            out << v[i] << " ";
        out << endl;
    }

    return 0;
}
