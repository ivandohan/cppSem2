/*
    Nama File       : 211402067_Ivandohan_tugas3.cpp
    Nama            : Ivandohan Samuel Siregar
    NIM             : 211402067

    === Diamond Inheritance ===
*/

#include <iostream>
#include <string>

using namespace std;

class AndroidPhone {
public:
    bool calendarAutoSystem;
    bool locationStat;
    AndroidPhone(bool a, bool b){
        this->calendarAutoSystem = a;
        this->locationStat = b;
    };
    // AndroidPhone(){
    //     this->locationStat = true;
    //     this->calendarAutoSystem = true;
    // }
};

class Maps:virtual public AndroidPhone {
public:
    string location;
    Maps(bool a, bool b):AndroidPhone(a,b){
        if(locationStat){
            location = "FASILKOM-TI, Medan";
        }else {
            cout << "Error, izin lokasi tidak diaktifkan!\n" << endl;
        }
    }
};

class Calendar:virtual public AndroidPhone {
public:
    string tanggal;
    Calendar(bool a, bool b):AndroidPhone(a, b){
        if(calendarAutoSystem){
            tanggal = "Selasa, 18 April 2022";
        }else {
            cout << "Error, Izin Kalender tidak diaktifkan!\n" << endl;
        }
    }

};

class GojekApp:public Maps, public Calendar {
public:
    bool status_device;
    GojekApp(bool a, bool b):Maps(a, b), Calendar(a,b), AndroidPhone(a,b){
        if(location.empty() && tanggal.empty()){
            cout << "Mohon berikan izin akses lokasi dan kalender" << endl;
        }else{
            status_device = true;
        }
    }

    void indexGojek(){
        if(status_device){
            cout << "=========" << endl;
            cout << "G O J E K" << endl;
            cout << "=========\n" << endl;
            cout << "Selamat datang di Gojek. Mau pesan apa hari ini?" << endl;
            cout << "Tanggal                    : " << tanggal << endl;
            cout << "Anda saat ini berada di    : " << location << endl;
        }else {
            cout << ":(" << endl;
            cout << "Mohon beri izin akses lokasi dan kalender" << endl;
        }
    }
};


int main()
{

    system("cls");
    GojekApp user(1,0); //Izin kalender off, lokasi on;

    user.indexGojek();

    return 0;
}