/*
    Nama : Amanda Bendicta Sembiring
    NIM  : 211402082
    UAS Prak. PBO membuat program konversi suhu
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;        //dasar c++ : namespace

class suhu{     //materi class & object : pendeklarasian class
    protected:
    float c, f, r, k;
    public:
    void inputSuhu(int index){
        switch (index)
        {
        case 1:
            cout<<"Input nilai celcius : ";
            cin>>c;
            break;
        case 2:
            cout<<"Input nilai reamur : ";
            cin>>r;
            break;
        case 3:
            cout<<"Input nilai fahren : ";
            cin>>f;
            break;
        case 4:
            cout<<"Input nilai kelvin : ";
            cin>>k;
            break;
        default:
            break;
        }
    }
};

class celcius : public suhu{     //materi inheritence

    public:

    void setCelcius()                      //materi class & object : pendeklarasian method
    {
        f = (c * 9/5) + 32;
        cout<<"\nCelcius ke Fahrenheit      :   "<<f;
        r = (c * 4/5);
        cout<<"\nCelcius ke Reamur          :   "<<r;
        k = c + 273.15;
        cout<<"\nCelcius ke Kelvin          :   "<<k<<endl;
    }
};

class reamur : public suhu{      //materi inheritence

    public:

    void setReamur()                       //materi class & object : pendeklarasian method
    {
        f = (r * 9/4) + 32;
        cout<<"\nReamur ke Fahrenheit       :   "<<f;
        c = (r * 5/4);
        cout<<"\nReamur ke Celcius          :   "<<c;
        k = c + 273.15;
        cout<<"\nReamur ke Kelvin           :   "<<k<<endl;
    }
};

class fahrenheit : public suhu{      //materi inheritence

    public:

    void setFahrenheit()                   //materi class & object : pendeklarasian method
    {
        r = 4 * (f -32)/9;
        cout<<"\nFahrenheit ke Reamur      :   "<<r;
        c =  5 * (f -32)/9;
        cout<<"\nFahrenheit ke Celcius     :   "<<c;
        k = c + 273.15;
        cout<<"\nFahrenheit ke Kelvin      :   "<<k<<endl;
    }
};

class kelvin : public suhu{      //materi inheritence

    public:
    void setKelvin()                       //materi class & object : pendeklarasian method
    {
        c = k - 273.15;
        cout<<"\nKelvin ke Celcius        :   "<<c;
        r = c * 4/5;
        cout<<"\nKelvin ke Reamur         :   "<<r;
        f = (c * 9/5) + 32;
        cout<<"\nKelvin ke Fahrenheit     :   "<<f<<endl;
    }
};

void menu()
{
    fstream myMenu;
    string namaFile = "menu_suhu.txt";
    string a;

    myMenu.open(namaFile, ios::in);
    while(getline(myMenu, a))
        cout<<a<<endl;
    myMenu.close();
}

int main()
{
    celcius c;        //materi class & object : pendeklarasian object
    reamur r;
    fahrenheit f;
    kelvin k;

    int pilihan;

    char ulang;
    do
    {
        system("cls");
        menu();
        cin>>pilihan;

        switch (pilihan)
        {
        case 1:
            c.inputSuhu(1);
            c.setCelcius();
            break;
        case 2:
            r.inputSuhu(2);
            r.setReamur();
            break;
        case 3:
            f.inputSuhu(3);
            f.setFahrenheit();
            break;
        case 4:
            k.inputSuhu(4);
            k.setKelvin();
            break;
        default:
            break;
        }
        cout<<"Apakah anda ingin kembali ke menu?(Y/T)";
        cin>>ulang;
        cin.ignore();
    }while(ulang == 'y' || ulang == 'Y');
    cout<<"Bye";

}
