#include <iostream>
using namespace std;

int x = 10;

// -> operator panah, untuk anggota var pointer

class Ascii{
    public:
        void displayAscii();
        void pointerOpr();
};

void Ascii::pointerOpr()
{
    cout << ::x << endl;  
}

void Ascii::displayAscii()
{
    // system("CLS");
    int i;
    cout << "=== ASCII TABLE ===" << endl;
    for( i = 0; i < 256; i++)
    {
        cout << i << ". " << char(i) << endl;
        if((i > 0) && (i % 20 == 0))
        {
            getchar();
        }
    }

    cout << "<ENTER>...";
    getchar();
}


int main()
{
    Ascii myAscii;

    double A[] = {1.2, 3.0, 4.5, 6.4, 8.1, 5.2, 2.3 };
    int arrSize = sizeof(A)/sizeof(A[0]) ;

    cout << sizeof(A) << endl;
    cout << sizeof(A[0]) << endl;
    cout << arrSize << endl;


    // myAscii.displayAscii();
    myAscii.pointerOpr();

    cout << sizeof(double) << endl;

    cin.get();
    return 0;
}