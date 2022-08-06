//Contoh6_7.cpp
#include <iostream>
#include <string>

using namespace std;
const int SZ = 80;

class String
{
    private:
        string str;
    public:
        String() { str = ""; }
        String(string s) { str = s; }
        void display() { cout << str; }
        String operator + (String);
        ~String() { }
};

String String::operator + (String ss)
{
    String temp;

    if (str.length() + (ss.str).length() < SZ)
    {
        temp.str = str;
        temp.str.append(ss.str);
    }
    else
        cout <<"\nString overflow";

    return temp;
}

int main()
{
    String s1 = String("\nFasilkom-TI USU ");
    String s2 = String("Medan, Sumatera Utara");
    String s3;

    s3 = s1 + s2;
    s3.display();
    cout << endl;

return 0;
}
