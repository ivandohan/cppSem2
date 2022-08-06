// file name: list1a.cpp
#include <iostream>
using namespace std ;

class Node {
public:
    int data ;
    Node* link ;
    Node() { link = NULL; } // constructor default
};
int main() {
    Node* L ;
    L = new Node() ; // create node
    L->data = 5 ; // isikan data
    L->link = NULL ;
    
    cout << L->data << "-->" << endl ; //tampilkan
    
    L->link = new Node() ; // create node diakhir list
    L->link->data = 7 ; // isikan data
    L->link->link = NULL;
    
    /*
    crete node baru beri nama temp
    Node* temp ;
    temp = new Node ;
    temp->data = 7 ;
    temp->link = NULL ;
    L->link = temp ; // tambah diakhir
    temp->link = L ; // dua baris ini utk menambah
    L = temp ; // node didepan (awal)
    */
    
    cout << L->data << "-->" ; // tampilkan
    cout << L->link->data << "-->" << endl ;
    
    return 0;
}