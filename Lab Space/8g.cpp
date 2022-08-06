//Contoh8_7.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define N 15

using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

class DoubleLinkList
{
private:
    Node *first;
    Node *end;
public:
    DoubleLinkList();
    void show_list();
    void show_prevlist();
    Node *append_value(int);
};

DoubleLinkList::DoubleLinkList()
{
    srand(time(NULL));
    first = NULL;
    end = NULL;
}

void DoubleLinkList::show_list()
{
    Node *node;

    node = first;
    while(node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void DoubleLinkList::show_prevlist()
{
    Node *node;

    node = end;

    while(node)
    {
        cout << node->value << " ";
        node = node->prev;
    }
    cout << endl;
}

Node *DoubleLinkList::append_value(int value)
{
    Node *ptr = end;
    end = new Node;

    if (first == NULL)
        first = end;
    else
        ptr->next = end;

    if(end)
    {
        end->next = NULL;
        end->prev = ptr;
        end->value = value;
    }

    return end;
}

int main()
{
    DoubleLinkList myList;

    cout << "Double Linked list:" << endl;
    for(int i=0; i < N; i++)
        myList.append_value(rand() % N);
    cout << "Print maju: " << endl;
    myList.show_list();
    cout << "Print mundur: " << endl;
    myList.show_prevlist();

    return 0;
}