#include <iostream>
#include <string>

using namespace std;

class Latihan {
    public:
        string NIM, nama;
        Latihan (string NIM, string nama) {
            Latihan::NIM = NIM;
            Latihan::nama = nama;
        }

        Latihan (const Latihan &copy) {
            Latihan::NIM = copy.NIM;
            Latihan::nama = copy.nama;
        }

        void print() {
            cout << "NIM         = " << NIM << endl;
            cout << "Nama        = " << nama << endl;
        }
};

int main()
{
    system("CLS");
    string inpNIM, inpNama;
    cout << "Input NIM   = ";
    cin >> inpNIM;

    cout << "Input Nama  = ";
    cin >> inpNama;

    cout << "\n\n=== Hasil Inputan ===" << endl;
    cout << "*********************" << endl;

    cout << "Objek 1" << endl;
    Latihan objek1(inpNIM, inpNama);
    objek1.print();

    cout << "\nObjek 1 (Copy)" << endl;
    Latihan objek2 = objek1;
    objek2.print();

    return 0;
}