#include <iostream>
using namespace std;
enum Colore
{
    ROSSO,
    GIALLO,
    VERDE,
    BLU
};
class Cerchio
{
    double raggio;
    Colore c;

public:
    /*  Cerchio(){raggio = 1; cout << "costr default"<<endl;}
    Cerchio(double r){ raggio=r; cout << "costr 1 par." << endl;}
*/
    /*explicit in questo modo non si può invocare calcola_area() con un numero*/
    Cerchio(double r = 1)
    {
        raggio = r;
        c = ROSSO;
    } //cout << "costr con valore di default"<<endl;}
    double circonferenza() const { return 2 * raggio * 3.1415; }
    double getRaggio() const { return raggio; }
};
double area_cerchio(Cerchio c)
{
    return c.getRaggio() * c.getRaggio() * 3.1415;
}
double area(Cerchio &c)
{
    cout << "Metodo senza const" << endl;
    return c.getRaggio() * c.getRaggio() * 3.1415;
}
double area(const Cerchio &c)
{
    cout << "Metodo con const" << endl;
    return c.getRaggio() * c.getRaggio() * 3.1415;
}
int main()
{
    Cerchio c1{};
    cout << c1.getRaggio() << endl;

    Cerchio c2{10};
    cout << c2.getRaggio() << endl;

    /*cout << "Circonferenza c1:\t" << c1.circonferenza() << endl;
    cout << "Circonferenza c2:\t" << c2.circonferenza() << endl;

    cout << "Area c2:\t" << area_cerchio(c2) << endl;
    cout << "Area di ?? \t" << area_cerchio(2.3) << endl;*/
    cout << "Area:\t" << area(c2) << endl;
    cout << "Area:\t" << area(2.3) << endl;

    return 0;
}
