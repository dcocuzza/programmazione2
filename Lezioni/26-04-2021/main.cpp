#include <iostream>
using namespace std;
enum Colore
{
    ROSSO,
    GIALLO,
    VERDE,
    BLU
};
class Shape
{
protected:
    Colore c = ROSSO;

public:
    Shape() {}
    Shape(Colore a) : c(a) {}
    Colore getColore()
    {
        return c;
    }
    void setColore(Colore _colore)
    {
        this->c = _colore;
    }
    void print()
    {
        cout << "Il colore e':\t" << c << endl;
    }
    virtual double getArea() = 0;
};

class Rettangolo : public Shape
{
    double altezza = 1;
    double ampiezza = 1;

public:
    Rettangolo(double _altezza, double _ampiezza)
    {
        this->altezza = _altezza;
        this->ampiezza = _ampiezza;
    }
    Rettangolo(double _altezza, double _ampiezza, Colore _colore) : Shape(_colore)
    {
        this->altezza = _altezza;
        this->ampiezza = _ampiezza;
    }
    double getAltezza()
    {
        return altezza;
    }
    void setAltezza(double _altezza)
    {
        this->altezza = _altezza;
    }
    double getAmpiezza()
    {
        return ampiezza;
    }
    void setAmpiezza(double _ampiezza)
    {
        this->altezza = _ampiezza;
    }
    double getArea()
    {
        return ampiezza * altezza;
    }
};

class Cerchio : public Shape
{
    double raggio = 1;
    double coordinataX = 0;
    double coordinataY = 0;

public:
    Cerchio(double _raggio, double _coordinataX, double _coordinataY)
    {
        this->raggio = _raggio;
        this->coordinataX = _coordinataX;
        this->coordinataY = _coordinataY;
    }
    Cerchio(double _raggio, double _coordinataX, double _coordinataY, Colore _colore) : Shape(_colore)
    {
        this->raggio = _raggio;
        this->coordinataX = _coordinataX;
        this->coordinataY = _coordinataY;
    }
    double getRaggio()
    {
        return raggio;
    }
    void setAmpiezza(double _raggio)
    {
        this->raggio = _raggio;
    }
    double getCoordinataX()
    {
        return coordinataX;
    }
    void setCoordinataX(double _coordinataX)
    {
        this->coordinataX = _coordinataX;
    }
    double getCoordinataY()
    {
        return coordinataY;
    }
    void setCoordinataY(double _coordinataY)
    {
        this->coordinataY = _coordinataY;
    }
    double getArea()
    {
        return 3.1415 * raggio * raggio;
    }
};
class Triangolo : public Shape
{
private:
    double base, altezza;

public:
    Triangolo(double _base, double _altezza) : base(_base), altezza(_altezza) {}
    Triangolo(double _base, double _altezza, Colore _c) : Shape(c)
    {
        base = _base;
        altezza = _altezza;
    }
    void setBase(double _base)
    {
        base = _base;
    }
    void setAltezza(double _altezza)
    {
        altezza = _altezza;
    }
    double getBase()
    {
        return base;
    }
    double getAlezza()
    {
        return altezza;
    }
    double getArea()
    {
        return (base * altezza) / 2;
    }
};
int main()
{
    const int n = 5;
    Shape *Fig[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Rettangolo: 1, Cerchio: 2, Triangolo: 3\n";
        int scelta;
        cin >> scelta;
        switch (scelta)
        {
        case 1:
            cout << "Inserire altezza e ampiezza \n";
            double ampiezza, altezza;
            cin >> ampiezza;
            cin >> altezza;
            Fig[i] = new Rettangolo(ampiezza, altezza);
            break;

        case 2:
            cout << "Inserire raggio, centroX, centroY \n";
            double raggio, centroX, centroY;
            cin >> raggio;
            cin >> centroX;
            cin >> centroY;
            Fig[i] = new Cerchio(raggio, centroX, centroY);
            break;

        case 3:
            cout << "Inserire base e altezza \n";
            double b, a;
            cin >> b;
            cin >> a;
            Fig[i] = new Triangolo(b, a);
            break;

        default:
            break;
        }
    }
    double somma = 0;
    for (int i = 0; i < n; i++)
    {
        somma += Fig[i]->getArea();
    }
    cout << "La media è: " << somma / n << endl;
    return 0;
}
