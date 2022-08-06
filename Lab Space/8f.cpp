// Contoh8_6.cpp
//  Program untuk menyimpan titik koordinat dalam linked list
#include <iostream>

using namespace std;

struct Simpul
{
    int absis;
    int ordinat;
    Simpul *berikut;
};

class titikKoord
{
private:
    Simpul *first;
public:
    titikKoord();
    void tambahTitik();
    void buangTitik();
    void cetakDaftar();
};

titikKoord::titikKoord()
{
    first = NULL;
}

void titikKoord::cetakDaftar()
{
    Simpul *node;

    cout << "Daftar titik koordinat:" << endl;
    node = first;

    while(node)
    {
        cout << "(" << node->absis << ", "
        << node->ordinat << ")";
        node = node->berikut;
    }
    cout << endl;
}

void titikKoord::tambahTitik()
{
    Simpul *baru, *ekor;

    baru = new Simpul;

    cout << "Berikan absis : ";
    cin >> baru->absis;
    cout << "Berikan ordinat: ";
    cin >> baru->ordinat;
    baru->berikut = NULL;

    if(first == NULL)
        first = baru;
    else
    {
        ekor = first;
        while (ekor->berikut)
        ekor = ekor->berikut;
        ekor->berikut = baru;
    }
}

void titikKoord::buangTitik()
{
    int x, y, ada = 0;
    Simpul *cari, *hapus;

    cout << "Titik mana?" << endl;
    cout << "Berikan absis dan ordinat: ";
    cin >> x >> y;

    cari = first;
    while(cari && !ada)
    {
        if((cari->absis == x) &&
        (cari->ordinat == y))
        ada = 1;
        else
        cari = cari->berikut;
    }

    if(ada)
    {
        hapus = first;

        if(hapus == cari)
        {
            first = first->berikut;
            cari->berikut = NULL;
            delete cari;
        }
        else
        {
            while ((hapus->berikut) && (hapus->berikut != cari))
            hapus = hapus->berikut;
            hapus->berikut = cari->berikut;
            cari->berikut = NULL;
            delete cari;
        }
    }
    else
        cout << "Titik ("<< x << ", " << y
        << ") tidak ada dalam daftar." <<
        endl;
}

int main()
{
    titikKoord titikA;
    char pilih = '0';

    do
    {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Menambah titik." << endl;
        cout << "2. Membuang titik." << endl;

        cout << "3. Mencetak daftar." << endl;
        cout << "4. Selesai." << endl;
        cout << "Pilihan: ";
        cin >> pilih;
        switch(pilih)
        {
            case '1': titikA.tambahTitik();
                break;
            case '2': titikA.buangTitik();
                break;
            case '3': titikA.cetakDaftar();
                system("pause");
                break;
        }
    } while (pilih < '4');

    return 0;
}