//Contoh6_4.cpp
#include <iostream>
using namespace std;
class Hitung
{
private:
    unsigned int cacah;
public:
    Hitung() {cacah = 0;};
    int get_Hitungan() {return cacah;}
    void operator ++(){cacah++;}//postfix ++
    void operator ++(int){//prefix ++
        ++cacah;
    }
    ~Hitung() { }
};

int main()
{
    Hitung c1, c2;

    cout << "\nc1 = " << c1.get_Hitungan();
    cout << "\nc2 = " << c2.get_Hitungan();
    c1++;
    c2++;
    ++c2;
    cout << "\nc1 = " << c1.get_Hitungan();
    cout << "\nc2 = " << c2.get_Hitungan();
    cout << endl;

    return 0;
}