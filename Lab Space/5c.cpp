//Contoh5_3.cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class kenderaan
{
    protected:
        string nama;
        string bbakar;
        int roda;
    public:
        kenderaan(string, string, int);
        void show_kenderaan();
        ~kenderaan() { }
};

kenderaan::kenderaan(string nama, string bbakar, int roda)
{
    kenderaan::nama = nama;
    kenderaan::bbakar = bbakar;
    kenderaan::roda = roda;
}

void kenderaan::show_kenderaan()
{
    cout << "Nama: " << nama << endl;
    cout << "Bahan bakar: " << bbakar << endl;
    cout << "Roda: " << roda << endl;
}
class sepedamotor : public kenderaan
{
    private: 
        int mesin;
    public:
        sepedamotor(string nama, string bbakar, int roda, int mesin);
        void show_sepedamotor();
};

sepedamotor::sepedamotor(string nama, string bbakar,int roda, int mesin):kenderaan(nama, bbakar, roda)
{
    sepedamotor::mesin = mesin;
}

void sepedamotor::show_sepedamotor()
{
    cout << "Nama: " << nama << endl;
    cout << "Mesin: " << mesin << " Takt" <<
    endl;
}

class mobil : public kenderaan
{
    private:
        int pintu;
    public:
        mobil(string nama,string bbakar, int roda, int pintu);
        void show_mobil();
};

mobil::mobil (string nama, string bbakar, int roda, int pintu):kenderaan(nama, bbakar, roda)
{
    mobil::pintu = pintu;
}

void mobil::show_mobil()
{
    cout << "Nama: " << nama << endl;
    cout << "Bahan bakar: " << bbakar << endl;
    cout << "Pintu: " << pintu << endl;
}

int main()
{
    sepedamotor honda("CBR250RR","bensin",4,2),
    yamaha("NMax", "bensin", 4, 2);
    mobil toyota("All New Rush","bensin", 4, 4);
    mobil mitsubishi("Pajero Sport", "solar", 4,4);

    honda.show_sepedamotor();
    yamaha.show_sepedamotor();

    toyota.show_mobil();
    mitsubishi.show_mobil();

    return 0;
}