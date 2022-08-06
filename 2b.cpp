#include <iostream>

using namespace std;

class HexOct
{
    private:
        int number;

    public:
        void getNumber();
        void displayNumber();
};

void HexOct::getNumber()
{
    cout << "Please give me a number: ";
    cin >> number;
}

void HexOct::displayNumber()
{
    cout << "Decimal: " << number << "\tHexadecimal: " << hex << number << endl;
    cout << "Decimal: " << dec << number << "\tOctal: " << oct << number << endl;
}

int main()
{
    HexOct aNumber;

    aNumber.getNumber();
    aNumber.displayNumber();

    return 0;
}
