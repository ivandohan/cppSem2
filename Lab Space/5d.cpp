//Contoh5_4.cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class buku
{
    private:
        string judul;
        string pengarang;
        int hlm;

    public:
        buku(string judul,string pengarang,int hlm);
        void show_buku();
        ~buku() {}
};

class disk
{
    private:
        float kapasitas;
    public:
        disk(float kapasitas);
        void show_disk();
        ~disk() { }
};

class bundel : public buku, public disk
{
    private:
        float harga;
    public:
        bundel(string judul,string pengarang, int hlm, float kapasitas, float harga);
        void show_bundel();
};

buku::buku(string judul, string pengarang, int hlm)
{
    this->judul = judul;
    this->pengarang = pengarang;
    this->hlm = hlm;
}

void buku::show_buku()
{
    cout << "Judul: " << judul << endl;
    cout << "Pengarang: " << pengarang << endl;
    cout << "Halaman: " << hlm << endl;
}

disk::disk(float kapasitas)
{
    this->kapasitas = kapasitas;
}

void disk::show_disk()
{
    cout << "kapasitas: " << kapasitas << "MB"
    << endl;
}

bundel::bundel(string judul, string pengarang, int hlm, float kapasitas, float harga):
buku(judul, pengarang, hlm),
disk(kapasitas)
{
    this->harga = harga;
}

void bundel::show_bundel()
{
    show_buku();
    show_disk();
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Harga: Rp" << harga << endl;
}

int main()
{
    bundel bukuku("Pemrograman C di Lingkungan Linux", 
    "Opim Salim Sitompul", 320, 700, 60000);
    
    bukuku.show_bundel();

    return 0;
}