/*
        Nama File       : 211402067_Ivandohan_tugas4.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        === Menggabungkan 2 File .txt ===
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>

using namespace std;

int main()
{
    string a;
    fstream file1, file2, file3;
    file1.open("File 1.txt", ios::in | ios::out);
    file2.open("File 2.txt", ios::in | ios::out);
    file3.open("File 3.txt", ios::in | ios::out);

    system("cls");
    cout << "Memulai penggabungan isi file...." << endl;
    sleep(2);
    file3 << "=== Isi File 1.txt ===" << endl;
    //Pemindahan isi file 1 ke file 3(file terbaru)
    while(getline(file1,a)){
        file3 << a << endl;
    }
    file3 << "=== Akhir Isi File 1.txt ===\n" << endl;

    file3 << "=== Isi File 2.txt ===" << endl;
    //Pemindahan isi file 2 ke file 3(file terbaru)
    while(getline(file2,a)){
        file3 << a << endl;
    }
    file3 << "=== Akhir Isi File 1.txt ===" << endl;

    cout << "=== Sukses ===" << endl;
    file1.close();
    file2.close();
    file3.close();
    system("pause"); 
    return 0;
}

