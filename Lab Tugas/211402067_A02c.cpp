/*
    Nama File   : 211402067_A02c.cpp
    Nama        : Ivandohan Samuel Siregar
    NIM         : 211402067
*/

#include <iostream>
#define PI 3.14159
using namespace std;

class BangunGeometri
{
    protected:
        double besaran;
    public:
        BangunGeometri() { besaran = 0;}
        BangunGeometri(double besaran){
            this->besaran = besaran;
        }
        ~BangunGeometri() {}
};

class Lingkaran : public BangunGeometri
{
    private:
        double luas, keliling;
    public:
        Lingkaran(double r) : BangunGeometri(r)
        {luas = 0.0; keliling = 0.0;}
        void hitungLuas();
        void hitungKeliling();
        void displayHasil();
};

class Persegi : public BangunGeometri
{
    private:
        double luas, keliling;
    public:
        Persegi(double sisi) : BangunGeometri(sisi)
        {luas = 0.0; keliling = 0.0;}
        
        void hitungLuas();
        void hitungKeliling();
        void displayHasil();
};

class Segitiga : public BangunGeometri
{
    private:
        double tinggi, luas, keliling;
    public:
        Segitiga(double sisi, double tinggi) : BangunGeometri(sisi)
        {
            luas = 0.0; 
            keliling = 0.0;
            this->tinggi = tinggi;
        }
        
        void hitungLuas();
        void hitungKeliling();
        void displayHasil();
};

void Lingkaran::displayHasil()
{
    cout << "Lingkaran berjari-jari " << besaran << endl;
    cout << "Luas       = " << luas << endl;
    cout << "Keliling   = " << keliling << endl;
}

void Lingkaran::hitungLuas()
{
    luas = PI * besaran * besaran;
}

void Lingkaran::hitungKeliling()
{
    keliling = 2 * PI * besaran;
}

void Persegi::displayHasil()
{
    cout << "Persegi dengan sisi " << besaran << endl;
    cout << "Luas       = " << luas << endl;
    cout << "Keliling   = " << keliling << endl;
}

void Persegi::hitungLuas()
{
    luas = besaran * besaran;
}

void Persegi::hitungKeliling()
{
    keliling = 4 * besaran;
}

void Segitiga::displayHasil()
{
    cout << "Segitiga dengan sisi " << besaran << ", dan tinggi " << tinggi << endl;
    cout << "Luas       = " << luas << endl;
    cout << "Keliling   = " << keliling << endl;
}

void Segitiga::hitungLuas()
{
    luas = (besaran * tinggi) / 2;
}

void Segitiga::hitungKeliling()
{
    keliling = 3 * besaran;
}

int main()
{

    Lingkaran r1(5);
    r1.hitungLuas();
    r1.hitungKeliling();
    r1.displayHasil();

    cout << "\n" << endl;

    Persegi r2(5);
    r2.hitungLuas();
    r2.hitungKeliling();
    r2.displayHasil();

    cout << "\n" << endl;

    Segitiga r3(5,7);
    r3.hitungLuas();
    r3.hitungKeliling();
    r3.displayHasil();


    return 0;
}
