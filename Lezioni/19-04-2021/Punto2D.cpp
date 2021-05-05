#include <iostream>
#include <math.h>
using namespace std;

class Punto2D
{
    double x, y;

public:
    Punto2D(double a = 0, double b = 0) : x(a), y(b) {}
    double getX() const { return x; }
    void setX(double a) { x = a; }
    double getY() const { return y; }
    void setY(double b) { y = b; }
};

class Rettangolo
{
private:
    double base, altezza;
    Punto2D *top_left, *bottom_right;

public:
    Rettangolo(double b = 10, double a = 5) : base(b), altezza(a)
    {
        top_left = new Punto2D(5, 20);
        bottom_right = new Punto2D(20, 10);
    }
    double getBase() const { return base; }
    double getAltezza() const { return altezza; }
    void setBase(double b) { base = b; }
    void setAltezza(double a) { altezza = a; }
    Punto2D getTopLeft() const { return *top_left; }
    void setTopLeft(Punto2D &p) { top_left = &p; }
    Punto2D getBottomRight() const { return *bottom_right; }
    void setBottomRight(Punto2D &p) { bottom_right = &p; }
    double calcolaArea() const;
    double calcolaPerimetro() const;
    double calcolaDiagonale() const;
    bool isQuadrato() const;
    bool contiene(const Punto2D &p) const;
    bool contiene(const Rettangolo &r) const;
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
bool Rettangolo::contiene(const Punto2D &p) const
{
    return p.getX() <= bottom_right->getX() &&
           p.getX() >= top_left->getX() &&
           p.getY() >= bottom_right->getY() &&
           p.getY() <= top_left->getY();
}
bool Rettangolo::contiene(const Rettangolo &r) const
{
    return (this->contiene(r.getTopLeft()) && this->contiene(r.getBottomRight()));
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

    cout << "ret1 top_left: (" << ret1.getTopLeft().getX() << ", " << ret1.getTopLeft().getY() << ")"
         << " ret 1 bottom_right: (" << ret1.getBottomRight().getX() << ", " << ret1.getBottomRight().getY() << ")\n";
    ;

    cout << "ret2 top_left: (" << ret2.getTopLeft().getX() << ", " << ret2.getTopLeft().getY() << ")"
         << " ret 2 bottom_right: (" << ret2.getBottomRight().getX() << ", " << ret2.getBottomRight().getY() << ")\n";
    ;
    Punto2D p{10, 15};
    cout << "Il punto: (" << p.getX() << ", " << p.getY() << ") si trova in ret 1: " << (ret1.contiene(p) ? "Si" : "No") << endl;
    cout << "--------------------------------------------------------\n";
    cout << "r1 contiene r2? " << (ret1.contiene(ret2) ? "Si" : "No") << endl;

    return 0;
}