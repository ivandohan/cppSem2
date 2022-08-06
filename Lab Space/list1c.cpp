#include <iostream>
using namespace std ;

class Node {
public:
    int data ;
    Node* link ;
    // constructor
    Node() { link = NULL;}
    Node(int val) { data = val ; link = NULL; }
};
//-----------------------------------
class SLL {
private:
    Node *head, *tail;

public:
    SLL() { head = NULL; tail = NULL; } // constructor
    void printList() ;
    void createNode(int val) ; // tambahkan node diakhir
    void insertdiAwal(int val) ; // tambah node diawal
    void insertPosisi(int pos, int val) ; // tambah pada posisi tertentu
    void deleteLast() ; // delete node diakhir
    void deleteFirst() ; // delete node pertama/diawal
    void deletePosisi(int pos) ; // delete pada posisi tertentu
    void search(int);
};

void SLL :: printList() {
    Node *p = head;
    
    while( p!=NULL) {
        cout << p->data << "-->";
        p = p->link ;
    }
    
    cout << endl;
} // end of print list
//------------------------------------

void SLL :: createNode(int val) {
    Node *temp = new Node() ;
    temp->data = val;
    temp->link = NULL;
    
    if(head==NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->link = temp;
        tail = temp;
    }
} // end of createNode

void SLL :: insertdiAwal(int val){
    Node *temp = new Node();
    temp->data = val ;
    temp->link = head ;
    head = temp;
} // end of insertdiAwal

void SLL :: insertPosisi(int pos, int val){
    Node *prev = new Node ;
    Node *curr = new Node ;
    Node *temp = new Node ;
    curr = head;
    int i = 1 ;

    while ( i < pos ) {
        prev = curr ;
        curr = curr->link ;
        i = i + 1 ;
    }

    temp->data = val ;
    prev->link = temp;
    temp->link = curr;
} // end of insertPosision

void SLL :: deleteFirst() {
    Node *temp = new Node;
    temp = head ;
    head = head->link ;
    delete temp;
} // end of deleteFirst

void SLL :: deleteLast() {
    Node *curr, *prev ;
    curr = head;
    
    while(curr->link != NULL) {
        prev = curr ;
        curr = curr->link ;
    }
    
    tail = prev ;
    prev->link = NULL;
    delete curr;
} //end deleteLast

void SLL :: deletePosisi(int pos) {
    Node *curr = new Node ;
    Node *prev = new Node ;
    curr = head;
    int i = 1 ;
    
    while( i < pos ) {
        prev = curr ;
        curr = curr->link ;
        i = i + 1 ;
    }
    
    prev->link = curr->link;
} // end of deletePosisi

void SLL :: search(int searchNum) {
    Node *elemen = head;
    int cek = 0, i = 0;

    while(elemen != NULL){
        i++;
        if(elemen->data == searchNum)
        {
            cout << searchNum << " di posisi " << i << endl;
            cek++;
        }
        elemen = elemen->link;
    }

    if(!cek){
        cout << "Not Found" << endl;
    }
}

int main() {
    SLL p ;

    system("CLS");
    
    cout << "Create linked list dengan elemen: " << endl;
    p.createNode(50);
    p.createNode(60);
    p.createNode(70);
    p.createNode(80);
    p.printList();

    cout << "\nCreate node baru : 95 " << endl;
    p.createNode(95);
    p.printList();
    
    cout << "\nInsert diawal : 65 " << endl ;
    p.insertdiAwal(65) ;
    p.printList();
    
    cout << "\nInsert pada posisi ke-3 : " << endl ;
    p.insertPosisi(3,88);
    p.printList();
    
    cout << "\nHapus node akhir : " << endl ;
    p.deleteLast();
    p.printList() ;
    
    cout << "\nHapus node diawal : " << endl ;
    p.deleteFirst() ;
    p.printList() ;
    
    cout << "\nHapus pada posisi 3 : " << endl ;
    p.deletePosisi(3);
    p.printList() ;
    
    cout << "\nCari Posisi : " << endl;
    p.search(50);

    return 0 ;
}