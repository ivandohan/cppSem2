 // Namafile: Contoh2_5.cpp
// Membalik bilangan bulat
#include <iostream>
#include <iomanip>
using namespace std;
class BalikBilangan
{
    private:
        int bilangan;
        int hasil;
        int pjgBil;
        public:
        void ambilBilangan();
        void balik();
        void displayHasil();
};

void BalikBilangan::ambilBilangan()
{
    cout << "Membalik bilangan\n";
    cout << "Berikan sebuah bilangan bulat: ";
    cin >> bilangan;
}

void BalikBilangan::balik()
{
    int blk=0, sisa=bilangan;
    pjgBil = 0;
    while(sisa)
    {
        hasil = (blk * 10) + (sisa%10);
        sisa /= 10;
        blk = hasil;
        pjgBil++;
    }
}

void BalikBilangan::displayHasil()
{
    cout << "Bilangan Anda sekarang = ";
    cout << setfill('0') << setw(pjgBil);
    cout << hasil << endl;
}

int main()
{
    BalikBilangan bil;

    bil.ambilBilangan();
    bil.balik();
    bil.displayHasil();

    return 0;
}
