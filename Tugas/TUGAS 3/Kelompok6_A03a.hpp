// #include <iostream>
// #include <typeinfo>
// #include <limits>

#define PI 3.14159265359
#define KUADRAT(X) (X*X)

using namespace std;

// ========================================= Soal Nomor 1 =============================================

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

// ========================================= Soal Nomor 2 =============================================


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

// ========================================= INTI BODY =============================================

int pilihantugas1();
int SoalP1_1();
int SoalP1_2();
 
void TugasPertemuan1()
{   
    label_start:
    int pilihan = pilihantugas1();
    char opsi;

	enum option{TUGAS1 = 1, TUGAS2, FINISH};
    
    while(pilihan != FINISH){
		switch(pilihan){
            case TUGAS1:
                SoalP1_1();
                break;
            
            case TUGAS2:
                SoalP1_2();
                break;
        }
        
        label_continue:

		cout << "Lihat Nomor Lain? (y/n) : ";
		cin >> opsi;
		if ( (opsi == 'y') | (opsi == 'Y')){
			// pilihan = pilihantugas1();
            goto label_start;
		} else if ((opsi == 'n') | (opsi == 'N')){
			break;
		} else {
			goto label_continue;
		}
    }

}

int SoalP1_1()
{
    Ascii myAscii;
    char opsi;


    system("CLS");
    cout << "== Kode ASCII Karakter User ==" << endl;
    label_continue1:
    myAscii.input();
    myAscii.output();

    label_continue2:
    cout << "\nCoba Lagi? (y/n)...";
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

int SoalP1_2()
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
    cout << "\nHitung Lagi? (y/n)...";
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

int pilihantugas1()
{
    int pilihan;
    system("CLS");
    cout << "=== TUGAS PERTEMUAN 01 ===" << endl;
    cout << "**************************" << endl;
    cout << "1. Kode ASCII dari User Char" << endl;
    cout << "2. Luas dan Keliling Lingkaran" << endl;
    cout << "3. FINISH." << endl;
    cout << "\n**************************" << endl;
    cout << "Pilihan [1-3] ? : ";
    cin >> pilihan;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return pilihan;
}
