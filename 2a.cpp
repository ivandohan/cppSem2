//Contoh2_1.cpp
#include <iostream>
#include <string>

using namespace std;

class Nama
{
    private:
        string nama_depan;
        string nama_belakang;

    public:
        void ambilNama();
        void displayNama();
};

void Nama::ambilNama()
{
    cout << "Tuliskan nama depan dan nama belakang: ";
    cin >> nama_depan >> nama_belakang;
}

void Nama::displayNama()
{
    cout << "Halo, " << nama_depan << " " << nama_belakang <<endl;
}

int main()
{
    Nama satuNama;

    satuNama.ambilNama();
    satuNama.displayNama();

    return 0;
}