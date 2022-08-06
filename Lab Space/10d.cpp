//Contoh9_4
#include <iostream>
#include <vector>
using namespace std;

static const int NUM_OBJECTS = 10;

class MyNumber
{
private:
    int value;
public:
    MyNumber(int value) {this->value=value;}
    void showNumber(){ cout << "You gave " << value << endl;}
};

int main()
{
    vector<MyNumber*> vec;
    MyNumber* p = NULL;
    // Load up the vector with MyClass objects
    for (int i = 0; i < NUM_OBJECTS; i++) {
        p = new MyNumber(i);
        p->showNumber();
        vec.push_back(p);
    }
    // Do something useful with this data, then
    // delete the objects when you’re done
    for (vector<MyNumber*>::iterator pObj = vec.
    begin(); pObj != vec.end(); ++pObj) {
    // Note that this is deleting what pObj
    // points to, which is a pointer
        delete *pObj;
    }
    // Purge the contents so no one tries
    // to delete them again
    vec.clear();

    return 0;
}