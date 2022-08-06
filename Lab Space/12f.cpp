//Contoh12_6.cpp
#include <iostream>
#include <string>

using namespace std;

class mesin
{
protected:
    string nama;
    int jenis_bbm;
public:
    mesin(string nama, int jenis_bbm);
    virtual void get_bbm(int liter);
};

mesin::mesin(string nama, int jenis_bbm)
{
    mesin::nama = nama;
    mesin::jenis_bbm = jenis_bbm;
}

void mesin::get_bbm(int liter)
{
    cout << "Tolong isi: " << liter
        << " liter premimum bersubsidi "
        << "untuk " << nama << endl;
}

class mesin_bmw : public mesin
{
public:
    mesin_bmw(string nama, int jenis_bbm): mesin(nama, jenis_bbm) {};
    void get_bbm(int liter)
    {
        cout << "Tolong isi: " << liter
            << " liter bbm non subsidi octane 92 "
            << "untuk " << nama << endl;
    }
};

class mesin_truk : public mesin
{
public:
    mesin_truk(string nama, int jenis_bbm): mesin(nama, jenis_bbm) {};
    void get_bbm(int liter)
    {
        cout << "Tolong isi: " << liter
            << " bbm solar non subsidi untuk "
            << nama << endl;
    }
};

int main()
{
    mesin rolls("Rolls Royce", 1);
    mesin_bmw bmw320i("BMW Serie 320i", 2);
    mesin_truk dyna("Truk sampah", 3);

    mesin *mesinPtr;
    mesinPtr = &rolls;
    mesinPtr->get_bbm(20);
    mesinPtr = &bmw320i;
    mesinPtr->get_bbm(100);
    mesinPtr = &dyna;
    mesinPtr->get_bbm(50);

    return 0;
}