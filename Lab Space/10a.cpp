// 10a.cpp

/*
    Ivandohan Samuel Siregar
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define N 20
using namespace std;

int main( )
{
    vector<int> intVec;

    // Add three elements to the "back" of thevector with push_back
    // for (vector<int>::iterator p=intVec.begin(); p != intVec.end(); ++p)
    srand(time(NULL));
    //Random 5 bilangan dari 0-20
    for(int i = 0; i < 5; i++)
    {
        intVec.push_back(rand()%N);
    }

    // intVec.push_back(3);
    // intVec.push_back(6);
    // intVec.push_back(9);

    // Or you can use iterators
    for (vector<int>::iterator p=intVec.begin(); p != intVec.end(); ++p)
    {
        cout << "-> " << *p << '\n';
    }

    // If you need to be safe, use at() instead of operator[]. It
    // will throw out_of_range if the index you use is > size().

    try {
        intVec.at(2) = rand()%N ; // Try at(3) to catch error
        cout << intVec.at(2) << endl;
        // cout << "Modifiying vector at " << 3 << endl;
        // cout << x << endl;
    }
        catch(out_of_range& e) {
        cerr << "out_of_range: " << e.what() <<
        endl;
    }

    for (vector<int>::iterator p=intVec.begin(); p != intVec.end(); ++p)
    {
        cout << "-> " << *p << '\n';
    }

    return 0;
}