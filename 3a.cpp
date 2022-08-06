 // Contoh3_1.cpp
#include <iostream>
using namespace std;
class MyClass {
    private:
        int counter;
    public:
        MyClass() {counter = 0;}
    
        void incrCounter(){counter++;}
        void showCounter();
        ~MyClass()
        {
            cout << "This statement is "
            << "automatically called..."
            << endl;
        }
};

void MyClass::showCounter()
{
    cout << "Counter is " << counter << endl;
}

int main()
{
    MyClass myCounter;


    myCounter.showCounter();
    myCounter.incrCounter();
    myCounter.showCounter();

return 0;
}