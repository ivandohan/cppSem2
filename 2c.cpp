//Contoh2_3.cpp
#include <iostream>
#include <iomanip>

using namespace std;
class NumSetbase
{
    private:
        int number;
        public:
        void getNumber();
        void displayNumber();
};
void NumSetbase::getNumber()
{
    cout << "Please give me a number: ";
    cin >> number;
}
void NumSetbase::displayNumber()
{
    cout<< setiosflags(ios::showbase);
    cout<< setiosflags(ios::uppercase);
    cout<<"Decimal "<< number <<" in octal: ";
    cout<<setbase(8)<< number <<endl;
    cout<<"Decimal "<< setbase(10) << number;
    cout<<" in Hexadecimal: "<< setbase(16) << number <<endl;
}
int main()
{
    NumSetbase aNumber;

    aNumber.getNumber();
    aNumber.displayNumber();

return 0;
}