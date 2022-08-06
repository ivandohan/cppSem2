/*
        Nama File       : Kel6_02.cpp
        Kelompok 6      :
            1. Ivandohan Samuel Siregar - 211402067
            2. Amanda Bendicta Sembiring - 211402082
            3. Aurelia Priscilia Simamora - 211402091
            4. Adelweys Margaretha Sijabat - 211402103

        ===== Mini Project 2 : Pilih dan download souce code yang tersedia =====
*/

#include <iostream>
#include <windows.h>
#include <cstring>
#include <fstream>

using namespace std;

struct User {
    int user_id;
    char username[20];
    char password[20];
    char fullName[50];
}u[30];

class LoginRegister {
protected:
    int user_no;
    bool check;
    char uName[20], pword[20] ;

public:
    char fName[50];
    void getUserno(){
        fstream f("Kel6_02.bin", ios::in | ios::binary);
        if (f.is_open()){
		    cout << "Database ditemukan!" << endl;
	    } else {
            cout << "Database tidak ditemukan, membuat database baru..." << endl;
            f.close();
            f.open("Kel6_02.bin", ios::trunc | ios::in | ios::out | ios::binary);
	    }
        for(int i = 0; !f.eof(); i++){
            f.read((char*)&u[i], sizeof(u[i]));
            user_no = i;
        }
        f.close();
    }

    int signUp(){
        LoginRegister::getUserno();
        fstream inputData;
        inputData.open("Kel6_02.bin", ios::binary | ios::out | fstream::app);

        if(!inputData){
            cout << "ERROR <001> : Tidak dapat membuka file" << endl;
        }
        cin.ignore();
        cout << "=== Registrasi Akun ===" << endl;
        cout << "Your Name : ";
        cin.getline(u[user_no].fullName, 50);
        cout << "Username  : "; 
        cin >> u[user_no].username;
        cout << "Password  : "; 
        cin >> u[user_no].password;

        u[user_no].user_id = user_no;

        inputData.write(reinterpret_cast<char*>(&u[user_no]), sizeof(u[user_no]));
        if(!inputData.good()){
            cout << "ERROR <002> : Kesalahan dalam interaksi dengan file" << endl;
            return 0;
        }
        cout << "Registrasi Berhasil!\n" << endl;
        user_no++;
        inputData.close();

        system("pause");
        return 1;
    }

    int signIn(){
        LoginRegister::getUserno();
        fstream getData;
        getData.open("Kel6_02.bin", ios::binary | ios::in);
        if(!getData){
            cout << "ERROR <001> : Tidak dapat membuka file" << endl;
        }
        while(true){
            system("cls");
            check = false;
            cout << "=== Login ===" << endl;
            cout << "Username : "; cin >> uName;
            cout << "Password : "; cin >> pword;
            getData.seekg(0);

            for(int i = 0; i < user_no; i++){
                getData.read(reinterpret_cast<char*>(&u[i]), sizeof(u[i]));
                // cout << "Username = " << u[i].username << endl;
                // cout << "Password = " << u[i].password << endl;
                if(strcmp(uName, u[i].username) == 0 && strcmp(pword, u[i].password) == 0){
                    strcpy(fName, u[i].fullName);
                    check = true;
                    break;
                }
            }

            if(check == false){
                cout << "ERROR <003> : Username atau Password tidak tepat" << endl;
                system("pause");
            }else {
                cout << "Login Berhasil!" << endl;
                break;
            }
        }
        system("pause");
        return 1;
    }
};

void menuSourceCode(char[20]);

int main(){
    LoginRegister a;
    char _SESSION_NAME[50];
    char opsi;

    system("cls");
    cout << "=======================================================================" << endl;
    cout << "|    Mini Project 2 : Pilih dan download souce code yang tersedia     |" << endl;
    cout << "=======================================================================" << endl;
    cout << "\n\n";
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "| Keterangan : Bila program tetap error saaat login, silahkan update  |" << endl;
    cout << "| compiler anda ke versi yang terbaru. Kemungkinan error dikarenakan  |" << endl;
    cout << "| element array yang kosong akan menjadi garbage mutlak. Pada versi   |" << endl;
    cout << "| tebaru, garbage pada elemen kosong array dapat diignore.            |" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    cout << "\n\n";
    system("pause");

    label_start_login:
    system("cls");
    cout << "=== Silahkan Login Terlebih Dahulu! ===" << endl;
    cout << "Sudah punya akun? [y/n] or EXIT [e] : "; cin >> opsi;

    if(opsi == 'y'){
        cout << "-- Silahkan login" << endl;
        cout << "\n\n";
        if(a.signIn()){
            strcpy(_SESSION_NAME, a.fName);
        }
        system("cls");
    }else if(opsi == 'n'){
        cout << "\n\n";
        a.signUp();
        system("cls");
        cout << "-- Silahkan login kembali!" << endl;
        cout << "\n\n";
        if(a.signIn()){
            strcpy(_SESSION_NAME, a.fName);
        }
        system("cls");
    }else if(opsi == 'e'){
        goto label_end;
    }else{
        cout << "Invalid Input!" << endl;
        system("pause");
        goto label_start_login;
    }

    cout << "YEAY BERHASIL" << endl;
    cout << "Welcome, " << _SESSION_NAME << endl;
    cout << "\n" << endl;
    cout << "Tunggu Loading..." << endl;
    Sleep(3000);

    menuSourceCode(_SESSION_NAME);

    label_end:
    cout << "See you next time" << endl;
    return 0;
}

