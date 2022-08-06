#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);         // constructor
    ~Stack();                       // destructor

    void push(int);
    int pop();
    int peek();

    void printStack();

    int size();
    bool isEmpty();
    bool isFull();
};

void Stack::printStack()
{
    int index = top;
    for(int i = 0; i < capacity; i++){
        cout << arr[index] << endl;
        index--;
    }
    cout << endl;
}

Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting : " << x << endl;
    arr[++top] = x;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing  : " << peek() << endl;

    return arr[top--];
}

int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

int Stack::size() {
    return top + 1;
}

bool Stack::isEmpty() {
    return top == -1;               // bisa juga return size() == 0;
}

bool Stack::isFull() {
    return top == capacity - 1;     // bisa juga return size() == capacity;
}

int main()
{
    Stack pt(3);

    system("cls");
    pt.push(1);
    pt.push(2);
    pt.push(3);
    pt.printStack();
    cout << "Size Stack  : " << pt.size() << endl;

    cout << "\n";
    pt.pop();
    pt.pop();
    cout << "Size Stack  : " << pt.size() << endl;
    cout << "\n";

    pt.push(3);

    cout << "Top element : " << pt.peek() << endl;
    cout << "Size Stack  : " << pt.size() << endl;

    cout << "\n";
    pt.pop();
    cout << "\n";

    if (pt.isEmpty()) {
        cout << "Stack sudah kosong\n";
    }
    else {
        cout << "Stack masih berisi\n";
    }

    return 0;
}