#include <iostream>
#include <typeinfo>
#include <limits>
#define PI 3.14159265359
#define KUADRAT(X) (X*X)


using namespace std;

class Ascii
{
    public:
        char inputan;

        void input(){
            cout << "\n\nInput Karakter    = ";
            cin >> Ascii::inputan;
        }

        void output(){
            cout << "Kode ASCII dari " << Ascii::inputan;
            cout << " = " << int(Ascii::inputan) << endl;
        }
};

class Lingkaran
{
    public:
        int r;
        float luas, keliling;

        void luaslkr(){
            Lingkaran::luas = PI * KUADRAT(Lingkaran::r);
            // Lingkaran::luas = (22 * KUADRAT((Lingkaran::r))) / 7;
        }

        void kelilinglkr(){
            Lingkaran::keliling = 2 * PI * Lingkaran::r;
            // Lingkaran::keliling = (22 * 2 * (Lingkaran::r)) / 7;
        }

        void print(){
            // cout << "Luas Lingkaran     = " << Lingkaran::luas << typeid(Lingkaran::luas).name() << endl;
            cout << "Luas Lingkaran     = " << Lingkaran::luas << endl;
            cout << "Keliling Lingkaran = " << Lingkaran::keliling << endl;
        }
};

int getOption();
int tugas1();
int tugas2();

int main()
{   
    label_start:
    int pilihan = getOption();
    char opsi;

	enum option{TUGAS1 = 1, TUGAS2, FINISH};
    
    while(pilihan != FINISH){
		switch(pilihan){
            case TUGAS1:
                tugas1();
                break;
            
            case TUGAS2:
                tugas2();
                break;
        }
        
        label_continue:

		cout << "Lanjutkan Program Utama? (y/n) : ";
		cin >> opsi;
		if ( (opsi == 'y') | (opsi == 'Y')){
			// pilihan = getOption();
            goto label_start;
		} else if ((opsi == 'n') | (opsi == 'N')){
			break;
		} else {
			goto label_continue;
		}
    }


	cout << "*** END ***" << endl;

	// cin.get();
	return 0;
}

int tugas1()
{
    Ascii myAscii;
    char opsi;


    system("CLS");
    cout << "== Kode ASCII Karakter User ==" << endl;
    label_continue1:
    myAscii.input();
    myAscii.output();

    label_continue2:
    cout << "\nLagi? (y/n)...";
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

int tugas2()
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
    cout << "\nLagi? (y/n)...";
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

int getOption()
{
    int pilihan;
    system("CLS");
    cout << "=== TUGAS PERTEMUAN 01 ===" << endl;
    cout << "**************************" << endl;
    cout << "1. Tugas 1 : Kode ASCII dari User Char" << endl;
    cout << "2. Tugas 2 : Luas dan Keliling Lingkaran" << endl;
    cout << "3. FINISH." << endl;
    cout << "\n**************************" << endl;
    cout << "Pilihan [1-3] ? : ";
    cin >> pilihan;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return pilihan;
}