//Contoh2_4.cpp
#include <iostream>
#include <iomanip>

using namespace std;

class NumSetPrecision
{
    private:
        float number;
        public:
        void Initialize() {number = 0.0;}
        void getNumber(float number) {this->number=number;}
        float returnNumber() {return number;}
        void displayNumber();
};

void NumSetPrecision::displayNumber()
{
    cout << setfill('-');
    cout << setprecision(5) << showpoint << setw(9);
    cout << number << endl;
}
int main()
{
    NumSetPrecision oneNumber;
    NumSetPrecision twoNumber;

    oneNumber.Initialize();
    oneNumber.displayNumber();
    twoNumber.getNumber(3.14159);
    twoNumber.displayNumber();

    return 0;
}
