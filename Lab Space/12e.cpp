//Contoh12_5.cpp
#include <iostream>
#include <string>

using namespace std;

class mesin
{
private:
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
        << " premimum bersubsidi." << endl;
}

class mesin_jet : public mesin
{
public:
    mesin_jet(string nama, int jenis_bbm): mesin(nama, jenis_bbm) {};
    void get_bbm(int liter)
    {
        cout << "Tolong isi: " << liter
            << " bbm avtur jet JP4" << endl;
    }
};

class mesin_truk : public mesin
{
public:
    mesin_truk(string nama, int jenis_bbm): mesin(nama, jenis_bbm) {};
    void get_bbm(int liter)
    {
        cout << "Tolong isi: " << liter << " bbm solar non subsidi" << endl;
    }
};

int main()
{
    mesin rolls("Rolls Royce", 1);
    mesin_jet F100("Pesawat jet", 2);
    mesin_truk dyna("Truk sampah", 3);
    mesin harley("Harley Davidson", 1);

    rolls.get_bbm(20);
    F100.get_bbm(100);
    dyna.get_bbm(40);
    harley.get_bbm(5);

    return 0;
}
