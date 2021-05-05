#include <iostream>
#include <math.h>
using namespace std;
class Rettangolo
{
private:
    double base, altezza;

public:
    Rettangolo(double b = 10, double a = 5) : base(b), altezza(a) {}
    double getBase() const { return base; }
    double getAltezza() const { return altezza; }
    void setBase(double b) { base = b; }
    void setAltezza(double a) { altezza = a; }
    double calcolaArea() const;
    double calcolaPerimetro() const;
    double calcolaDiagonale() const;
    bool isQuadrato() const;
    friend ostream &operator<<(ostream &out, Rettangolo &r);
};
double Rettangolo::calcolaArea() const { return base * altezza; }
double Rettangolo::calcolaPerimetro() const { return (base + altezza) * 2; }
double Rettangolo::calcolaDiagonale() const { return sqrt(base * base + altezza * altezza); }
bool Rettangolo::isQuadrato() const
{
    if (base == altezza)
        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, Rettangolo &r)
{
    out << r.base << " X " << r.altezza << endl;
    out << "Diag. = " << r.calcolaDiagonale() << endl;
    out << "Perim. = " << r.calcolaPerimetro() << endl;
    out << "Area = " << r.calcolaArea() << endl;
    out << "è un quadtrato? " << (r.isQuadrato() ? "SI" : "NO") << endl;
    return out;
}
int main()
{
    Rettangolo ret1;
    cout << "ret1 base: " << ret1.getBase() << " ret1 altezza: " << ret1.getAltezza() << endl;
    Rettangolo ret2{30, 30};
    cout << "ret2 base: " << ret2.getBase() << " ret2 altezza: " << ret2.getAltezza() << endl;

    cout << "ret1 area: " << ret1.calcolaArea() << " ret1 perimetro: " << ret1.calcolaPerimetro() << " ret1 diagonale: " << ret1.calcolaDiagonale() << endl;
    cout << "ret2 area: " << ret2.calcolaArea() << " ret2 perimetro: " << ret2.calcolaPerimetro() << " ret2 diagonale: " << ret2.calcolaDiagonale() << endl;

    cout << "ret1 quadrato: " << ret1.isQuadrato() << endl;
    cout << "ret2 quadrato: " << ret2.isQuadrato() << endl;

    cout << ret1 << endl;
    cout << ret2 << endl;

    return 0;
}