// Contoh3_4.cpp
#include <iostream>
using namespace std;

class Number
{
    private:
        int value;
    public:
        Number(int);
        Number(const Number &);
        void getNumber();
        void showNumber(string);
        ~Number() {}
};

Number::Number(int aValue)
{
    value = aValue;
}

Number::Number(const Number &aCopy)
{
    value = aCopy.value;
    cout << "Got " << value << endl;
}

void Number::getNumber()
{
    cout << "Enter an integer: ";
    cin >> value;
}

void Number::showNumber(string txt)
{
    cout << txt ;
    cout << value << endl;
}

int main()
{
    Number yourNumber(10);
    Number myCopy = yourNumber;

    yourNumber.getNumber();
    yourNumber.showNumber("Your new number : ");

    myCopy.showNumber("Copy of your number : ");

    return 0;
}