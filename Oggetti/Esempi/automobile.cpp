#include <iostream>
using namespace std;
class Mezzo
{
private:
    int velocita;
    string colore;
    int numPorte;
    int livCarburante;
    int posMacia;
    bool stato;

public:
    Mezzo()
    {
        this->stato = 0;
    }
    Mezzo(int velocita, string colore, int numPorte, int livCarburante, int posMarcia)
    {
        this->velocita = velocita;
        this->colore = colore;
        this->numPorte = numPorte;
        this->livCarburante = livCarburante;
        this->posMacia = posMacia;
        this->stato = 0;
    }
    void fermati()
    {
        this->velocita = 0;
    }
    void accelera(int nuovaVelocita)
    {
        this->velocita = nuovaVelocita;
    }
    void modificaStato(bool stato)
    {
        this->stato = stato;
    }
    virtual int getNumMarcie() = 0;
};
class Automobile : public Mezzo
{
private:
    int numMarcie;

public:
    Automobile(int velocita, string colore, int numPorte, int livCarburante, int posMarcia, int numMarcie) : Mezzo(velocita, colore, numPorte, livCarburante, posMarcia)
    {
        this->numMarcie = numMarcie;
    }
    int getNumMarcie()
    {
        return numMarcie;
    }
};
class MyClass
{
public:
    // Costruttore di default
    MyClass() {}
    // lista di inizializzazione
    MyClass(int a, char b) : x(a), c(b) {}
    MyClass(int a) : y(a * 2) {}

    MyClass(char b) : MyClass(10, b) {}
    void printAll()
    {
        cout << "x = " << x << endl;
        cout << "c = " << c << endl;
        cout << "y = " << y << endl;
    }

private:
    int x = 18;  // inizializzazione
    char c{'M'}; // iniz. Uniforme
    const int y = 0;
};
int main()
{
    //*Automobile
    /*Automobile Car(50, "rosso", 5, 200, 1, 5);
    Automobile *car = new Automobile(50, "rosso", 5, 200, 1, 4);
    Mezzo *a;
    a = new Automobile(120, "giallo", 4, 220, 2, 5);
    cout << Car.getNumMarcie() << endl;
    cout << car->getNumMarcie() << endl;
    cout << a->getNumMarcie() << endl;*/

    /*//*MyClass
    cout << "Primo costruttore\n";
    MyClass cos;
    cos.printAll();

    cout << "Secondo costruttore\n";
    MyClass trut(6, 'a');
    trut.printAll();

    cout << "Terzo costruttore\n";
    MyClass to(5);
    to.printAll();

    cout << "Quarto costruttore\n";
    MyClass re('q');
    re.printAll();
    return 0;*/

    //*Const
    const double p = 3.14; // non posso modificare il valore
    //! p = 4; da errore

    int a = 22;
    int b = 10;
    int *punt = &a; //! nulla è costante

    const int *punt2 = &a; //! il dato è costante
    //! *punt2 = b; da errore
    punt2 = &b; //? posso cambiare la variabile puntata

    int *const punt3 = &a; //! il puntatore è costante
    //! punt3 = &b; da errore
    *punt3 = b; //? posso cambiare il valore

    const int *const punt4 = &a; //! puntatore costante e dato costante
    //! punt4 = &b; da errore
    //! *punt4 = b;
}
