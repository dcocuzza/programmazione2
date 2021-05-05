#ifndef ARRAY_DINAMICO_CPP_INCLUDED
#define ARRAY_DINAMICO_CPP_INCLUDED
#include <iostream>
#define BUF_SIZE 5

using namespace std;
class ArrayDinamico
{
private:
    double *ptr;
    int size;
    int maxSize;

public:
    explicit ArrayDinamico(int n = 8);
    explicit ArrayDinamico(const ArrayDinamico &a);
    ArrayDinamico(const double a[], int n);
    ~ArrayDinamico();

    int getSize() const { return size; }
    int getMaxSize() const { return maxSize; }

    void insert(double elem);
    void remove(int idx);

    double operator[](int idx) const;
    double &operator[](int idx);
    friend ostream &operator<<(ostream &out, const ArrayDinamico &a);
};
#endif