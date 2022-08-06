/*
    Nama File       : 211402067_Ivandohan_tugas2a.cpp
    Nama            : Ivandohan Samuel Siregar
    NIM             : 211402067

    === Program dengan Metode Enkapsulasi ===
    === Study kasus pada Game Mobile Legends === 

*/
#include <iostream>
#include <string>

using namespace std;

class MobileLegends {
private:
    string nickname;
    int jlh_diamond;
//  Intinya adalah melindungi variabel dengan membuatnya bersifat private;
//  untuk akses ke variabel itu sendiri, kita bisa menggunakan metode setter dan getter

public:
    // Getter
    void showNickname(){cout << "Nama    : " << nickname << endl;}
    void showDiamond(){cout << "Diamond : " << jlh_diamond << endl;}
    
    //Setter
    MobileLegends(string a, int b){
        this->nickname = a;
        this->jlh_diamond = b;
    }
    
    void changeNikcname(){
        if(jlh_diamond >= 250){
            cin.ignore();
            cout << "Masukkan nama baru : ";
            getline(cin,nickname);
            cout << "====================" << endl; 
            cout << "Nama baru anda : " << nickname << endl;
        }else {
            cout << "Diamond anda tidak cukup. Silahkan top up diamond terlebih dahulu" << endl;
            topUpDiamond();
        }
    }

    void topUpDiamond(){
        int opsi1, opsi2;

        cout << "\n====================" << endl; 
        cout << "Pilih Jumlah Top Up" << endl;
        cout << "1. 11 diamond (Rp3.000)" << endl;
        cout << "2. 50 diamond (Rp15.000)" << endl;
        cout << "3. 250 diamond (Rp75.000)" << endl;
        cout << "4. 500 diamond (Rp149.000)" << endl;
        cout << "Pilihan [1-4] : ";
        cin >> opsi1;
        
        //Ini hanya contoh kecil saja, tentunya konfirmasi pembayaran aslinya jauh lebih ketat lagi.
        cout << "\nKonfirmasi Pembayaran" << endl;
        cout << "1. Dana" << endl;
        cout << "2. Ovo" << endl;
        cout << "3. Gopay" << endl;
        cout << "4. Pulsa" << endl;
        cout << "Pilihan [1-4] : ";
        cin >> opsi2;

        if(opsi2 >= 1){
            if(opsi1 == 1){
                jlh_diamond += 11;
            }else if(opsi1 == 2){
                jlh_diamond += 50;
            }else if(opsi1 == 3){
                jlh_diamond += 250;
            }else if(opsi1 == 4){
                jlh_diamond += 500;
            }
        }else {
            cout << "Pembayaran Gagal" << endl;
        }
        cout << "====================\n" << endl; 

        showDiamond();
        changeNikcname();
    }
};

int main()
{
    char opsi;
    MobileLegends user("EVOS GALANG", 20);

    label_continue1:
    system("cls");
    cout << "=== Profile Akun ===" << endl;
    user.showNickname(); //getter
    user.showDiamond(); //getter

    cout << "Ganti Nama (250 diamond) ? [y/n] : ";
    cin >> opsi;

    if(opsi == 'y' || opsi == 'Y'){
        user.changeNikcname(); //setter
    }else if(opsi == 'n' || opsi == 'N'){
        goto label_continue2;
    }else {
        goto label_continue1;
    }

    label_continue2:

    cout << "\n\nSelamat Bermain" << endl;
    return 0;
}