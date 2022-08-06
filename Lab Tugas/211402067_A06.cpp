/*
        Nama File       : 211402067_A06.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        === Tugas Pemrograman 6 : Soal Nomor 3 ===
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <typeinfo>
using namespace std;

// typedef struct NodeType Node;
template <class T>
struct Node {
    T val;
    Node<T> *next;
};

template <class T>
class Queue
{
private:
    Node<T> *first;
    Node<T> *trav;
    T empty;
public:
    Queue() {
        first=NULL;
        empty=1;
    }
    ~Queue(){}
    void push(T x){
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
        empty=0;
    }

    T pop(){
        if(first == NULL){
            cout << "Queue Kosong" << endl;
            return -1;
        }
        else{
            T r = first->val;
            first = first->next;
            if(first==NULL)
            empty = 1;
            return r;
        }
    }
    void print(){
        trav = first;
        while(trav != NULL){
        cout << trav->val << endl;
        trav = trav->next;
        }
    }

    T is_empty(){
        return empty;
    }
};

void queueInt();
void queueFloat();
void queueChar();

int main()
{
    int opsi;
    char opsi2;

    label_start:
    system("cls");
    cout << "=== Push & Pop Berdasarkan Tipe ===" << endl;
    cout << "1. Integer" << endl;
    cout << "2. Float" << endl;
    cout << "3. Char" << endl;
    cout << "===================================" << endl;
    cout << "Pilihan [1-3] : "; cin >> opsi;

    switch(opsi){
        case 1:
            queueInt();
            break;
        case 2:
            queueFloat();
            break;
        case 3:
            queueChar();
            break;
        default:
            cout << "<error> Pilihan tidak diketahui." << endl;
            break;
    }

    label_confirm:
    cout << "Lagi? [y/n] ..."; cin >> opsi2;
    if(opsi2 == 'y' || opsi2 == 'Y'){
        goto label_start;
    }else if(opsi2 == 'n' || opsi2 == 'N'){
        goto label_stop;
    }else {
        goto label_confirm;
    }

    label_stop:
    cout << "\n===== END =====" << endl;
    system("pause");

    return 0;
}

void queueInt(){
    Queue<int> objInt;
    int iVal;
    cout << "===== PUSH =====" << endl;
    for(int i=0; i<10; i++){
        iVal = rand() % 50;
        cout << "Pushing in (" << iVal << ")..." << "Type : " << 
        typeid(iVal).name() << endl;
        objInt.push(iVal);
    }

    cout << "\n===== POP =====" << endl;

    while(!objInt.is_empty()){
        cout << "Popping out (" << objInt.pop()
        << ")..." << endl;
    }
}

void queueFloat(){
    Queue<float> objFloat;
    float fVal;
    cout << "===== PUSH =====" << endl;
    for(int i=0; i<10; i++){
        fVal = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/50));
        cout << fixed << setprecision(3) << "Pushing in (" << fVal << ")..." << "Type : " << 
        typeid(fVal).name() << endl;
        objFloat.push(fVal);
    }

    cout << "\n===== POP =====" << endl;

    while(!objFloat.is_empty()){
        cout << setprecision(3) << "Popping out (" << objFloat.pop()
        << ")..." << endl;
    }
}

void queueChar(){
    Queue<char> objChar;
    char cVal;
    cout << "===== PUSH =====" << endl;
    for(int i=0; i<10; i++){
        cVal = (rand() % 58) + 65; //ASCII code char alfabet dimulai dari 65. 
        cout << "Pushing in (" << cVal << ")..." << "Type : " << 
        typeid(cVal).name() << endl;
        objChar.push(cVal);
    }

    cout << "\n===== POP =====" << endl;

    while(!objChar.is_empty()){
        cout << "Popping out (" << objChar.pop()
        << ")..." << endl;
    }
}