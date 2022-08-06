/*
        Nama File       : Kel6_UAS.cpp
        Kelompok 6      :
            1. Ivandohan Samuel Siregar - 211402067
            2. Amanda Bendicta Sembiring - 211402082
            3. Aurelia Priscilia Simamora - 211402091
            4. Adelweys Margaretha Sijabat - 211402103

        ===== Mini Project 3 (UAS) : Mencari posisi di mana jumlah 2 elemen sama dengan inputan user =====
*/

/*
        Untuk memperkompleks program, maka kami menambahkan fitur-fitur lain di luar soal.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

class MiniProject {
private:
    vector<int> vect; // Deklarasi vector
    vector<int>::iterator it; // Deklarasi iterator vector untuk fitur tambahan
    
public:

    void generateBilAcak(char methodIndex){ // Melakukan generate bilangan random dengan batas 0-20
        srand(time(0));                     // Ada 2 method sebagai indikator :
        if(methodIndex == 's'){             // 's' untuk saat awal program dijalankan (start)
            for(int i = 0; i < N; i++){
                int rd = rand() % 20;
                vect.push_back(rd);
            }
        }else if(methodIndex == 'r'){       // 'r' untuk fitur generate ulang (regenerate)
            vect.clear();                   // seluruh elemen vector akan dihapus terlebih dahulu
            for(int i = 0; i < N; i++){
                int rd = rand() % 20;
                vect.push_back(rd);
            }
        }
    }

    void checkSum(int userSum){            // Melakukan pengecekan untuk inputan user (Menu opsi ke-2)
        cout << "Index ke-| Value" << endl;
        for(int i = 0; i < vect.size(); i++)                    // Mengambil vect[i] sebagai acuan
            for(int j = 0; j < vect.size(); j++)                // Mengambil vect[j] sebagai lawan banding
                if((vect[i] + vect[j]) == userSum)              // Jika ditemukan sesuai dengan kondisi, maka print posisi dan value
                    cout << "( " << i << ", " << j << " ) = "
                        << "( " << vect[i] << ", " << vect[j] << " )" << endl;
        
        system("pause");
    }

    void displayVector(){                   // Menampilkan isi data vector
        cout << "Random Number : ";
        cout << "{ ";
        for(int i = 0; i < vect.size(); i++){
            cout << vect[i] << ", ";
        }
        cout << " }" << endl;
    }

    void findElementVector(int element){    // Mencari posisi elemen yang diinputkan user (Menu opsi ke-1)
        it = find(vect.begin(), vect.end(), element);       // Mencari elemen di vector menggunakan vector iterator yang dideklarasikan sebelumnya
        if (it != vect.end()){                              // dan dikombinasikan dengan fungsi algoritma find()
            cout << "<SUCCESS> Elemen " << element <<" ditemukan pada posisi : " ;
            cout << it - vect.begin() << " (terhitung dari 0) \n" ;
        }
        else
            cout << "<ERROR> Elemen tidak ditemukan\n\n";

        system("pause");
    }

    void addElementVector(int element){     // Menambahkan elemen baru vector
        vect.push_back(element);            // Posisi elemen baru akan ada di index terbaru (terakhir saat ini + 1)

        cout << "<SUCCESS> Elemen " << element << " berhasil ditambahkan!" << endl;
        system("pause");
    }

    void deleteElementVector(int index){            // Menghapus salah satu elemen vector
        if(index < vect.size()){                    // Cek terlebih dahulu ketersediaan posisi (index) vector, jangan sampai out of range
            vect.erase(vect.begin() + (index));     // Jika sesuai maka hapus elemen yang ada di posisi tersebut
            cout << "<SUCCESS> Elemen pada index ke-" << index << " berhasil dihapus!" << endl;
        }else {                                     // Jika tidak sesuai, tampilkan pesan error
            cout << "<ERROR> Elemen pada index ke-" << index << " tidak ditemukan!" << endl;
        }

        system("pause");
    }

    void updateElementVectorByIndex(int index, int element){    // Mengubah salah satu element vector sesuai dengan posisi yang diberikan user
        if(index < vect.size()){                                // Cek terlebih dahulu ketersediaan posisi (index) vector
            vect.at(index) = element;                           // Jika sesuai, maka ubah sesuai dengan value baru dari user
            cout << "<SUCCESS> Elemen " << element << " pada posisi ke-" << index << " sukses diubah!" << endl;
        }else{                                                  // Jika index out of range, maka tampilkan pesan error
            cout << "<ERROR> Elemen pada index ke-" << index << " tidak ditemukan!" << endl;
        }

        system("pause");
    }
};

char displayMenu();        // Deklarasi fungsi menu container

int main(){
    MiniProject mp;                 // Menurunkan sebuah object
    char opsi;                      // Opsi untuk menu
    int userInput, userInput2;      // Penampung value inputan user

    mp.generateBilAcak('s');        // Melakukan generate bilangan dengan methodIndex 's' (start)

    do {
        system("CLS");
        cout << "\n\n";         // Kop Menu
        cout << "============ Mini Project : Cari Bilangan Di Vector ============" << endl;
        cout << "----------------------------------------------------------------" << endl;
        mp.displayVector();     // Menampilkan isi vector saat ini
        cout << "----------------------------------------------------------------" << endl;
        opsi = displayMenu();   // Memanggil fungsi yang berisikan daftar menu.

        switch (opsi)           // Menentukan alur eksekusi dari tiap-tiap opsi
        {
            case '1':
                cout << "Input elemen   = "; cin >> userInput;  // Input elemen yang akan dicari keberadaannya
                mp.findElementVector(userInput);                // Fungsi pencari dipanggil
            break;

            case '2':
                cout << "Input elemen (jumlah 2 bilangan) = "; cin >> userInput; // Input elemen yang akan dicek kesesuaiannya
                cout << "\n";
                mp.checkSum(userInput);                                          // Fungsi pengecek dipanggil 
            break;

            case '3':
                cout << "Input elemen   = "; cin >> userInput;  // Input elemen yang akan ditambahkan
                mp.addElementVector(userInput);                 // Fungsi penambah elemen dipanggil
            break;

            case '4':
                cout << "------------------------------------------" << endl;
                cout << "<WARNING> Posisi terhitung dari 0 sampai n" << endl;   // Peringatan bahwa index vector dimulai dari 0
                cout << "------------------------------------------" << endl;
                cout << "Input posisi   = "; cin >> userInput;                  // Input posisi yang akan dihapus
                mp.deleteElementVector(userInput);                              // Fungsi penghapus elemen dipanggil
            break;

            case '5':
                cout << "------------------------------------------" << endl;
                cout << "<WARNING> Posisi terhitung dari 0 sampai n" << endl;   // Peringatan bahwa index vector dimulai dari 0
                cout << "------------------------------------------" << endl;
                cout << "Input posisi       = "; cin >> userInput;              // Input posisi yang akan diubah
                cout << "Input elemen baru  = "; cin >> userInput2;             // Input elemen baru sebagai pengganti
                mp.updateElementVectorByIndex(userInput, userInput2);           // Fungsi pengubah elemen dipanggil
            break;

            case '6':
                cout << "Gerating..." << endl;                               // Melakukan generate bilangan random baru
                mp.generateBilAcak('r');                                     // Memanggil fungsi generate dengan methodIndex 'r' (regenerate)
                cout << "<SUCCSESS> Elemen berhasil digenerate!" << endl;
            break;
        }

    }while(opsi != 'e' && opsi != 'E');         // Terminate program jika opsi bernilai 'e' ataupun 'E'

    cout << "\n\n";
    cout << "Bye-bye" << endl;

    return 0;
}

char displayMenu(){      // Fungsi yang berisikan jenis-jenis fitur program
    char opsi;

    cout << "================================================================" << endl;
    cout << "| 1. Cari elemen di vector                                     |" << endl;
    cout << "| 2. Cari posisi di mana jumlah 2 vector sama dengan inputan   |" << endl;
    cout << "| 3. Tambah sebuah elemen vector                               |" << endl;
    cout << "| 4. Hapus salah satu elemen vector berdasarkan posisi         |" << endl;
    cout << "| 5. Update value salah satu elemen vector berdasarkan posisi  |" << endl;
    cout << "| 6. Generate ulang bilangan random untuk vector               |" << endl;
    cout << "================================================================" << endl;
    cout << "Pilihan [1-5] or EXIT [e] : "; cin >> opsi;        // Ambil pilihan user dan tampung ke variable opsi,

    return opsi;                                                // lalu kembalikan nilainya ke tempat fungsi dipanggil.
}
