#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MyClass
{
    public:
        // string str = "Hello World";

        string method(){
            string str = "Hello World";

            return str;
        }
};

int main()
{
    MyClass deza;
    fstream myFile;

    myFile.open("deza.txt", ios::app);

    myFile << deza.method();

    myFile.close();
}