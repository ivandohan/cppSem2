/*
    Nama File       : 211402067_Ivandohan_tugas2a.cpp
    Nama            : Ivandohan Samuel Siregar
    NIM             : 211402067

    === Program dengan Metode Abstraksi ===
    === Study kasus pada Game Mobile Legends === 

*/

#include <iostream>
#include <string>

using namespace std;

class MobileLegends {
public:
    virtual void banHero()=0;
    virtual void pickHero()=0;
    virtual void rekomendasiHero()=0;
    virtual void chat()=0;
};

// Intinya adalah user tidak perlu tau bagaimana mekanisme di balik layar terkait fitur-fitur itu.
// user hanya perlu tau bagaimana menggunakan fitur-fitur yang disediakan, bukan mekanisme dibalik layar.

class Ranked:public MobileLegends {
private:
    int id_hero;
    string pesan;
public:
    void banHero(){
        cout << "Please Ban a Hero....." << endl;
        cout << "1. Nana\n2. Angela" << endl;
        cout << "Pilihan [1-2] = ";
        cin >> id_hero;

        if(id_hero == 1){
            cout << "Nana sukses dibanned" << endl;
        }else if(id_hero == 2){
            cout << "Angela sukses dibanned" << endl;
        }else {
            cout << "Error [Hero tidak tersedia]" << endl;
        }
    }

    void pickHero(){
        cout << "Please Pick a Hero....." << endl;
        cout << "1. Alucard\n2. Lancelot" << endl;
        cout << "Pilihan [1-2] = ";
        cin >> id_hero;

        if(id_hero == 1){
            cout << "Alucard sukses dipilih" << endl;
        }else if(id_hero == 2){
            cout << "Lancelot sukses dipilih" << endl;
        }else {
            cout << "Error [Hero tidak tersedia]" << endl;
        }
    }

    void rekomendasiHero(){
        cout << "Rekomendasikan Hero Anda" << endl;
        cout << "1. Alucard\n2. Lancelot" << endl;
        cout << "Pilihan [1-2] = ";
        cin >> id_hero;

        if(id_hero == 1){
            cout << "Saya ingin menggunakan Alucard, win rate 49.1%" << endl;
        }else if(id_hero == 2){
            cout << "Saya ingin menggunakan Lancelot, win rate 37.5%" << endl;
        }else {
            cout << "Error [Hero tidak tersedia]" << endl;
        }
    }
    
    void chat(){
        cout << "Chat" << endl;
        cout << "1. Saya ke Hutan" << endl;
        cout << "2. Saya ke Exp Lane" << endl;
        cout << "3. Kita butuh tank" << endl;
        cout << "4. Kita butuh mage" << endl;
        cout << "Tim : ";
        cin.ignore();
        getline(cin,pesan);
        cout << "=====================" << endl;



        if(pesan == "1"){
            cout << "\n\nYou : Saya ke Hutan" << endl;
        }else if(pesan == "2") {
            cout << "\n\nYou : Saya ke Exp Lane" << endl;
        }else if(pesan == "3") {
            cout << "\n\nYou : Kita butuh tank" << endl;
        }else if(pesan == "4") {
            cout << "\n\nYou : Kita butuh mage" << endl;
        }else {
            cout << "\n\nYou : " << pesan << endl;
        }
    }
};

int main()
{
    MobileLegends* user = new Ranked();

    system("cls");

    cout << "=== Ranked Game ===" << endl;
    cout << "Ban Hero" << endl;
    user->banHero();
    cout << "===================\n" << endl;
    user->rekomendasiHero();
    cout << "===================\n" << endl;
    cout << "Pick Hero" << endl;
    user->pickHero();
    cout << "===================\n" << endl;
    cout << "\n\n" << endl;
    user->chat();

    cout << "\nWelcome to Mobile Legends\n" << endl;
    return 0;
}