//Contoh9_5.cpp
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

static const int MAXINT = 10;
using namespace std;
// A simple functor for printing
template<typename T>
struct printer {
    void operator()(const T& s) {
        cout << s << '\n';
    }
};

bool inline even(int n) {
    return(n % 2 == 0);
}

printer<int> intPrinter;

int main( )
{
    list<int> intLst;

    srand(time(0));
    for(int i=0; i < MAXINT; i++) {
        intLst.push_back(rand()%MAXINT);
    }

    // Remove all values greater than 8
    intLst.remove_if(bind2nd(greater<int>(), 8));
    for_each(intLst.begin(),
        intLst.end(),
        intPrinter);
    // Or, remove all even values
    cout << "============ - eliminasi bil genap" << endl;
    intLst.remove_if(even);
    for_each(intLst.begin(),
        intLst.end(),
        intPrinter);

    return 0;
}