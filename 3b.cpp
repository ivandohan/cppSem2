// Contoh3_2.cpp
#include <iostream>
using namespace std;

class Number
{
    private:
        int value; 
    public:
        Number(int aValue);
        void getNumber();
        void showNumber();
        ~Number() {}
};

Number::Number(int aValue)
{
    value = aValue;
    cout << "Got " << value << endl;
}

void Number::getNumber()
{
    cout << "Enter an integer: ";
    cin >> value;
}

void Number::showNumber()
{
    cout << "You entered " ;
    cout << value << endl;
}

int main()
{
    Number yourNumber(10);

    yourNumber.getNumber();
    yourNumber.showNumber();

    Number* obj1 = new Number(20);
    
    return 0;
}
