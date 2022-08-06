#include <iostream>
#include <string>

using namespace std;

class Presiden{
private:
    string namaP;
    int jabatanP;
    char negara;
protected:
    int a;
    bool memerintah();
    void menugaskan();
};

class Rakyat: public Presiden{
protected:
    string namaR;
    void dilindungi();
    void berdaulat();
public:
    char daerah;
    string pangkat;
};

class Menteri: public Presiden, public Rakyat{
protected:
    void membuat();
public:
    string namaM;
    int jabatanM;
    char bagian;
    void bertugas();
};

class Tentara: public Presiden, public Rakyat{
private:
    int misi();
    void perang();
protected:
    string namaT;
    string angkatan;
public:
    string pangkat;
};

int main(){
    Presiden objP;
}