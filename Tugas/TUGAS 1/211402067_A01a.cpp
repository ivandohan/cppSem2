#include <iostream>

using namespace std;

class Ascii
{
    public:
        char inputan;
        void input();
        void output();
};

void Ascii::input()
{
    cout << "\n\nInput Karakter    = ";
    cin >> Ascii::inputan;
}

void Ascii::output()
{
    cout << "Kode ASCII dari " << Ascii::inputan;
    cout << " = " << int(Ascii::inputan) << endl;
}

int main()
{
    Ascii myAscii;
    char opsi;


    system("CLS");
    cout << "== Kode ASCII Karakter User ==" << endl;
    label_continue1:
    myAscii.input();
    myAscii.output();

    label_continue2:
    cout << "\nLanjutkan? (y/n)...";
    cin >> opsi;

    if ( (opsi == 'y') | (opsi == 'Y')){
        goto label_continue1;
    } else if ((opsi == 'n') | (opsi == 'N')){
        goto label_stop;
    } else {
        goto label_continue2;
    }

    label_stop:

    return 0;
}