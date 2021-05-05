#include <iostream>
using namespace std;
class MyClass
{
    int value;
    static int num_obj; //numero di istanze della classe
public:
    MyClass(int x);
    MyClass();
    ~MyClass();
    int getValue();
    void setValue(int x);
    static int getNumObj();
    //definisco un metodo per clonare una istanza
    MyClass *clone();
};
int MyClass::num_obj = 0;
MyClass::MyClass(int x)
{
    value = x;
    num_obj++;
}
MyClass::~MyClass() { num_obj--; }
MyClass::MyClass() {}
int MyClass::getNumObj() { return num_obj; }
int MyClass::getValue() { return value; }
MyClass *MyClass::clone()
{
    MyClass *copia_p = new MyClass();
    copia_p->setValue(value);
    return copia_p;
}
void MyClass::setValue(int x)
{
    value = x;
}

int main()
{
    MyClass obj_l;
    obj_l.setValue(20);
    MyClass obj_2(10);

    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Obj_l value:\t" << obj_l.getValue() << endl;
    cout << "Obj_2 value:\t" << obj_2.getValue() << endl;

    MyClass *cp_1 = obj_l.clone();
    cout << "Copia 1 value:\t" << cp_1->getValue() << endl;
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    {
        cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    }
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    return 0;
}