#include <iostream>
using namespace std;
class ClasseA
{
public:
    ClasseA() {}
    virtual void dinamica()
    {
        cout << "Metodo dinamico della Classe A" << endl;
    }
    void statica()
    {
        cout << "Metodo statico della Classe A" << endl;
    }
};
class ClasseB : public ClasseA
{
public:
    ClasseB() {}
    void dinamica()
    {
        cout << "Metodo dinamico della Classe B" << endl;
    }
    void statica()
    {
        cout << "Metodo statico della Classe B" << endl;
    }
};
int main()
{
    ClasseA *a;
    ClasseB *b;
    a = new ClasseA();
    b = new ClasseB();

    cout << "Metodi di a* della classe A:" << endl;
    a->dinamica();
    a->statica();
    cout << endl;
    cout << "Metodi di b* della classe B:" << endl;
    b->dinamica();
    b->statica();
    cout << endl;
    a = b;
    cout << "Metodi di b* dopo a = b:" << endl;
    a->dinamica();
    a->statica();

    return 0;
}