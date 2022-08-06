//Contoh8_1.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#define N 100

using namespace std;

class Array
{
private:
    int i, array[N];
public:
    Array();
    void bubble_sort();
    void printArray(string);
    ~Array(){}
};

Array::Array()
{
    time_t seed;

    srand(time(&seed));

    for(int i=0; i < N; i++)
        array[i] = rand() % N;
}

void Array::bubble_sort()
{
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            if(array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}

void Array::printArray(string str)
{
    cout << str << endl;
    for(int i=0; i < N; i++)
        cout << array[i] << " ";

    cout << endl;
}

int main()
{
    Array myArr;

    myArr.printArray("Sebelum disortir: ");
    myArr.bubble_sort();
    cout << endl;
    myArr.printArray("Setelah disortir: ");

    return 0;
}