
#include <iostream>
#include <math.h>
using namespace std;

class Rettangolo{
    double base, altezza;
public:
    Rettangolo(double,double);
    Rettangolo(): Rettangolo(16,9) {}
    double getBase() const {return base;}
    double getAltezza() const {return altezza;}
    void setBase(double b) {base = b;}
    void setAltezza(double a) {altezza =a;}
    double area() const { return base*altezza;}
    double misuraDiagonale() const;
    double perimetro() const;
    bool sonoQuadrato() const;

    friend
    ostream& operator<<(ostream& out, const Rettangolo& r);
};

Rettangolo::Rettangolo(double b, double a): base(b), altezza(a){}
double Rettangolo::misuraDiagonale() const{
    return sqrt(base*base + altezza*altezza);
}
double Rettangolo::perimetro() const {return 2*(base+altezza);}
bool Rettangolo::sonoQuadrato() const { return base==altezza;}

ostream& operator<<(ostream& out, const Rettangolo& r){
    out << r.base << " X " << r.altezza << endl;
    out << "Diag. = " << r.misuraDiagonale() << endl;
    out << "Perim. = " << r.perimetro() << endl;
    out << "Area = " << r.area() << endl;
    out << "Quadrato ? " << (r.sonoQuadrato()? "Si" : "No") << endl;
    return out;
}

int main(){

    Rettangolo A(10,5);
    cout << A << endl;

    Rettangolo B(A);
    cout << B << endl;


return 0;
}




