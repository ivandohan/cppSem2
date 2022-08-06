// Namafile: Contoh5_2.cpp
#include <iostream>
#define PI 3.14159
using namespace std;

class BangunGeometri
{
    protected:
        int besaran;
    public:
        BangunGeometri() { besaran = 0;}
        BangunGeometri(int besaran)
        { this->besaran = besaran;}
        ~BangunGeometri() {}
};

class Lingkaran : public BangunGeometri
{
    private:
        float luas, keliling;
    public:
        Lingkaran(int r) : BangunGeometri(r)
        {luas = 0.0; keliling = 0.0;}
        void getJari2();
        void hitungLuas();
        void hitungKeliling();
        void displayHasil();
};

void Lingkaran::displayHasil()
{
    cout << "Lingkaran berjari-jari " << besaran
    << endl;
    cout << "Luas = " << luas << endl;
    cout << "Keliling = " << keliling << endl;
}

void Lingkaran::getJari2()
{
    cout << "Berikan jari-jari lingkaran: ";
    cin >> besaran;
}

void Lingkaran::hitungLuas()
{
    luas = PI * besaran * besaran;
}

void Lingkaran::hitungKeliling()
{
    keliling = 2 * PI * besaran;
}

int main()
{

    Lingkaran r1(5);
    r1.hitungLuas();
    r1.hitungKeliling();
    r1.displayHasil();

return 0;
}
