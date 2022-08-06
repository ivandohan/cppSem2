/*
    09-02-2022
*/

#include <iostream>
#include <string>
using namespace std;

int x = 10;

class Introduce
{
    private: // Lebih baik untuk menyimpan data // Tidak dapat diaksess di class lain
        string beginner = "Ivandohan Samuel Siregar";
        string prvtString = "Ini Variabel Private";

    public:
        void printData()
        {
            cout << "Hello World" << endl;
            cout << beginner << endl;
            cout << prvtString << endl;
        }

    // protected: //  Hampir mirip dengan private, tapi masih dapat di akses di class yang beda
};

int main()
{
    Introduce hari1;
    int x = 20;
    // 
    hari1.printData();
    cout << ::x << endl;


    cin.get();
    return 0;
}