 // Contoh9_2.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main( )
{
    vector<string> strVec;
    // Add elements to the "back" of the vector with push_back
    string s = "Teknologi Informasi";
    strVec.push_back(s);
    s = "Fasilkom-TI";
    strVec.push_back(s);
    s = "Universitas Sumatera Utara";
    strVec.push_back(s);

    // You can access them with operator[], just like an array
    for (vector<string>::size_type i = 0; i <
    strVec.size(); ++i) {
        cout << "strVec[" << i << "] = " << strVec[i] << '\n';
    }
    // Or you can use iterators
    for (vector<string>::iterator p = strVec.
    begin(); p != strVec.end( ); ++p)
    {
        cout << *p << '\n';
    }

    // If you need to be safe, use at( ) instead of operator[].
    // It will throw out_of_range if the index  you use is > size().
    try {
        strVec.at(3) = "Medan";
    }
    catch(out_of_range& e) {
        cerr << "out_of_range: " << e.what() <<
        endl;
    }

    return 0;
}