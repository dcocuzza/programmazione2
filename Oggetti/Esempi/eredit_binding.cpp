#include <iostream>
using namespace std;
class Figura
{
public:
    virtual double calcola_area() { return 0.001; };
    virtual void disegnare(){};
};
class Cerchio : public Figura
{
public:
    double calcola_area();
    void disegnare();
    void setRaggio(double r) { raggio = r; }

private:
    double xc, yc; //coordinate centro
    double raggio;
};
double Cerchio::calcola_area()
{
    return 3.1415 * raggio * raggio;
}
void Cerchio::disegnare()
{
}

class Rettangolo : public Figura
{
public:
    double calcola_area();
    void disegnare();
    void setBase(double b) { base = b; }
    void setAltezza(double a) { altezza = a; }

private:
    double base, altezza;
};
double Rettangolo::calcola_area()
{
    return base * altezza;
}
void Rettangolo::disegnare()
{
}

int main()
{
    Figura *figs[3];
    Cerchio c;
    Cerchio c2(c);
    c2.setRaggio(5);
    Rettangolo r;

    figs[0] = &c;
    figs[1] = &r;
    figs[2] = &c2;
    for (int i = 0; i < 3; i++)
        cout << figs[i]->calcola_area() << endl;
    return 0;
}