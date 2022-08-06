/*
    Nama File   : 211402067_A02e.cpp
    Nama        : Ivandohan Samuel Siregar
    NIM         : 211402067
*/

#include <iostream>
#include <string>
using namespace std;

class Triangle {
public:
    float a, b, c;
    int flagT;
    Triangle(float a, float b, float c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
};

class Checking:public Triangle {
public:
    Checking(float a, float b, float c)
    :Triangle(a,b,c){}

    void cekTriangle(){
        if((a + b > c || a + c > b || b + c > a) && (a != 0) && (b != 0) && (c != 0)){
            cout << "Triangle True!" << endl;
            flagT = 1;
        }else {
            cout << "Triangle False!" << endl;
            flagT = 0;
        }
    }

    void cekEqui(){
        if(flagT == 1){
            if(a == b && b == c && a == c){
                cout << "Equilateral True!" << endl;
            }else {
                cout << "Equilateral False!" << endl;
            }
        }else {
            cout << "Equilateral False!" << endl;
        }
    }

    void cekIso(){
        if(flagT == 1){
            if((a == b && a != c) || ((b == c) && b != a)){
                cout << "Isoscele True" << endl;
            }else {
                cout << "Isoscele False" << endl;
            }
        }else {
            cout << "Isoscele False" << endl;
        }
    }

    void cekScal(){
        if(flagT == 1){
            if((a != b && b != c) && a != c){
                cout << "Scalene True!" << endl;
            }else {
                cout << "Scalene False" << endl;
            }
        }else{
                cout << "Scalene False" << endl;
        }
    }

};

int main()
{
    int i;
    float a, b, c;
    char opsi;

    label_continue1:
    system("CLS");
    cout << "== Cek Karakteristik Segitiga ==" << endl;
    cout << "Input 3 Sisi Segitiga : " << endl;
    cin >> a >> b >> c;

    Checking myClass = Checking(a,b,c);
    cout << "\n================================" << endl;
    myClass.cekTriangle();
    myClass.cekEqui();
    myClass.cekIso();
    myClass.cekScal();
    cout << "================================\n" << endl;

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

    cout << "E N D" << endl;

    return 0;

}