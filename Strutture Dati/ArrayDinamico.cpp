#include "ArrayDinamico.h"
ArrayDinamico::ArrayDinamico(int n)
{
    if (n <= 0)
    {
        cout << "Errore: size deve essere maggiore di 0";
        exit(1);
    }
    maxSize = n + BUF_SIZE;
    size = n;
    ptr = new double[maxSize];
    for (int i = 0; i < maxSize; i++)
        ptr[i] = 0.0;
}

ArrayDinamico::ArrayDinamico(const ArrayDinamico &a)
{
    maxSize = a.maxSize;
    size = a.size;
    ptr = new double[maxSize];
    for (int i = 0; i < maxSize; i++)
        ptr[i] = a.ptr[i];
}

ArrayDinamico::ArrayDinamico(const double a[], int n)
{
    maxSize = n + BUF_SIZE;
    size = n;
    ptr = new double[maxSize];
    for (int i = 0; i < maxSize; i++)
        ptr[i] = a[i];
}

ArrayDinamico::~ArrayDinamico()
{
    delete[] ptr;
}

void ArrayDinamico::insert(double elem)
{
    if (size == maxSize)
    {
        cout << "Estendo l'array..." << endl;
        maxSize += BUF_SIZE + 1;
        double *tmp = new double[maxSize];
        for (int i = 0; i < size; i++)
            tmp[i] = ptr[i];
        double *toDelete = ptr;
        ptr = tmp;
        delete[] toDelete;
    }
    ptr[size] = elem;
    size++;
}

void ArrayDinamico::remove(int idx)
{
    if (idx >= size || idx < 0)
    {
        cout << "Indice errato" << endl;
        exit(-1);
    }
    for (int i = idx; i < size - 1; i++)
        ptr[i] = ptr[i + 1];

    ptr[size] = 0.0;
    size--;

    if (size <= maxSize - 2 * BUF_SIZE)
    {
        cout << "Riduco l'array..," << endl;
        maxSize -= BUF_SIZE;
        double *tmp = new double[maxSize];
        for (int i = 0; i < size; i++)
            tmp[i] = ptr[i];
        double *toDelete = ptr;
        ptr = tmp;
        delete[] toDelete;
        cout << "Nuova dimensione massima-->" << maxSize << endl;
    }
}

double ArrayDinamico::operator[](int idx) const
{
    if (idx < 0 || idx >= size)
    {
        throw out_of_range("ArrayDinamico::operator[] -> indice fuori dal range");
    }
    return ptr[idx];
}

double &ArrayDinamico::operator[](int idx)
{
    if (idx < 0 || idx >= size)
    {
        cout << "Indice errato" << endl;
        exit(-1);
    }
    return ptr[idx];
}

ostream &operator<<(ostream &out, const ArrayDinamico &a)
{
    out << "[ ";
    for (int i = 0; i < a.maxSize; i++)
    {
        if (i < a.size)
            out << a.ptr[i] << " ";
        else
            out << " - ";
    }
    out << " ]" << endl;
    return out;
}