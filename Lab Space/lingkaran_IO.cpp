// PRISMA
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class lingkaran
{
protected:
    int jari;

public:
    // FOR INPUT/OUTPUT
    fstream myLingkaran;

    int jarii, luass, kelilingg;

    void openfile()
    {
        myLingkaran.open("wowowo.txt", ios ::app | ios ::in);
    }

    void closeFile()
    {
        myLingkaran.close();
    }
    void tulisStatistik();

    lingkaran() { jari = 0; }
    lingkaran(int jari)
    {
        this->jari = jari;
    }
    ~lingkaran() {}
};

// KELAS TURUNAN
class hitungLingkaran : public lingkaran
{
private:
    int luas, keliling;

public:
    hitungLingkaran(int j) : lingkaran(j)
    {
        luas = 0.0;
        keliling = 0.0;
    }
    // PROTOTYPE FUNGSI
    void getsisi();
    int ambilJari() { return jari; }
    int ambilLuas() { return luas; }
    int ambilKeliling() { return keliling; }
    void hitungLuas();
    void hitungKeliling();
    void displayHasil();
    int ubahJari();
    void ubahValue();
};

// MENDESKRIPSIKAN FUNGSI

// int hitungLingkaran ::ubahJari()
// {
//     // jarii = jari;
//     // return jarii;
// }
void hitungLingkaran ::getsisi()
{
    cout << " berikan jari-jari lingkaran : ";
    cin >> jari;
    // jarii = jari;
}
void hitungLingkaran ::hitungLuas()
{
    luas = (22 * jari * jari) / 7;
    // luass = luas;
}

void hitungLingkaran ::hitungKeliling()
{
    keliling = (2 * 22 * jari) / 7;
    // kelilingg = keliling;
}

void hitungLingkaran::displayHasil()
{
    cout << " lingkaran dengan jari sisi : " << jari << endl;
    cout << " luas : " << luas << endl;
    cout << " keliiling : " << keliling << endl;
}

void lingkaran ::tulisStatistik()
{
    openfile();
    myLingkaran << " jari-jari adalah : " << jarii << endl;
    myLingkaran << " luasnya adalah : " << luass << endl;
    myLingkaran << " keliling adalh : " << kelilingg << endl;
    closeFile();
}

void hitungLingkaran ::ubahValue()
{
    luass = luas;
    jarii = jari;
    kelilingg = keliling;
}

int main()
{
    // cout << " luasnya adalah : " << luass;
    lingkaran outinFile;
    hitungLingkaran prismaSatu(7);
    prismaSatu.getsisi();
    prismaSatu.ubahValue();

    prismaSatu.hitungLuas();
    prismaSatu.hitungKeliling();
    prismaSatu.displayHasil();
    outinFile.tulisStatistik();
}