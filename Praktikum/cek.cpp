#include <iostream>
#include <string>
using namespace std;

class Kendaraan {
public:
	Kendaraan(int x){
        cout << "Konstraktor Kendaraan Berparameter (tidak terpanggil)" << endl;
    }
	Kendaraan(){
        cout << "Konstraktor Kendaraan" << endl;
    }
};

class Kereta : virtual public Kendaraan {
public:
    string merkKereta;
	Kereta(int x):Kendaraan(x) {
        cout<< "Konstraktor Kereta" << endl;
        merkKereta = "Honda";
	}
};

class Mobil : virtual public Kendaraan {
public:
    string merkMobil;
	Mobil(int x):Kendaraan(x) {
		cout<< "Konstraktor Mobil" << endl;
        merkMobil = "Toyota";
	}
};

class Merk : public Kereta, public Mobil {
public:
	// Merk(int x):Mobil(x), Kereta(x), Kendaraan(x) {      //Untuk memanggil konstraktor
	// 	cout<< "Konstraktor Merk" << endl;    //kendaraan dengan parameter
	// }

	Merk(int x):Mobil(x), Kereta(x) {
		cout<< "Konstraktor Merk" << endl;
	}

    void printMerk(){
        cout << "Merk Kereta : " << merkKereta << endl;
        cout << "Merk Mobil  : " << merkMobil << endl;
    }
};

int main() {
	Merk obj(1);
    obj.printMerk();

    return 0;
}


