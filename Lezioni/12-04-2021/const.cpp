#include <iostream>
using namespace std;
class ContoCorrente
{
private:
    int saldo = 100000;

public:
    int &getSaldoCattiva()
    {
        return saldo;
    }
    int const &getSaldo() { return saldo; }
    void printSaldo()
    {
        cout << "Il tuo saldo è:\t " << saldo << endl;
        if (saldo < 0)
            cout << "Attenzione!!! Il conto è in passivo! \n";
    }
};
int main()
{
    ContoCorrente cc;
    cc.getSaldoCattiva() = -10;
    cc.printSaldo();
    const int y = cc.getSaldo();
    return 0;
}