#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
unsigned long int fibonacci(int n)
{
    unsigned long int v[n];
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < n; i++)
        v[i] = v[i - 1] + v[i - 2];
    return v[n - 1];
}
int main() //Punteggio: 10/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");
    int n;
    for (int t = 0; t < 100; t++)
    {
        in >> n;
        out << fibonacci(n) << endl;
    }

    return 0;
}
