//Contoh6_5.cpp
#include <iostream>

using namespace std;

class Jarak
{
private:
    int kaki;
    float inches;
public:
    Jarak() { kaki = 0; inches = 0.0; };
    Jarak(int ft, float in)
    { kaki = ft; inches = in; };
    void get_Jarak();

    void show_Jarak(){
        cout << kaki << "\'-" << inches << '\"';
    }
    
    Jarak operator + (Jarak);
    
    ~Jarak() { }
};

void Jarak::get_Jarak()
{
    cout << "\nBerikan kaki dan inchi: ";
    cin >> kaki >> inches;
}

Jarak Jarak::operator + (Jarak j)
{
    int f = kaki + j.kaki;
    float i = inches + j.inches;
    if (i >= 12.0){
        i -= 12.0;
        f++;
    }
    return Jarak(f, i);
}

int main()
{
    Jarak j1, j3, j4;

    j1.get_Jarak();
    Jarak j2(11, 6.25);
    j3 = j1 + j2;
    j4 = j1 + j2 + j3;
    cout << "\nJarak 1 = "; j1.show_Jarak();
    cout << "\nJarak 2 = "; j2.show_Jarak();
    cout << "\nJarak 3 = "; j3.show_Jarak();
    cout << "\nJarak 4 = "; j4.show_Jarak();
    cout << endl;

    return 0;
}