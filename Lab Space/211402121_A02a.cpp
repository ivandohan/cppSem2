#include <iostream>
#include <cmath>
#define PI 3.14159
using namespace std;

class bangunGeometri {
    protected:
        float volume, luas, P, T, L;
    public:
        bangunGeometri(){volume = 0; luas = 0;};
        float ambilVolume() { return volume; };
        float ambilLuas() { return luas; };
        void getPTL();
        ~bangunGeometri(){};
};

class Kubus : public bangunGeometri{
    private:
        float sisi;
    public:
        Kubus(){sisi = 0;}
        void getSisi();
        void hitungVolume(){
            volume = sisi * sqrt(sisi);
        }
        void hitungLuas(){
            luas = 6.0 * sisi;
        }
        ~Kubus(){};
};

class Balok : public bangunGeometri{
    public:
        Balok(){
            P = 0; T = 0; L = 0;
        }
        void hitungVolume(){
            volume = P * L * T;
        }
        void hitungLuas(){
            luas = 2 * (P*L + P*T + L*T);
        }
        ~Balok(){};
};

class Piramid : public bangunGeometri{
    public:
        Piramid(){
            P = 0; T = 0; L = 0;
        }
        void hitungVolume(){
            volume = 1.0/3.0 * (P*L) * T;
        }
        void hitungLuas(){
            luas = (P*L) + (sqrt(pow(T,2) + pow(0.5*P,2)) * L) + (sqrt(pow(T,2) + pow(0.5*L,2)) * P );
        }
        ~Piramid(){};
};

class Bola : public bangunGeometri{
    private:
        float jari2;
    public:
        Bola(){
            jari2 = 0;
        }
        void getJari2();
        void hitungVolume(){
            volume = 4.0/3.0 * PI * pow(jari2, 3);
        }
        void hitungLuas(){
            luas = 4.0 * PI * pow(jari2, 2);
        }
        ~Bola(){};
};

int main()
{
    Bola bola;
    Kubus kubus;
    Balok balok;
    Piramid piramid;
    char jwb, choice;

    do
	{
        system("cls");
        cout << "=== Menghitung Volume dan Luas Bangun Geometri ===" << endl;
        cout << "1. Kubus\n2. Balok\n3. Piramid\n4. Bola" << endl;
        cout << "Pilih Bangun Geometri: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "+++ KUBUS ++++\n";
            kubus.getSisi();
            kubus.hitungLuas();
            kubus.hitungVolume();
            cout << "Volume \t= " << kubus.ambilVolume() << endl;
            cout << "Luas \t= " << kubus.ambilLuas() << endl;
            break;

        case '2':
            cout << "+++ BALOK (PRISMA SEGIEMPAT) ++++\n";
            balok.getPTL();
            balok.hitungLuas();
            balok.hitungVolume();
            cout << "Volume \t= " << balok.ambilVolume() << endl;
            cout << "Luas \t= " << balok.ambilLuas() << endl;
            break;

        case '3':
            cout << "+++ PIRAMID ++++\n";
            piramid.getPTL();
            piramid.hitungLuas();
            piramid.hitungVolume();
            cout << "Volume \t= " << piramid.ambilVolume() << endl;
            cout << "Luas \t= " << piramid.ambilLuas() << endl;
            break;

        case '4':
            cout << "+++ BOLA ++++\n";
            bola.getJari2();
            bola.hitungLuas();
            bola.hitungVolume();
            cout << "Volume \t= " << bola.ambilVolume() << endl;
            cout << "Luas \t= " << bola.ambilLuas() << endl;
            break;

        default:
            cout << "WARNING: Inputan salah" << endl;
            break;
        }

        cout << "Ulang (Y/T)? ";
		cin >> jwb;

    } while(jwb == 'y' || jwb == 'Y');

    return 0;
}

void Bola::getJari2(){
    cout << "Jari - jari : ";
    cin >> jari2;
}

void Kubus::getSisi(){
    cout << "Berikan besar sisi Kubus: ";
    cin >> sisi;
}

void bangunGeometri::getPTL(){
    cout << "Panjang\t: ";
    cin >> P;
    cout << "Tinggi\t: ";
    cin >> T;
    cout << "Lebar\t: ";
    cin >> L;
}