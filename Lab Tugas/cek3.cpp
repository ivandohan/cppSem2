

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int ayah;
    int ibu;
    int jlhAnak;
    int jlhPendapatan;
    int jlhAnggota;
    string namaAyah;
    string namaIbu;
    string namaKeluarga;

    Node* next;
    Node* prev;

    Node(int a, int b, int c, int d, string e, string f, string g){
        ayah = a;
        ibu = b;
        jlhAnak = c;
        jlhPendapatan = d;
        namaAyah = e;
        namaIbu = f;
        namaKeluarga = g;
        jlhAnggota = a + b + c;
        next = NULL;
    }
};

class Keluarga {
public:
    Node* head;
    Node* sorted;
    int pengeluaran;
    int totalOrang = 0;
    double mean = 0;

    void pushValue(Node **head_ref, int ayah, int ibu, int jlhAnak, int pendapatan, 
    string nmAyah, string nmIbu, string nmFam){
        Node* newNode = new Node(ayah, ibu, jlhAnak, pendapatan, nmAyah, nmIbu, nmFam);
        newNode->next = *head_ref;
        if(*head_ref != NULL)
            (*head_ref)->prev = newNode;
	    *head_ref = newNode;
    }

    void setPengeluaranKeluarga(int a){
        this->pengeluaran = a;
    }

    void sorting(Node*);
    void sortingKategori(Node*, int);

    void jlhWarga(Node*);
    void meanPendapatan(Node*);
    void cekMampu(Node*);

    void printListSorting(Node*);
};

void Keluarga::sorting(Node* headref)
{
    int opsi;
    sorted = NULL;
    Node* current = headref;

    cout << "Sorting Berdasarkan  : " << endl;
    cout << "1. Jumlah Anak Terbanyak" << endl;
    cout << "2. Pendapatan Keluarga Terbesar" << endl;
    cout << "Pilihan [1-2] : ";
    cin >> opsi;
    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL) {
        // Store next for next iteration
        Node* next = current->next;
        // insert current in sorted linked list
        sortingKategori(current, opsi);
        // Update current
        current = next;
    }
    // Update head_ref to point to sorted linked list
    head = sorted;
}

void Keluarga::sortingKategori(Node* newnode, int opsi)
{
    switch(opsi){
        case 1:{
            if (sorted == NULL || sorted->jlhAnak <= newnode->jlhAnak) {
                newnode->next = sorted;
                sorted = newnode;
            }
            else {
                Node* current = sorted;
                while (current->next != NULL
                    && current->next->jlhAnak > newnode->jlhAnak) {
                    current = current->next;
                }
                newnode->next = current->next;
                current->next = newnode;
            }
        }
            break;
        
        case 2:{
            if (sorted == NULL || sorted->jlhPendapatan <= newnode->jlhPendapatan) {
                newnode->next = sorted;
                sorted = newnode;
            }
            else {
                Node* current = sorted;
                while (current->next != NULL
                    && current->next->jlhPendapatan > newnode->jlhPendapatan) {
                    current = current->next;
                }
                newnode->next = current->next;
                current->next = newnode;
            }
        }
    }
}

void Keluarga::meanPendapatan(Node* head)
{
    double i, x;
    while(head != NULL){
        i++;
        x += head->jlhPendapatan;
        head = head->next;
    }
    mean = x/i;

    cout << "Rata-rata pendapatan tiap keluarga di daerah X = " << mean << endl;
}

void Keluarga::jlhWarga(Node* head){
    while(head != NULL){
        totalOrang += head->jlhAnggota;
        head = head->next;
    }

    cout << "Jumlah total orang dari seluruh keluarga di daerah X = " << totalOrang << endl;
}

void Keluarga::cekMampu(Node* head)
{
    int Net;
    while(head != NULL){
        Net = pengeluaran * (head->jlhAnggota);
        if(head->jlhPendapatan < Net){
            cout << "Keluarga " << head->namaKeluarga << " kurang mampu" << endl;
        }else{
            cout << "Keluarga " << head->namaKeluarga << " mampu" << endl;
        }
        head = head->next;
    }
}

void Keluarga::printListSorting(Node* head)
{
    while(head != NULL){
        cout << head->namaAyah << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Keluarga list;
    list.head = NULL;

    list.pushValue(&list.head,1,1,3,8000,"Ucup", "Lisa", "Siregar");
    list.pushValue(&list.head,1,1,1,10000,"Ivando", "Rin", "DOhann");
    list.pushValue(&list.head,1,1,1,10000,"Asep", "Butet", "DOhann");

    list.jlhWarga(list.head);

    list.sorting(list.head);
    list.printListSorting(list.head);

    list.setPengeluaranKeluarga(2000);
    list.cekMampu(list.head);
    list.meanPendapatan(list.head);
}