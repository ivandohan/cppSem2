//Contoh6_3.cpp
#include <iostream>
using namespace std;
class Hitung
{
protected:
    unsigned int cacah;
public:
    Hitung() { cacah = 0; }
    Hitung(int c) { cacah = c; }
    int get_Hitungan() { return cacah; }
    Hitung operator ++ ()
    {
        cacah++;
        return Hitung(cacah);
    }

    ~Hitung() { }
};

int main()
{
    Hitung c1, c2;

    cout << "\nc1 = " << c1.get_Hitungan();
    cout << "\nc2 = " << c2.get_Hitungan();
    ++c1;
    c2 = ++c1;
    cout << "\nc1 = " << c1.get_Hitungan();
    cout << "\nc2 = " << (++c2).get_Hitungan();
    cout << endl;
    return 0;
}