void menuSourceCode(char name[50]){
    char opsi, opsi2;
    char downloadUrl[100];

    label_start:
    system("CLS");
    cout << "Hi, " << name << "!" << endl;
    cout << "\n\n";
    cout << "============= Pilihan Source Code untuk Didownload =============" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Keterangan : Fitur demo untuk source code tidak tersedia.    |" << endl;
    cout << "| Silahkan lakukan demo secara manual setelah download file.   |" << endl;
    cout << "| File source code disimpan di Google Drive.                   |" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "================================================================" << endl;
    cout << "| 1. Program Book Store Sederhana (bookstore.cpp)              |" << endl;
    cout << "| 2. Program Booking Hotel Sederhana (hotel.cpp)               |" << endl;
    cout << "| 3. Program Konversi Suhu Sederhana (konversi_suhu.cpp)       |" << endl;
    cout << "| 4. Program Order Laundry (laundry.cpp)                       |" << endl;
    cout << "| 5. Program Order Makanan dari Sebuah Restorant (restoran.cpp)|" << endl;
    cout << "================================================================" << endl;
    cout << "Pilihan [1-5] or EXIT [e] : "; cin >> opsi;

    switch (opsi)
    {
    case '1':
        cout << "Downloading File 1..." << endl;
        strcpy(downloadUrl, "https://drive.google.com/file/d/1BlM5K5Rmi3uI0wwwkaD25XaKoJKTG9Ks/view?usp=sharing");
        ShellExecuteA(NULL, "open", downloadUrl, NULL, NULL, SW_SHOWNORMAL);
        cout << "\nDownload Sukses" << endl;
        break;

    case '2':
        cout << "Downloading File 2..." << endl;
        strcpy(downloadUrl, "https://drive.google.com/file/d/1SXWyL-ZMrZxgLuJnO0cwTkGHC_qS4faS/view?usp=sharing");
        ShellExecuteA(NULL, "open", downloadUrl, NULL, NULL, SW_SHOWNORMAL);
        cout << "\nDownload Sukses" << endl;
        break;

    case '3':
        cout << "Downloading File 3..." << endl;
        strcpy(downloadUrl,"https://drive.google.com/file/d/1v1VvS_zLpJ50m3XB3fOjLz-cJ07bd6t4/view?usp=sharing");
        ShellExecuteA(NULL, "open", downloadUrl, NULL, NULL, SW_SHOWNORMAL);
        cout << "\nDownload Sukses" << endl;
        break;

    case '4':
        cout << "Downloading File 4..." << endl;
        strcpy(downloadUrl,"https://drive.google.com/file/d/1xIMe-7VevH2yo0kLu6QhNS6MzxAfvnVn/view?usp=sharing");
        ShellExecuteA(NULL, "open", downloadUrl, NULL, NULL, SW_SHOWNORMAL);
        cout << "\nDownload Sukses" << endl;
        break;

    case '5':
        cout << "Downloading File 5..." << endl;
        strcpy(downloadUrl,"https://drive.google.com/file/d/16HjYEaS0RDvf9mkoohU_zZ6fhvr6W_2e/view?usp=sharing");
        ShellExecuteA(NULL, "open", downloadUrl, NULL, NULL, SW_SHOWNORMAL);
        cout << "\nDownload Sukses" << endl;
        break;

    case 'e':
        goto label_end;
        break;
    
    default:
        cout << "Invalid input!" << endl;
        break;
    }

    label_tryagain:
    cin.ignore();
    cout << "Donwload Lagi? [y/n] : "; cin >> opsi2;
    if(opsi2 == 'y'){
        goto label_start;
    }else if(opsi2 == 'n'){
        goto label_end;
    }else {
        goto label_tryagain;
    }

    label_end:
    cout << "Bye-bye" << endl;
}