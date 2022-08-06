//Contoh12_3.cpp
#include <iostream>
#include <string>

using namespace std;

class telepon
{
protected:
    string no_telp;
    int volume;
public:
    telepon(string nomor, int volume);
    virtual int dial(string no_keluar);
};

telepon::telepon(string nomor, int volume)
{
    telepon::no_telp = nomor;
    telepon::volume = volume;
}

int telepon::dial(string no_keluar)
{
    cout << "Menggunakan telepon rotary atau touch-tone ";
    cout << " untuk memanggil: " << no_keluar;

    cout << " Volume: " << volume << endl;

    return 0;
}

class touch_tone : public telepon
{
public:
    touch_tone (string nomor, int volume): telepon(nomor, volume) { };
    int dial (string no_keluar);
};

int touch_tone::dial(string no_keluar)
{
    cout << "Beep beep beep suara touch-tone: " << no_keluar;
    cout << " Volume: " << volume << endl;

    return 0;
}

class rotary : public telepon
{
public:
    rotary (string nomor, int volume): telepon(nomor, volume) { };
    int dial (string nomor_keluar);
};

int rotary::dial(string no_keluar)
{
    cout << "Klick klik klik suara rotary: " << no_keluar;
    cout << " Volume: " << volume << endl;

    return 0;
}

int main()
{
    touch_tone kantor("821-3793", 5);
    rotary rumah("822-3576", 2);

    telepon seluler("555-5555", 3);

    rumah.dial("222-3333");
    kantor.dial("333-4444");
    seluler = rumah;
    seluler.dial("555-1234");
    seluler = kantor;
    seluler.dial("555-5678");

    return 0;
}