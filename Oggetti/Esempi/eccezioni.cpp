#include <iostream>
#include <stdexcept>
using namespace std;
class Tempo
{
private:
    int ore;
    int minuti;
    int secondi;

public:
    void setOre(int h)
    {
        if (h >= 0 && h <= 23)
            ore = h;
        else
        {
            /*cout << "Errore di ore validi 0-23.\n";
            exit(1);*/
            //! OPPURE
            throw invalid_argument("Errore: valori di ore validi 0-23.\n");
        }
    }
};

int main()
{
    Tempo a;
    a.setOre(50);

    Tempo t;

    try
    {
        t.setOre(80);
    }
    catch (invalid_argument &ex)
    {
        cout << "Eccezione: " << ex.what() << endl;
    }
    return 0;
}