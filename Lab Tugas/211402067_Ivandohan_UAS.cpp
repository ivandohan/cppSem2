/*
        Nama        : Ivandohan Samuel Siregar
        NIM         : 211402067

        === UAS : Program Kalkulator Sederhana ===
*/

/*
        1. Template class => mengimplementasikan class calculator sebagai template class
        2. Vector => untuk menyimpan data inputan user. Setiap kali kalkulator dibuka,
                    maka vector akan dibersihan menggunakan clear();
        3. File Handling => untuk menyimpan dan menampilkan struktu menu awal
*/


// Isi File .txt dapat dibuat dan dicopas manual, dikarenakan format pengumpulan elearning
// hanya menerima file .cpp
/*
===============================================================
        Kalkulator Sederhana : Ivandohan Samuel Siregar
===============================================================
                            MENU                               
===============================================================
        1. Penjumlahan
        2. Pengurangan
        3. Perkalian
        4. Pembagian
===============================================================
.                                                             .
===============================================================
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <class T> // Implementasi Template Class
class Calculator {
private:
    int a;
    T x,y,result;
    vector<T> value; // Implementasi Vector
    char choice;
    string fileMenu = "211402067_Ivandohan_UAS.txt"; // Implementasi File Handling
    string copasTxt; // Implementasi File Handling
    fstream myMenu; // Implementasi File Handling
public:
    void penjumlahan(){
        result = value.front() + value.back(); // Implementasi Vector
        cout << "Hasil : " << result << endl;
    }

    void pengurangan(){
        result = value.front() - value.back(); // Implementasi Vector
        cout << "Hasil : " << result << endl;
    }

    void perkalian(){
        result = value.front() * value.back(); // Implementasi Vector
        cout << "Hasil : " << result << endl;
    }

    void pembagian(){
        result = value.front() / value.back(); // Implementasi Vector
        cout << "Hasil : " << result << endl;
    }

    void setData(){
        cout << "Bilangan Pertama   : ";
        cin >> x;
        cout << "Bilangan Kedua     : ";
        cin >> y;

        value.push_back(x); // Implementasi Vector
        value.push_back(y); // Implementasi Vector
    }

    void menu(){
        myMenu.open(fileMenu, ios::in); // Implementasi File Handling
        while(getline(myMenu, copasTxt)){
            cout << copasTxt << endl; // Implementasi File Handling
        }
        myMenu.close(); // Implementasi File Handling
    }

    void subDriver(){
        cout << "Pilihan [1-4] : ";
        cin >> a;
        switch(a){
        case 1:
            setData();
            penjumlahan();
            break;
        case 2:
            setData();
            pengurangan();
            break;
        case 3:
            setData();
            perkalian();
            break;
        case 4:
            setData();
            pembagian();
            break;
        default:
            cout << "Invalid input. Coba Lagi!" << endl;
        }
    }

    void driver(){
    do {
        system("CLS");
        menu();
        subDriver();
        value.clear();
        cout << "Buka kalkulator lagi? [y/n] : ";
        cin >> choice;
    }
    while(choice != 'n' || choice != 'N');
    }

};

int main () {
    Calculator<double> objCal; //Implementasi Template Class
    objCal.driver();
    return 0;
}