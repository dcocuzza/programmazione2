#include <iostream>
#include <math.h>
using namespace std;

class Punto2D
{
    int x, y;

public:
    Punto2D(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }

    friend ostream &operator<<(ostream &out, const Punto2D &p);
};

ostream &operator<<(ostream &out, const Punto2D &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

class Rettangolo
{
    double base, altezza;
    Punto2D top_left, bot_right;

    void aggiornaBaseAltezza()
    {
        base = bot_right.getX() - top_left.getX();
        altezza = top_left.getY() - bot_right.getY();
    }

public:
    Rettangolo(const Punto2D &, const Punto2D &);
    const Punto2D &getTL() const { return top_left; }
    const Punto2D &getBR() const { return bot_right; }
    void setTL(int x, int y)
    {
        top_left.setX(x);
        top_left.setY(y);
        aggiornaBaseAltezza();
    }
    void setBR(int x, int y)
    {
        bot_right.setX(x);
        bot_right.setY(y);
        aggiornaBaseAltezza();
    }
    double area() const { return base * altezza; }
    double perimetro() const;
    double diagonale() const;
    bool sonoQuadrato() const;
    bool contiene(const Punto2D &);
    bool contiene(const Rettangolo &);

    friend ostream &operator<<(ostream &out, const Rettangolo &r);
};

ostream &operator<<(ostream &out, const Rettangolo &r)
{
    out << "Coordinate:\t" << r.getTL() << "\t" << r.getBR() << endl;
    out << "Diag. = " << r.diagonale() << endl;
    out << "Perim. = " << r.perimetro() << endl;
    out << "Area = " << r.area() << endl;
    out << "Quadrato ? " << (r.sonoQuadrato() ? "Si" : "No") << endl;
    return out;
}
double Rettangolo::perimetro() const { return 2 * (base + altezza); }
bool Rettangolo::sonoQuadrato() const { return base == altezza; }
double Rettangolo::diagonale() const { return sqrt(base * base + altezza * altezza); }

bool Rettangolo::contiene(const Punto2D &p)
{
    return p.getX() <= bot_right.getX() &&
           p.getX() >= top_left.getX() &&
           p.getY() >= bot_right.getY() &&
           p.getY() <= top_left.getY();
}

bool Rettangolo::contiene(const Rettangolo &r)
{
    return this->contiene(r.getTL()) && this->contiene(r.getBR());
}

Rettangolo::Rettangolo(const Punto2D &p1, const Punto2D &p2)
{
    top_left = p1;
    bot_right = p2;
    aggiornaBaseAltezza();
}

int main()
{
    Punto2D tl1 = {3, 7};
    Punto2D br1(15, 1);

    Rettangolo r1(tl1, br1);
    cout << r1 << endl;

    Rettangolo r2({0, 50}, {50, 0});
    cout << r2 << endl;

    cout << "r1 contiene (10,20)? " << (r1.contiene((10, 20)) ? "Si" : "No") << endl;
    //    cout << r1.contiene(Punto2D(10,20)) << endl;
    cout << "r2 contiene (25,20)? " << (r2.contiene((25, 20)) ? "Si" : "No") << endl;

    cout << "r1 contiene r2? " << (r1.contiene(r2) ? "Si" : "No") << endl;
    cout << "r2 contiene r1? " << (r2.contiene(r1) ? "Si" : "No") << endl;

    return 0;
}
