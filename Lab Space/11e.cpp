//11e.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 15

using namespace std;

struct Node
{
    int val;
    Node *next;
};

class Queue
{
private:
    Node *first;
    Node *last;
    int empty;
public:
    Queue() {first=NULL; empty=1;}
    void enqueue(int);
    int dequeue();
    void print();
    int is_empty(){return empty;}
    ~Queue(){}
};

void Queue::enqueue(int x)
{
    Node *temp;
    temp = new Node;
    temp->val = x;
    temp->next = NULL;
    if(first==NULL)
        first = temp;
    else
    {
        last = first;
        while(last->next!=NULL)
        last = last->next;
        last->next = temp;
    }
    empty=0;
}

int Queue::dequeue()
{
    if(first == NULL)
    {
        cout << "Queue Kosong" << endl;
        return -1;
    }
    else
    {
        int r = first->val;
        first = first->next;
        if(first==NULL)
            empty = 1;
        return r;
    }
}

void Queue::print()
{
    last = first;
    while(last != NULL)
    {
        cout << last->val << " ";
        last = last->next;
    }
}

int main()
{
    Queue q;

    srand(time(NULL));
    cout << "Entering Q..." << endl;
    for(int i=0; i<N; i++)
        q.enqueue(rand()%N);
    q.print();
    cout << endl;
    cout << "Exiting Q..." << endl;

    while(!q.is_empty())
        cout << q.dequeue() << " ";
    cout << endl;
    return 0;
}

// int main2(){
//     do {
//         cout << "=== Queue ===" << endl;
//         cout << ""

//     }while(true);
// }