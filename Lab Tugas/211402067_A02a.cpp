/*
    Nama File   : 211402067_A02a.cpp
    Nama        : Ivandohan Samuel Siregar
    NIM         : 211402067
*/


#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#define PI 3.14159
#define KUBIK(X) (X * X * X)
#define KUADRAT(X) (X * X)

using namespace std;

class BangunGeometri {
public:
    double luas, volume, besaran;

    BangunGeometri(double besaran){
        this->besaran = besaran;
    }

    virtual void ambilLuas(){
        cout << "Luas      = " << luas << endl;
    }

    virtual void ambilVolume(){
        cout << "Volume    = " << volume << endl;
    }

    ~BangunGeometri(){}
};

class Kubus:public BangunGeometri {
public:
    Kubus(double besaran):BangunGeometri(besaran){
        luas = 0;
        volume = 0;
    }

    void hitungVolume(){
        volume = KUBIK(besaran);
    }

    void hitungLuas(){
        luas = (KUADRAT(besaran)) * 6;
    }

    ~Kubus(){}
};


class Balok:public BangunGeometri {
public:
    double tinggi, lebar, keliling;

    Balok(double besaran, double lebar, double tinggi)
    :BangunGeometri(besaran) {
        luas = 0;
        volume = 0;
        
        this->tinggi = tinggi;
        this->lebar = lebar;
    }

    void hitungLuas(){
        keliling = (2 * besaran) + (2 * lebar);
        luas = ((besaran * lebar) * 2) + (keliling * tinggi) ;
    }

    void hitungVolume(){
        volume = (besaran * lebar) * tinggi;
    }

    ~Balok(){}
};

class Piramid:public BangunGeometri {
public:
    double lebar, tinggi;
    Piramid(double besaran, double lebar, double tinggi)
    :BangunGeometri(besaran){
        volume = 0;
        luas = 0;

        this->tinggi = tinggi;
        this->lebar = lebar;
    }

    void hitungLuas(){
        luas = (besaran * lebar) + (sqrt(KUADRAT(tinggi) + KUADRAT((besaran/2))) * lebar) + (sqrt(KUADRAT(tinggi) + KUADRAT(lebar/2)) * besaran);
    }

    void hitungVolume(){
        volume = ((besaran * lebar) * tinggi) / 3;
    }

    ~Piramid(){}
};

class Bola: public BangunGeometri {
public:
    Bola(int besaran):BangunGeometri(besaran){
        volume = 0;
        luas = 0;
    }

    void hitungLuas(){
        luas = (KUADRAT(besaran)) * PI * 4;
    }

    void hitungVolume(){
        volume = ((KUBIK(besaran)) * PI * 4) / 3;
    }

    ~Bola(){}
};

int getOption();
void kubus();
void balok();
void piramid();
void bola();

int main()
{
    label_start:
    int pilihan = getOption();
    char opsi;

    if(pilihan == 1){
        kubus();
        goto label_start;
    } else if(pilihan == 2){
        balok();
        goto label_start;
    } else if(pilihan == 3){
        piramid();
        goto label_start;
    } else if(pilihan == 4){
        bola();
        goto label_start;
    } else if(pilihan == 5){
        goto label_stop;
    }

    label_stop:
    cout << "E N D" << endl;
    return 0;
}

int getOption()
{
    int pilihan;
    system("CLS");
    cout << "=== Bangun Ruang ===" << endl;
    cout << "********************" << endl;
    cout << "1. Kubus" << endl;
    cout << "2. Balok" << endl;
    cout << "3. Piramid" << endl;
    cout << "4. Bola" << endl;
    cout << "5. FINISH." << endl;
    cout << "\n**************************" << endl;
    cout << "Pilihan [1-5] ? : ";
    cin >> pilihan;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return pilihan;
}

void kubus()
{
    double sisi;
    char opsi;

    system("CLS");
    cout << "== K U B U S ==" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Sisi = ";
    cin >> sisi;

    Kubus k = Kubus(sisi);
    k.hitungLuas();
    k.hitungVolume();

    
    //Polymorphism
    BangunGeometri* BG = &k;
    BG->ambilLuas();
    BG->ambilVolume();
    
    label_continue2:
    cout << "\nLagi? (y/n)...";
    cin >> opsi;

    if ( (opsi == 'y') | (opsi == 'Y')){
        goto label_continue1;
    } else if ((opsi == 'n') | (opsi == 'N')){
        goto label_stop;
    } else {
        goto label_continue2;
    }
    label_stop:

    cout << "OKE" << endl;

}

void balok()
{
    double panjang, lebar, tinggi;
    char opsi;

    system("CLS");
    cout << "== B A L O K ==" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Panjang = ";
    cin >> panjang;
    cout << "Lebar   = ";
    cin >> lebar;
    cout << "Tinggi  = ";
    cin >> tinggi;

    Balok b = Balok(panjang, lebar, tinggi);
    b.hitungLuas();
    b.hitungVolume();
    
    //Polymorphism
    BangunGeometri* BG = &b;
    BG->ambilLuas();
    BG->ambilVolume();

    label_continue2:
    cout << "\nLagi? (y/n)...";
    cin >> opsi;

    if ( (opsi == 'y') | (opsi == 'Y')){
        goto label_continue1;
    } else if ((opsi == 'n') | (opsi == 'N')){
        goto label_stop;
    } else {
        goto label_continue2;
    }
    label_stop:

    cout << "OKE" << endl;
    
}

void piramid()
{
    double panjang, lebar, tinggi;
    char opsi;

    system("CLS");
    cout << "== P I R A M I D ==" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Input Nilai : " << endl;
    cout << "Panjang = ";
    cin >> panjang;
    cout << "Lebar   = ";
    cin >> lebar;
    cout << "Tinggi  = ";
    cin >> tinggi;

    Piramid p = Piramid(panjang, lebar, tinggi);
    p.hitungLuas();
    p.hitungVolume();
    
    //Polymorphism
    BangunGeometri* BG = &p;
    BG->ambilLuas();
    BG->ambilVolume();

    label_continue2:
    cout << "\nLagi? (y/n)...";
    cin >> opsi;

    if ( (opsi == 'y') | (opsi == 'Y')){
        goto label_continue1;
    } else if ((opsi == 'n') | (opsi == 'N')){
        goto label_stop;
    } else {
        goto label_continue2;
    }
    label_stop:
    cout << "OKE" << endl;

}

void bola()
{
    double r;
    char opsi;

    system("CLS");
    cout << "== B O L A ==" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Jari-jari = ";
    cin >> r;

    Bola b = Bola(r);
    b.hitungLuas();
    b.hitungVolume();
    
    //Polymorphism
    BangunGeometri* BG = &b;
    BG->ambilLuas();
    BG->ambilVolume();

    label_continue2:
    cout << "\nLagi? (y/n)...";
    cin >> opsi;

    if ( (opsi == 'y') | (opsi == 'Y')){
        goto label_continue1;
    } else if ((opsi == 'n') | (opsi == 'N')){
        goto label_stop;
    } else {
        goto label_continue2;
    }
    label_stop:
    cout << "OKE" << endl;

}