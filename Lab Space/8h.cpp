//Contoh8_5.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#define N 100

using namespace std;

struct Node
{
    int value;
    Node *next;
};

class LinkList
{
private:
    Node *first;
public:
    LinkList();
    void show_list();
    void append_value(int);
    void reverseList();
    ~LinkList(){}
};

LinkList::LinkList()
{
    srand(time(NULL));
    first = NULL;
}

void LinkList::show_list()
{
    Node *node = first;
    while(node)
    {
        cout << node->value << " ";
        node = node->next;
    }
    cout << endl;
}

void LinkList::append_value(int value)
{
    Node *tmp, *tail;

    tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;

    if (first == NULL)
        first = tmp;
    else
    {
        tail = first;
        while(tail->next)
        tail = tail->next;
        tail->next = tmp;
    }
}

void LinkList::reverseList()
{
    Node* temp = first;
    Node* nextnode = NULL;
    Node* revnode = NULL;

    while (temp != NULL)
    {
        first = temp;
        nextnode = temp->next;
        temp->next = revnode;
        revnode = temp;
        temp = nextnode;
    }
}

int main()
{
    LinkList myList;

    cout << "Linked list awal:" << endl;
    for(int i=0; i < N; i++)
        myList.append_value(rand() % N);

    myList.show_list();

    myList.reverseList();
    cout<< "Linked list setelah dibalik:"
        << endl;

    myList.show_list();

    return 0;
}