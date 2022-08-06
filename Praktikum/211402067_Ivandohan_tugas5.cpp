/*
        Nama        : Ivandohan Samuel Siregar
        NIM         : 211402067
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vect;
    system("CLS");

    for (int i = 1; i <= 5; i++)
        vect.push_back(i);

    cout << "Isi Vector : \n=> "; 
    for (auto i = vect.begin(); i != vect.end(); ++i)
        cout << *i << " ";

    cout << endl;
    cout << "\nBagian depan    : " << vect.front() << endl;
    cout << "Bagian belakang : " << vect.back() << endl;

    cout << "\nSize : \n=> " << vect.size();
    vect.clear();  //clear()
    cout << endl;
    cout << "\nVector after clear : \n=> " << vect.size();
    cout << endl;
}