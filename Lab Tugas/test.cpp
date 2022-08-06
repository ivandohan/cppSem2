#include <iostream>
#include <string>

using namespace std;

class Kalkulator
{
protected :
    float Bil1;
    float Bil2;
    float Hasil;
    float Jumlah;
public:
    virtual void input()=0;
    virtual void output()=0;
};

class Kabataku: public Kalkulator
{
public:
    void input()
    {
        cout<<"\nKalkulator Sederhana"<<endl;
        cout<<"Masukkan Bilangan pertama : "; cin>>Bil1;
        cout<<"Masukkan Bilangan Kedua   : "; cin>>Bil2;
    }
    void output()
    {
        cout<<"\nHASIL :";
        Hasil= Bil1 - Bil2 ;
        cout<<"\nKurang     = "<<Hasil<<endl;
        Hasil= Bil1 * Bil2;
        cout<<"Kali       = "<<Hasil<<endl;
        Hasil= Bil1 / Bil2;
        cout<<"Bagi       = "<<Hasil<<endl;
    }
};
    int main()
    {
        Kabataku Kd;
        int pil;
        system("CLS");
        cout<<"--------- UAS PPBO -----------\n"<<endl;

        Kalkulator* objCalc;
        objCalc = &Kd;
        objCalc->input();
        objCalc->output();
        cout<<endl;

        return 0;
    }