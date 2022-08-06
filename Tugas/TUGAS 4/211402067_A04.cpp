/*
        Nama File       : 211402067_A04.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        === Modifikasi pada Program 7.2 ===
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#define N 100
using namespace std;

class Array
{
private:
    fstream myFile;
    int array_integer[N];
    float array_float[N];

    int tampungnilaiInt = 0;
    float tampungnilaiFloat = 0 , mean;

    int arrayi_hasilReadFile[N];
    float arrayf_hasilReadFile[N];

    string intFile = "data1.txt";
    string floatFile = "data2.txt";

public:
    Array(int);
    Array(double);

    long jlh_Array(int);
    float jlh_Array(double);
    void print_array(int);
    void print_array(double);

    //Fungsi untuk Tugas Pemrograman 4

    void cekFile(int a){
        if(a == 1){
            if(!myFile.is_open()){
                myFile.open(intFile, ios::trunc | ios::out);
                closeFile();
            }
        }
        else if(a == 2){
            if(!myFile.is_open()){
                myFile.open(floatFile, ios::trunc | ios::out);
                closeFile();
            }
        }
    }

    void openFile(int a){
        if(a == 1){
            myFile.open(intFile, ios::out | ios::in);
        }else if(a == 2){
            myFile.open(floatFile, ios::out | ios::in);
        }
    }

    void closeFile(){
        myFile.close();
    }

    void hitungMean(int);
    void writeFile(int);
    void readFile(int);
    //Ending dari Fungsi Tambahan untuk Tugas Pemrograman 4

    ~Array() { }
};

void Array::writeFile(int a)
{
    if(a == 1){
        openFile(1);
        for(int i=0; i < N; i++)
            myFile << array_integer[i] << " ";
        cout << endl;
        closeFile();
    }else if(a == 2){
        openFile(2);
        for(int i=0; i < N; i++)
            myFile << array_float[i] << " ";
        cout << endl;
        closeFile();
    }
}

void Array::readFile(int a)
{
    if(a == 1){
        openFile(1);
        for(int i=0; i < N; i++)
            myFile >> arrayi_hasilReadFile[i];
        closeFile();
    }
    else if(a == 2){
        openFile(2);
        for(int i=0; i < N; i++)
            myFile >> arrayf_hasilReadFile[i];
        closeFile();
    }
}

void Array::hitungMean(int a)
{
    if(a == 1){
        for(int i=0; i < N; i++){
            tampungnilaiInt += arrayi_hasilReadFile[i];
        }
        mean = float(tampungnilaiInt)/float(N);
        cout << "Mean Array Int dari File   = " << mean << endl;
    }
    else if(a == 2){
        for(int i=0; i < N; i++){
            tampungnilaiFloat += arrayf_hasilReadFile[i];
        }
        mean = tampungnilaiFloat/N;
        cout << "Mean Array Float dari File = " << mean << endl;
    }
}

Array::Array(int type)
{
    srand(time(NULL));

    for(int i=0; i<N; i++)
        array_integer[i] = rand() % N;
}

Array::Array(double type)
{
    for(int i=0; i<N; i++)
        array_float[i] = (float) (rand() % N);
}

long Array::jlh_Array(int type)
{
    long jlh = 0L;
    for(int i=0; i < N; i++)
        jlh += array_integer[i];

    return jlh;
}

float Array::jlh_Array(double type)
{
    float jlh = 0.0;

    for(int i=0; i < N; i++)
        jlh += array_float[i];

    return jlh;
}

void Array::print_array(int type)
{
    cout << "\nArray Integer : " << endl;

    for(int i=0; i < N; i++)
        cout << array_integer[i] << " ";

    cout << endl;
}

void Array::print_array(double type)
{
    cout << "\nArray Float   : " << endl;

    for(int i=0; i < N; i++)
        cout << setprecision(2)
            << setiosflags(ios::fixed)<<
            array_float[i]
            << " ";

    cout << endl;
}

int main()
{
    Array myArr1(0), myArr2(0.0);

    system("CLS");

    myArr1.cekFile(1);
    myArr2.cekFile(2);

    //Part untuk Integer
    myArr1.print_array(0);
    myArr1.writeFile(1);
    cout << "Jumlah array integer = "
        << myArr1.jlh_Array(0) << endl;
    myArr1.readFile(1);
    myArr1.hitungMean(1);
    //End of Part untuk Integer


    //Part untuk Float
    myArr2.print_array(0.0);
    myArr2.writeFile(2);
    cout << "Jumlah array float   = " 
        <<setprecision(2)
            << setiosflags(ios::fixed)
            << myArr2.jlh_Array(0.0)<< endl;
    myArr2.readFile(2);
    myArr2.hitungMean(2);
    //End of Part untuk Float

    return 0;
}