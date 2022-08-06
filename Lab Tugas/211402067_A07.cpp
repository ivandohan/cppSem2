/*
        Nama File       : 211402067_A07.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        === Modifikasi Program 9.5 ===
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10

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

void Queue::enqueue(int x){ // Otomatis Sort Secara ASCENDING 

    Node* current;
    Node* temp = new Node;

    temp->val = x;
    temp->next = NULL;

    if (first == NULL|| first->val >= temp->val) {
        temp->next = first;
        first = temp;
    }
    else {
        current = first;
        while (current->next != NULL && current->next->val < temp->val) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    empty = 0;
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
    if(first == NULL){
        cout << "Queue Kosong";
    }
    last = first;
    while(last != NULL)
    {
        cout << last->val << " ";
        last = last->next;
    }

    cout << endl;
}

int main()
{
    Queue q;
    char opsi = 0;
    int x;

    srand(time(NULL));
    for(int i=0; i<N; i++){
        q.enqueue(rand()%N);
    };

    do {
        system("cls");
        cout << "===== Queue yang Terdaftar ======" << endl;
        cout << "Saat ini : ";
        q.print();
        cout << "=================================" << endl;
        cout << "\n";
        cout << "==== Menu Operasi Pada Queue ====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue Elemen Terdepan" << endl;
        cout << "3. Hapus Semua Queue" << endl;
        cout << "4. End" << endl;
        cout << "---------------------------------" << endl;
        cout << "Pilihan [1-4] : ";
        cin >> opsi;

        switch(opsi)
        {
            case '1':
                cout << "Nilai yang akan ditambah : ";
                cin >> x;
                q.enqueue(x);
                cout << "Value " << x << " Berhasil Ditambahkan!" << endl;
                system("pause");
                break;

            case '2': 

                cout << "Dequeue Elemen Terdepan => " << q.dequeue() << endl;
                system("pause");
                break;

            case '3': 
                cout << "Menghapus Elemen Queue :" << endl;
                while(!q.is_empty())
                    cout << q.dequeue() << " ";
                cout << endl;
                system("pause");
                break;
        }

    } while(opsi < '4');

    cout << "=== END ===" << endl;
    return 0;
}