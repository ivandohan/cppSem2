/*
    Nama File   : 211402067_A02d.cpp
    Nama        : Ivandohan Samuel Siregar
    NIM         : 211402067
*/

#include <iostream>
#include <string>
#define PI 3.14159
#define KUADRAT(X) (X * X)

using namespace std;

class BangunGeometri {
public:
    double r, sBujur, sSegitiga;
    double luas, keliling;
    char kode_bangun;
    string namaBangun;

    BangunGeometri(char kode, double besaran){
        this->kode_bangun = kode;
        if(kode == 'c' || kode == 'C'){
            this->r = besaran;
            namaBangun = "Lingkaran";
        }
        else if(kode == 's' || kode == 'S'){
            this->sBujur = besaran;
            namaBangun = "Bujur Sangkar";
        }
        else if(kode == 't' || kode == 'T'){
            this->sSegitiga = besaran;
            namaBangun = "Segitiga";
        }else {
            cout << "Tidak ada bangun terdaftar!" << endl;
        }
    }

    virtual void display(){
        cout << "=== " << namaBangun << " ===" << endl;
        cout << "Luas       = " << luas << endl;
        cout << "Keliling   = " << keliling << endl;
        cout << "\n" << endl;
    }
};

class Lingkaran:public BangunGeometri {
public:
    Lingkaran(char kode, double besaran)
    :BangunGeometri(kode, besaran){
        luas = 0;
        keliling = 0;
    }

    void htgLuas(){
        luas = PI * (KUADRAT(r));
    }

    void htgKeliling(){
        keliling = 2 * PI * (KUADRAT(r));
    }
};

class BujurSangkar:public BangunGeometri {
public:
    BujurSangkar(char kode, double besaran)
    :BangunGeometri(kode,besaran){
        luas = 0;
        keliling = 0;
    }

    void htgLuas(){
        luas = sBujur * sBujur;
    }

    void htgKeliling(){
        keliling = 4 * sBujur;
    }
};

class Segitiga:public BangunGeometri {
private:
    double tinggi;
public:
    Segitiga(char kode, double besaran, double tinggi)
    :BangunGeometri(kode,besaran){
        luas = 0;
        keliling = 0;
        this->tinggi = tinggi;
    }

    void htgLuas(){
        luas = (sSegitiga * tinggi) / 2;
    }

    void htgKeliling(){
        keliling = 3 * sSegitiga;
    }
};

int main()
{
    Lingkaran L = Lingkaran('C',7);
    L.htgKeliling();
    L.htgLuas();


    BujurSangkar BS = BujurSangkar('S', 5);
    BS.htgKeliling();
    BS.htgLuas();


    Segitiga S = Segitiga('T', 5, 7);
    S.htgKeliling();
    S.htgLuas();

    //Polymorphism
    BangunGeometri* LP = &L;
    BangunGeometri* BSP = &BS;
    BangunGeometri* SP = &S;
    LP->display();
    BSP->display();
    SP->display();

    return 0;
}