/*
        Nama File               : Kel06_01.cpp
        Nama dan NIM anggota    :
            1. Ivandohan Samuel Siregar - 211402067
            2. Amanda Bendicta Sembiring - 211402082
            3. Aurelia Priscilia Simamora - 211402091
            4. Adelweys Margaretha Sijabat - 211402103
        
        === Mini Project 1 : Implementasi Fungsi Virtual dan Polymorphism ===
*/


#include <iostream>
#include <string>
#define PI 3.14159
#define KUADRAT(X) (X*X)
#define KUBIK(X) (X*X*X)
using namespace std;

// ===== Dalam satuan centimeter (cm) =====
class BangunGeometri
{
protected:
    double volume; 
    double area;
    string namaBangun;
public:
    BangunGeometri(){
        volume = 0;
        area = 0;
    }; 

    virtual void countVolume() = 0;                
    virtual void countArea() = 0;                  
    virtual void getArea() = 0; 
    virtual void getVolume() = 0;

    ~BangunGeometri(){};
};

class Cube : public BangunGeometri
{
private:
    double side;

public:
    Cube(string namaBangun, double side) {
        this->side = side;
        this->namaBangun = namaBangun;
    }

    void countVolume() {
        volume = KUBIK(side);
    }

    void countArea() {
        area = KUADRAT(side);
    }

    void getVolume() {
        cout << "Volume " << namaBangun << " = " << volume << " cm^3" << endl;
    }

    void getArea() {
        cout << "Luas " << namaBangun << " = " << area << " cm^2" << endl;
    }

    ~Cube() {}
};

class Prism : public BangunGeometri
{
private:
    double length, widht, height;

public:
    Prism(string namaBangun, double length, double width, double height){
        this->namaBangun = namaBangun;
        this->length = length;
        this->widht = width;
        this->height = height;
    }

    void countVolume() {
        volume = length * widht * height;
    }

    void countArea(){
        area = 2 * ((length * widht) + (length * height) + (widht * height));
    }

    void getVolume() {
        cout << "Volume " << namaBangun << " = " << volume << " cm^3" << endl;
    }

    void getArea() {
        cout << "Luas " << namaBangun << " = " << area << " cm^2" << endl;
    }

    ~Prism() {}
};

class Sphere : public BangunGeometri
{
private:
    double radius;

public:
    Sphere(string namaBangun, double radius) {
        this->namaBangun = namaBangun;
        this->radius = radius;
    }

    void countVolume() {
        volume = (4 * PI * radius * radius * radius) / 3;
    }

    void countArea() {
        area = 4 * PI * KUADRAT(radius);
    }

    void getVolume() {
        cout << "Volume " << namaBangun << " = " << volume << " cm^3" << endl;
    }

    void getArea() {
        cout << "Luas " << namaBangun << " = " << area << " cm^2" << endl;
    }

    ~Sphere() {}
};

int main(int argc, char const *argv[])
{
    Cube kubus("Kubus", 8);
    Prism balok("Balok", 2,4,3);
    Sphere bola("Bola", 12);

    BangunGeometri* bangunGeometri;

    system("CLS");
    cout << "=== Menghitung Luas dan Volume Bangun Ruang ===\n" << endl;

    bangunGeometri = &kubus;
    bangunGeometri->countArea();
    bangunGeometri->countVolume();
    bangunGeometri->getArea();
    bangunGeometri->getVolume();

    cout << "\n";

    bangunGeometri = &balok;
    bangunGeometri->countArea();
    bangunGeometri->countVolume();
    bangunGeometri->getArea();
    bangunGeometri->getVolume();

    cout << "\n";

    bangunGeometri = &bola;
    bangunGeometri->countArea();
    bangunGeometri->countVolume();
    bangunGeometri->getArea();
    bangunGeometri->getVolume();

    return 0;
}