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
        int somma = 0;
        int N, M;
        in >> N;
        in >> M;
        int nemo[N], gaspare[M];

        for (int i = 0; i < N; i++)
            in >> nemo[i];
        for (int i = 0; i < M; i++)
            in >> gaspare[i];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (nemo[i] == gaspare[j])
                    somma += 5;
        out << somma << endl;
    }

    return 0;
}
