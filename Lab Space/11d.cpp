//11d.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

using namespace std;

class Queue
{
private:
    int *storage;
    int first;
    int last;
    int isempty;
    int isfull;
    int q_size;

public:
    Queue(int size);
    int enqueue(int value);
    int dequeue(void);
    void show_queue();
    int getLast(void) {return last;}
    int getFirst(void) {return first;}
    int is_empty(void) { return isempty; }
    int is_full(void) { return isfull;}
    ~Queue(){delete [] storage;}
};

Queue::Queue(int size)
{
    srand(time(NULL));
    storage = new int[size];
    first = 0;
    last = 0;
    isempty = 1;
    isfull = 0;
    q_size = size;
}

void Queue::show_queue()
{
    int i=first;

    while(i<q_size)
        cout << storage[i++] << " ";
    cout << endl;
}

int Queue::dequeue(void)
{
    if (!is_empty())
    {
        if (first == q_size)
        {
            isempty = 1;
            isfull = 0;
            first = 0;
            last = 0;
            return isempty;
        }
        else return storage[first++];
    }
    return 0;
}

int Queue::enqueue(int value)
{
    if (is_full())
        return 0;
    else
    {
        storage[last++] = value;
        if (last == q_size-1)
            isfull = 1;
        isempty = 0;
    }
}

int main()
{
    Queue values(N);

    cout << "Enqueue:" << endl;
    while(!values.is_full())
        values.enqueue(rand()%N);

    values.show_queue();
    cout << "Queue is full... " << endl;
    cout << "\nDequeue:" << endl;
    for(int i=0; i < N; i++)
        cout << values.dequeue() << " ";
    cout << "\nQueue is empty..." << endl;

    return 0;
}
