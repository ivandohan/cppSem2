//11c.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

struct Node
{
    int value;
    Node *next;
};

class Stack
{
private:
    Node *top;
    Node *bottom;
    int isempty;
public:
    Stack() {top = NULL; bottom = NULL;
    isempty = 1;}
    void push (int value);
    int pop(void);
    void show_stack();
    int is_empty(void) { return (isempty); }
};

void Stack::show_stack()
{
    Node *temp;

    temp = top;
    while(temp)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::push(int value)
{
    Node *temp;

    temp = new Node;
    temp->value = value;
    temp->next = NULL;

    if (is_empty())
    {
        top = temp;
        bottom = top;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    isempty = 0;
}

int Stack::pop(void)
{
    Node *temp;
    int val=-99;

    if (!is_empty())
    {
        temp = top;
        val = temp->value;
        if(temp->next)
        {
            temp = temp->next;
            top->next = NULL;
            delete top;
            top = temp;
        }

        else
        {
            top->next = NULL;
            delete top;
            top = NULL;
            bottom = NULL;
            isempty = 1;
        }
    }
    return val;
}



int main()
{
    Stack myStack;

    cout << "Push:" << endl;
    for(int i = 0; i<N; i++)
        myStack.push(rand()%N);
    myStack.show_stack();

    cout << "Pop:" << endl;
    while(!myStack.is_empty())
        cout << myStack.pop() << " ";
    cout << endl;

    return 0;
}