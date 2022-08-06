#include <iostream>
#include <typeinfo>
#define PI 3.14159265359
#define KUADRAT(X) (X*X)

using namespace std;

class Lingkaran
{
    public:
        int r;
        float luas, keliling;

        void luaslkr();
        void kelilinglkr();
        void print();
};

void Lingkaran::luaslkr()
{
    Lingkaran::luas = PI * KUADRAT(Lingkaran::r);
    // Lingkaran::luas = (22 * KUADRAT((float)(Lingkaran::r))) / 7;
}

void Lingkaran::kelilinglkr()
{
    Lingkaran::keliling = 2 * PI * Lingkaran::r;
    // Lingkaran::keliling = (22 * 2 * (float)(Lingkaran::r)) / 7;
}

void Lingkaran::print()
{
    // cout << "Luas Lingkaran     = " << Lingkaran::luas << typeid(Lingkaran::luas).name() << endl;
    cout << "Luas Lingkaran     = " << Lingkaran::luas << endl;
    cout << "Keliling Lingkaran = " << Lingkaran::keliling << endl;
}

int main()
{
    Lingkaran lkr;
    char opsi;

    system("CLS");
    cout << "== Operasi Pada Lingkaran ==\n\n" << endl;
    label_continue1:
    cout << "Input Jari-Jari    = ";
    cin >> lkr.r;

    lkr.luaslkr();
    lkr.kelilinglkr();
    lkr.print();

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

    cin.get();
    return 0;
}