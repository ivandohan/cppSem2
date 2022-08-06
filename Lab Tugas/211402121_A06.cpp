/*
    Nama File : 211402121_A06.cpp
    Nama      : Ahmad Fadli Tambunan
    NIM       : 211402121
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#define N 100

using namespace std;

template <typename T>
struct Node{
    T val;
    Node<T> *next;
};

template <typename T>
class Queue {
    private:
        Node<T> *first;
        Node<T> *trav;
        int empty;
    public:
        Queue() {
        first=NULL;
        empty=1;}
        ~Queue(){}
        void push(T x);
        T pop();
        void print();
        int is_empty();
};

template <typename T>
void Queue<T>::push(T x) {
    Node<T> *temp;
    temp = new Node<T>;

    temp->val = x;
    temp->next = NULL;

    if(first==NULL)
        first = temp;
    else {
        trav = first;

        while(trav->next!=NULL)
            trav = trav->next;

        trav->next = temp;
    }

    empty = 0;
}


template <typename T>
T Queue<T>::pop() {
    if(first == NULL){
        cout << "Queue Kosong" << endl;
        return -1;
    }
    else {
        T r = first->val;
        first = first->next;

        if(first==NULL)
            empty = 1;

        return r;
    }
}

template <typename T>
void Queue<T>::print(){
    trav = first;
    while(trav != NULL){
        cout << trav->val << endl;
        trav = trav->next;
    }
}

template <typename T>
int Queue<T>::is_empty(){
    return empty;
}

int main()
{
    
    Queue<int> q;
    Queue<float> r;
    Queue<char> s; 

    srand(time(0));

    // Integer
    cout << "Untuk tipe data Integer : " << endl;
    for(int i=0; i<5; i++) {
        int rd = rand() % N; 
        cout << "Pushing in (" << rd << ")..." << endl;
        q.push(rd);
    }
    cout << "-------------------------" << endl;
    while(!q.is_empty()) {
        cout << "Popping out (" << q.pop() << ")..." << endl;
    }

    cout << endl;

    // Float
    cout << "Untuk tipe data Float : " << endl;
    for(int i=0; i<5; i++) {
        float rd = static_cast <int> (rand()) / (static_cast <int> (RAND_MAX/N)); 
        cout << fixed <<  setprecision(2) << "Pushing in (" << rd << ")..." << endl;
        r.push(rd);
    }
    cout << "-------------------------" << endl;
    while(!r.is_empty()) {
        cout << setprecision(2) << "Popping out (" << r.pop() << ")..." << endl;
    }

    cout << endl;

    // Char
    cout << "Untuk tipe data Char : " << endl;
    for(int i=0; i<5; i++) {
        char rd = (rand() % 26) + 65; 
        cout << "Pushing in (" << rd << ")..." << endl;
        s.push(rd);
    }
    cout << "-------------------------" << endl;
    while(!s.is_empty()) {
        cout << "Popping out (" << s.pop() << ")..." << endl;
    }
    
    
    system("pause");

    return 0;
}
