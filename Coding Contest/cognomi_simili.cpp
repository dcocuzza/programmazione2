#include <iostream>
#include <fstream>
using namespace std;
int main() //Punteggio: 10/10
{

    fstream in("../../../input.txt");
    ofstream out("../../../output.txt");
    int k;
    string s0, s1, s2;
    for (int i = 0; i < 100; i++)
    {
        in >> k;
        in >> s0;
        in >> s1;
        in >> s2;
        bool c0 = false, c1 = false, c2 = false, conf = false;
        if (s0.substr(0, k) == s1.substr(0, k) && s0.substr(0, k + 1) != s1.substr(0, k + 1))
        {
            c0 = true;
            c1 = true;
        }
        else
            conf = true;
        if (s0.substr(0, k) == s2.substr(0, k) && s0.substr(0, k + 1) != s2.substr(0, k + 1))
        {
            c0 = true;
            c2 = true;
        }
        if (s1.substr(0, k) == s2.substr(0, k) && s1.substr(0, k + 1) != s2.substr(0, k + 1))
        {
            c1 = true;
            c2 = true;
        }
        if (c0 == true && c1 == true && c2 == true && conf == true)
        {
            out << s0 << " " << s2 << endl;
            continue;
        }

        if (c0)
            out << s0 << " ";
        if (c1)
            out << s1 << " ";
        if (c2)
            out << s2 << " ";
        out << endl;
    }

    return 0;
}