//Contoh3_3.cpp
#include<iostream>
using namespace std;

class Myconstructor
{
    private:
        int x, y; //data members
    public:
        Myconstructor(int, int);
        Myconstructor(const Myconstructor &);
        void display();
};

/* Copy constructor */
Myconstructor::Myconstructor(int x1, int y1)
{
    x = x1;
    y = y1;
}

Myconstructor::Myconstructor(const Myconstructor &pan)
{
    x = pan.x;
    y = pan.y;
}

void Myconstructor::display()
{
    cout << x << " " << y << endl;
}

int main()
{
    Myconstructor obj1(10, 15);//Normal constr
    // Myconstructor obj2 = obj1;//Copy constr
    Myconstructor* obj2 = new Myconstructor(obj1);
    
    cout<<"Normal constructor : ";
    obj1.display();

    cout<<"Copy constructor   : ";
    obj2->display();

return 0;
}
