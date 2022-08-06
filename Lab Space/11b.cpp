//11b.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

class stack
{
    private:
    int *storage;
    int elements;
    int isempty;
    int isfull;
    int stack_size;

    public:
    stack(int size);
    void push (int value);
    int pop(void);
    void show_stack();
    int is_empty(void) { return (isempty); }
    int is_full(void) { return (isfull);}
    ~stack(){delete [] storage;}
};

stack::stack(int size)
{
    storage = new int[size];
    elements = 0;
    isempty = 1;
    isfull = 0;
    stack_size = size;
}

int stack::pop(void)
{
    if (!is_empty())
    {
        if (--elements == 0)
            isempty = 1;
        return (storage[elements]);
    }
}

void stack::push(int value)
{
    if (!is_full())
    {
        storage[elements++] = value;
        if (elements == stack_size)
            isfull = 1;
        isempty = 0;
    }
}

void stack::show_stack()
{
    int i=0;

    while(i<stack_size)
    {
        cout << storage[i] << " ";
        i++;
    }
    cout << endl;
}

int main()
{
    stack values(N);

    cout << "Push:" << endl;
    for(int i = 0; !values.is_full(); i++)
        values.push(rand()%N);
    values.show_stack();

    cout << "Pop:" << endl;
    while(!values.is_empty())
        cout << values.pop() << " ";
    cout << endl;

    return 0;
}