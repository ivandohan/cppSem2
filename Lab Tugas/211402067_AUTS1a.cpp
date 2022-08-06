/*
        Nama File   : 211402067_AUTS1a.cpp
        NIM         : 211402067
        Nama        : Ivandohan Samuel Siregar
        
*/


#include <iostream>

using namespace std;

class Sum {
private:
    int sum = 0;

public:
    int AlternateSum(int);
};

int Sum::AlternateSum (int n)
{
    int i;

    for(i=0; i < n; i++){
        if((i%2) == 0)
            sum -= i;
        else
            sum += i;
    }

    return sum;
}

int main()
{
    Sum test;
    int n;

    cout << "Input Nilai n             = ";
    cin >> n; 


    cout << "Hasil Test Program AltSum = " << test.AlternateSum(n) << endl;

    return 0;
}