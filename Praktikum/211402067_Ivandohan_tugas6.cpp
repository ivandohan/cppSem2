/*
        Nama        : Ivandohan Samuel Siregar
        NIM         : 211402067

        === Menghitung Volume Balok ===
*/

#include <iostream>
using namespace std;

class Box {
private:
    double length;      // Panjang
    double breadth;     // Lebar
    double height;      // Tinggi
    double volume;      // Volume
public:
    void getVolume() {
        volume = length * breadth * height;
        cout << "=> " << length << " x " << breadth << " x " << height <<
        " = " << volume << endl;    }
    void setLength( double len ) {
        length = len;
    }
    void setBreadth( double bre ) {
        breadth = bre;
    }
    void setHeight( double hei ) {
        height = hei;
    }
    
    // Overload + operator untuk menambahkan value properti 2 buah objek
    Box operator+(const Box& b) {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
};

int main() {
    Box Box1;                // Deklarasi balok 1
    Box Box2;                // Deklarasi balok 2 
    Box Box3;                // Deklarasi balok 3

    // spesifikasi balok 1 
    Box1.setLength(6.0); 
    Box1.setBreadth(7.0); 
    Box1.setHeight(5.0);

    // spesifikasi balok 2 
    Box2.setLength(12.0); 
    Box2.setBreadth(13.0); 
    Box2.setHeight(10.0);

    // Volume Balok 1
    cout << "Volume Balok 1 : " << endl;
    Box1.getVolume();
    cout << "\n";

    // Volume Balok 2
    cout << "Volume Balok 2 : " << endl;
    Box2.getVolume();
    cout << "\n";

    // Spesifikasi balok 3 = jumlah spesifikasi masing2 sisi balok 1 dan 2
    Box3 = Box1 + Box2;
    cout << "Volume Balok 3 : " << endl;
    Box3.getVolume();
    cout << "\n";

    return 0;
}