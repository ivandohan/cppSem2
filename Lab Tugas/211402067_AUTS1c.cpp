/*
        Nama File   : 211402067_AUTS1c.cpp
        NIM         : 211402067
        Nama        : Ivandohan Samuel Siregar
        
*/

#include <iostream>
#include <ctime>
#define N 10

using namespace std;

class BilanganAcak {
    private:
        int bilAcak[N];
    public:
        int n;
        BilanganAcak();

        void printArray();
        void cekPosisi(int);
        ~BilanganAcak(){}
};

BilanganAcak::BilanganAcak(){
    srand(time(NULL));
    for(int i=0; i<N; i++)
        bilAcak[i] = rand() % N;
}

void BilanganAcak::printArray(){
    for(int i=0; i<N; i++)
        cout << bilAcak[i] << " ";
    cout << endl;
}

void BilanganAcak::cekPosisi(int n) {
    int jlh, flag = 0;
    cout << "Ada di posisi : ";
    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            jlh = bilAcak[i] + bilAcak[j];
            if(jlh == n) {
                cout << "(" << i+1 << "," << j+1 << ") " ;
                flag = 1;
            }
        }
    }
    if(flag != 1) {
        cout << "Elemen Berjumlah " << n << " tidak ada di dalam bilAcak" << endl;
    }
}

int main()
{
    int a;
    BilanganAcak myArr;
    system("CLS");
    cout << "== Program Mencari Elemen di BilanganAcak Sejumlah Inputan ==\n" << endl;
    cout << "Input Nilai : ";
    cin >> a;

    myArr.printArray();
    myArr.cekPosisi(a);

    return 0;
}