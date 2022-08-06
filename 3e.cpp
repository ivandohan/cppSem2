//Contoh3_5.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define N 100

using namespace std;

class Array
{
    private:
        int array_integer[N];
        float array_float[N];
    public:
        Array(int);
        Array(double);
        long jlh_Array(int);
        float jlh_Array(double);
        void print_array(int);
        void print_array(double);
        ~Array() {}
};

// Array::Array(int type)
// {
//     srand(time(NULL));
//     for(int i = 0; i < N; i++)
//         array_integer[i] = rand() % N;
// }

// Array::Array(double type)
// {
//     srand(time(NULL));
//     for(int i = 0; i < N; i++)
//         array_float[i] = rand() % N;
// }

Array::Array(int aValue)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        aValue = rand() % N;
        array_integer[i] = aValue;
    }
}
Array::Array(double aValue)
{
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        aValue = rand() % N;
        array_float[i] = aValue;
    }
}

float Array::jlh_Array(double type)
{
    float jlh = 0.0;

    for(int i=0; i < N; i++)
        jlh += array_float[i];
    
    return jlh;
}

long Array::jlh_Array(int type)
{
    long jlh = 0L;

    for(int i=0; i < N; i++)
        jlh += array_integer[i];
    return jlh;
}

void Array::print_array(double type)
{
    cout << "Array Float : " << endl;
    for(int i=0; i < N; i++)
    cout << setprecision(2) << setiosflags(ios::fixed) << array_float[i] << " ";
    cout << endl;
}

int main()
{
    Array myArr1(0), myArr2(0.0);

    myArr1.print_array(0);
    cout << "Jumlah array integer = " << myArr1.jlh_Array(0) << endl;
    myArr2.print_array(0.0);
    
    cout << "Jumlah array float = " << setprecision(2) 
    << setiosflags(ios::fixed)
    << myArr2.jlh_Array(0.0)
    << endl;

    return 0;
}