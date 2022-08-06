/* Nama Kelompok :
1. Maria Anggraini Natio      211402052
2. Andre Gozali               211402100
3. Gihon Sinaga               211402124
4. Tobias Davino Purba        211402148
*/

// Ujian Akhir Semester Pemrograman Berorientasi Objek

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#define N 10

using namespace std;

template <class T>
class UAS {
public:
    T opsi;
    vector<T> vect;

    void genBilAcak(){                  // menghasilkan bilangan acak 
        srand(time(0));
        for(int i = 0; i < N; i++){     // melakukan perulangan banyak angka sebanyak N
            T rd = rand() % N;          // menghasilkan angka random yang di modulo dengan N
            vect.push_back(rd);         // mem push elemen angka random ke dalam vektor
        }
    }

    void cekHasil(int hasil){                       // mencari dan menampilkan kedua bilangan yang hasilnya sesuai inputan user
        cout << "\nHasil" << endl;
        for(int i = 0; i < vect.size(); i++)        
            for(int j = 0; j < vect.size(); j++)    
                if((vect[i] + vect[j]) == hasil)    // menampilkan hasil dengan mencari elemen-elemen i ditambah j, menghasilkan sesuai inputan user
                    cout << "(" << i << ", " << j << ") = "
                        << "(" << vect[i] << " + " << vect[j] << ")" << endl;
    }

    void displayNumber(){
        genBilAcak();           // menampilkan bilangan bilangan acak yang dihasilkan
        cout << "\nBilangan Acak" << endl;
        cout << "{ ";
        for(int i = 0; i < N; i++){
            cout << "{" << vect[i] << "} ";
        }
        cout << "}" << endl;
    }
};

int main(){
    UAS<int> X;
    int opsi;

    system("cls");
    cout << "Ujian Akhir Semester Pemrograman Berorientasi Objek" << endl;

    cout << "Berikan sebuah bilangan : "; cin >> opsi;      // meminta inputan user
    X.displayNumber();                                      // menampilkan bilangan acak

    cout << "\nBilangan berjumlah " << opsi << " ada di posisi : " << endl;
    X.cekHasil(opsi);                                                           // menampilkan elemen dan letak elemen yang memiliki hasil sesuai inputan user

    return 0;
}
