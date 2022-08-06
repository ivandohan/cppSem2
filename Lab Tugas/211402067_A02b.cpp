/*
    Nama File   : 211402067_A02b.cpp
    Nama        : Ivandohan Samuel Siregar
    NIM         : 211402067
*/

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#define PI 3.14159
#define KUADRAT(X) (X * X)

using namespace std;

class BangunGeometri {
public :
    fstream myInput, myOutputL, myOutputT;
    double besaran;

    string Input = "input.txt";
    string OutputL = "output.txt";
    string OutputT = "output1.txt";

    BangunGeometri(double besaran){
        this->besaran = besaran;
    }

    void OpenFile(int opsi){
        if(opsi == 1){
            myInput.open(Input, ios::app);
        }else if(opsi == 2){
            myOutputL.open(OutputL, ios::app);
        }else if(opsi == 3){
            myOutputT.open(OutputT, ios::app);
        }
    }

    void CloseFile(int opsi){
        if(opsi == 1){
            myInput.close();
        }else if(opsi == 2){
            myOutputL.close();
        }else if(opsi == 3){
            myOutputT.close();
        }
    }

    ~BangunGeometri(){}
};

class Lingkaran:public BangunGeometri {
private:
    double luas, keliling;
public  :
    Lingkaran(double besaran):BangunGeometri(besaran){
        luas = 0;
        keliling = 0;
    }

    void htgLuas(){
        luas = PI * (KUADRAT(besaran));
    }

    void htgKeliling(){
        keliling = 2 * PI * besaran;
    }

    void cetakLingkaran(){
        OpenFile(2);

        myOutputL << "=== Lingkaran ===" << endl;
        myOutputL << "Keliling  : " << keliling << endl;
        myOutputL << "Luas      : " << luas << endl;
        myOutputL << "\n";

        CloseFile(2);
    }

    void cetakInputL(){
        OpenFile(1);

        myInput << "=== Lingkaran ===" << endl;
        myInput << "Jari-jari : " << besaran << endl;
        myInput << "~~~~~~~~~~~~~~~~~" << endl;
        myInput << "\n";

        CloseFile(1);
    }

    // void ambilLuas(){ cout << "Luas Lingkaran     = " << luas << endl; }
    // void ambilKeliling(){ cout << "Keliling Lingkaran = " << keliling << endl; }
    // void ambilR(){ cout << "Jari-jari          = " << besaran << endl; }

    void ambil(int opsi){
        if(opsi == 1){
            cout << "Jari-jari          = " << besaran << endl;
        }else if(opsi == 2){
            cout << "Keliling Lingkaran = " << keliling << endl;
        }else if(opsi == 3){
            cout << "Luas Lingkaran     = " << luas << endl;
        }
    }

    ~Lingkaran(){}
};

class Tabung:public BangunGeometri {
private:
    double luas_alas, luas_selimut, luas_permukaan, volume;
public  :
    double tinggi;
    
    Tabung(double besaran, double tinggi):BangunGeometri(besaran){
        this->tinggi = tinggi;
        luas_alas = 0;
        luas_selimut = 0;
        volume = 0;
    }

    void htgLuasSelimut(){
        luas_selimut = (2 * PI * besaran) * tinggi;
    }

    void htgLuasAlas(){
        luas_alas = PI * KUADRAT(besaran);
    }

    void htgLuasPermukaan(){
        // luas_permukaan = (PI * KUADRAT(besaran)) + (2 * PI * besaran * tinggi);
        luas_permukaan = (luas_alas) + (2 * PI * besaran * tinggi);
    }
    void htgVolume(){
        // volume = (PI * KUADRAT(besaran)) * tinggi;
        volume = (luas_alas) * tinggi;
    }

    void cetakTabung(){
        OpenFile(3);

        myOutputT << "=== Tabung ===" << endl;
        myOutputT << "Luas Alas     : " << luas_alas << endl;
        myOutputT << "Luas Selimut  : " << luas_selimut << endl;
        myOutputT << "Volume        : " << volume << endl;
        myOutputT << "\n";

        CloseFile(3);
    }

    void cetakInputT(){
        OpenFile(1);

        myInput << "=== Tabung ===" << endl;
        myInput << "Jari-jari     : " << besaran << endl;
        myInput << "Tinggi        : " << tinggi << endl;
        myInput << "~~~~~~~~~~~~~~" << endl;
        myInput << "\n";

        CloseFile(1);
    }

    void ambil(int opsi){
        if(opsi == 1){
            cout << "Jari-jari      = " << besaran << endl;
        }else if(opsi == 2){
            cout << "Tinggi         = " << tinggi << endl;
        }else if(opsi == 3){
            cout << "Luas Selimut   = " << luas_selimut << endl;
        }else if(opsi == 4){
            cout << "Luas Alas      = " << luas_alas << endl;
        }else if(opsi == 5){
            cout << "Luas Permukaan = " << luas_permukaan << endl;
        }else if(opsi == 6){
            cout << "Volume         = " << volume << endl;
        }
    }

    ~Tabung(){}
};

int getOption();
void lingkaran();
void tabung();

int main()
{
    label_start:
    int pilihan = getOption();
    char opsi;

    if(pilihan == 1){
        lingkaran();
        goto label_start;
    } else if(pilihan == 2){
        tabung();
        goto label_start;
    } else if(pilihan == 3){
        goto label_stop;
    }

    label_stop:
    cout << "E N D" << endl;

    return 0;
}

void lingkaran()
{
    double r;
    char opsi;
    
    system("CLS");
    cout << "=== Lingkaran ===" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Jari-jari  = ";
    cin >> r;

    Lingkaran L = Lingkaran(r);

    L.htgKeliling();
    L.htgLuas();
    cout << "~~~~~~~~~~~~~~~~~" << endl;
    L.ambil(1);
    L.ambil(2);
    L.ambil(3);
    cout << "~~~~~~~~~~~~~~~~~" << endl;

    L.cetakInputL();
    L.cetakLingkaran();
    
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
    cout << "O K E" << endl;
}

void tabung()
{
    double r, t;
    char opsi;

    system("CLS");
    cout << "=== Tabung ===" << endl;
    label_continue1:
    cout << "Input Nilai : " << endl;
    cout << "Jari-jari  = ";
    cin >> r;
    cout << "Tinggi     = ";
    cin >> t;

    Tabung T = Tabung(r,t);

    T.htgLuasAlas();
    T.htgLuasPermukaan();
    T.htgLuasSelimut();
    T.htgVolume();

    /*
        ambil();
        1. Jari2            4. Luas Alas
        2. Tinggi           5. Luas Permukaan
        3. Luas Selimut     6. Volume
    */
    
    cout << "~~~~~~~~~~~~~~" << endl;
    for(int i = 1; i <= 6; i++){
        T.ambil(i);
    }
    cout << "~~~~~~~~~~~~~~" << endl;

    T.cetakInputT();
    T.cetakTabung();
    
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
    cout << "O K E" << endl;
}

int getOption()
{
    int pilihan;
    system("CLS");
    cout << "=== Bangun Ruang ===" << endl;
    cout << "********************" << endl;
    cout << "1. Lingkaran" << endl;
    cout << "2. Tabung" << endl;
    cout << "3. FINISH." << endl;
    cout << "\n**************************" << endl;
    cout << "Pilihan [1-3] ? : ";
    cin >> pilihan;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return pilihan;
}