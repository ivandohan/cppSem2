//Contoh6_6.cpp 
#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
    private:
        double jari2;
        double sudut;
        double getx() { return jari2*cos(sudut); }
        double gety() { return jari2*sin(sudut); }
    public:
        Polar() { jari2 = 0.0; sudut = 0.0; };
        Polar(double r, double a) { jari2 = r; sudut = a; };

        void display(){cout << "(" << jari2 << ", " << sudut << ")";}
        Polar operator + (Polar);
        ~Polar() { }
};

Polar Polar::operator + (Polar p2)
{
    double x = getx() + p2.getx();
    double y = gety() + p2.gety();
    double r = sqrt(x*x + y*y);
    double a = atan(x/y);

    return Polar(r, a);
}

int main()
{
    Polar p1(10.0, 0.0), p2(10.0, 1.570796325), p3;

    p3 = p1 + p2;
    cout << "\np1 = "; p1.display();
    cout << "\np2 = "; p2.display();
    cout << "\np3 = "; p3.display();
    cout << endl;

    return 0;
}