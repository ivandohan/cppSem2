//Contoh9_3.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Util function for printing vector contents
template<typename T>
void vecPrint (const vector<T>& vec)
{
    cout << "{";
    for (typename vector<T>::const_iterator p = vec.begin(); p != vec.end(); ++p) {
        cout << "{" << *p << "} ";
    }
    cout << "}" << endl;
}

int main( )
{
    vector<string> vec(5);
    string foo[] = {"My", "way", "or", "the", "highway"};
    vec[0] = "Today";
    vec[1] = "is";
    vec[2] = "a";
    vec[3] = "new";
    vec[4] = "day";
    vector<string> vec2(vec);
    vecPrint(vec2);

    vec.at(0) = "Tomorrow";
    // Copy each element over with assign //Kiri - Kanan
    vec2.assign(vec.begin(), vec.end());
    vecPrint(vec2);
    // Assign works for anything that
    // behaves like an iterator
    vec2.assign(&foo[0], &foo[5]);
    vecPrint(vec2);
    vector<string>::iterator p;
    p = find(vec.begin(), vec.end(), "new");
    // Copy a subset of the full range of vec
    vec2.assign(vec.begin(), p);
    vecPrint(vec2);

    return 0;
}