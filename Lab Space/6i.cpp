//Contoh6_9.cpp
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int SZ = 80;
enum boolean {salah, benar};

class String
{
private:
    string str;
    public:
    String() { str = ""; }
    String(string s) { str = s; }
    void getstr() { getline(cin, str); }

    void display() { cout << str; }
    boolean operator == (String);
    ~String() { }
};

boolean String::operator == (String ss)
{
    // return (strcmp(str, ss.str) == 0) ? benar : salah;
    return (str.compare(ss.str) == 0) ? benar : salah;
}

int main()
{
    String s1("ya");
    String s2("tidak");
    String s3;

    cout << "\nJawab dengan 'ya' atau 'tidak' : ";
    s3.getstr();
    if (s3 == s1)
    cout << "Jawaban Anda ya\n";
    else if (s3 == s2)
    cout << "Jawaban Anda tidak\n";
    else
    cout << "Anda tidak mematuhi instruksi"
    << " yang diberikan\n";

    return 0;
}