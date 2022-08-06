// file name: list1b.cpp
#include <iostream>
using namespace std ;


class Node {
public:
    int data ;
    Node* link ;
    Node() { link = NULL;}    // constructor
    Node(int val) { data = val ; link = NULL; }
};

int main() {
    Node* L = new Node(5) ; //create node
    cout << L->data << "-->" << endl ; // tampilkan
    L->link = new Node(7) ; // create node baru diakhir
    
    /* atau cara barikut,
    Node* temp = new Node(12) ; // create node baru
    L->link = temp ; // tambahkan diakhir
    */

    /* atau cara bekiut, tamabahkan diakhir
    Node* temp = new Node(12) ; // create node baru
    temp->link = L ; // link ke point to L
    L = temp ; // L point to temp
    */
    
    cout << L->data << "-->" ; // tampilkan
    cout << L->link->data << "-->" << endl ;
    return 0;
}
