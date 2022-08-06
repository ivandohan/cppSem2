//Contoh5_1.cpp
#include <iostream>
using namespace std;

class Hitung
{
    protected:
        int cacah;
    public:
        Hitung() { cacah = 0; }
        Hitung(int c) { cacah = c; }
        // int Inkremen() { return cacah++; }
        // int Dekremen() { return cacah--; }
        int getHitungan() { return cacah; }
        ~Hitung() { }
};

class HitungMaju : public Hitung
{
    public:
        int Inkremen() { return cacah++; }
};

class HitungMundur : public Hitung
{
    public:
        int Dekremen() { return cacah--; }
};

int main()
{
    HitungMaju c1;
    HitungMundur c2;
    Hitung c3(10);

    cout << "c1 = " << c1.getHitungan() << endl;
    c1.Inkremen(); c1.Inkremen(); c1.Inkremen();
    cout << "c1 = " << c1.getHitungan() << endl;

    cout << "c2 = " << c2.getHitungan() << endl;
    c2.Dekremen(); c2.Dekremen();
    cout << "c2 = " << c2.getHitungan() << endl;

    // cout << "c3 = " << c3.getHitungan() << endl;
    // c3.Inkremen();
    // cout << "c3 = " << c3.getHitungan() << endl;

    return 0;
}