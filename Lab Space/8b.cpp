//Contoh8_2.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Array
{
private:
    int *array;
    int size;

public:
    Array(int);
    void generate();
    void bubble_sort();
    void printArray(string);
    ~Array() { delete [] array; }
};

Array::Array(int size)
{
    time_t seed;

    this->size = size;
    srand(time(&seed));
}

void Array::generate()
{
    if ((array = new int[size]) == NULL)
        cerr << "Error alokasi memori..." << endl;
    else
    {
        for(int i=0; i < size; i++)
        array[i] = rand() % size;
    }
}

void Array::bubble_sort()
{
    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
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
    for(int i=0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    Array myArr(100);

    //Generate random array
    myArr.generate();

    //Print unsorted array
    myArr.printArray("Sebelum disortir:");
    //Sort array
    myArr.bubble_sort();
    //Print sorted array
    myArr.printArray("Sesudah disortir:");

    return 0;
}