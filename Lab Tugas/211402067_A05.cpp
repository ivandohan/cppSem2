/*
        Nama File       : 211402067_A05.cpp
        Nama            : Ivandohan Samuel Siregar
        NIM             : 211402067

        ==== Tugas Pemrograman 5 : Soal Nomor 3 ====
*/

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
    int pengeluaran = 0;
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

    void printData(Node*);
    void printListSorting(Node*);
    void continueMenu(){
        char opsi;
        label_continue2:
        cout << "\nLanjut ke menu utama [y/n]...";
        cin >> opsi;

        if ( (opsi == 'y') | (opsi == 'Y')){
            goto label_stop;
        } else if ((opsi == 'n') | (opsi == 'N')){
            goto label_continue2;
        } else {
            goto label_continue2;
        }
        label_stop:

        cout << "OKE" << endl;
    }
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
    cout << "===============================" << endl;
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

    cout << "Rata-rata pendapatan tiap keluarga di daerah X = Rp" << mean << endl;
    continueMenu();
}

void Keluarga::jlhWarga(Node* head){
    while(head != NULL){
        totalOrang += head->jlhAnggota;
        head = head->next;
    }
    cout << "Jumlah total orang dari semua keluarga = " << totalOrang << endl;
    continueMenu();
}

void Keluarga::cekMampu(Node* head)
{
    int Net;
    while(head != NULL){
        Net = pengeluaran * (head->jlhAnggota);
        if((head->jlhPendapatan) < Net){
            cout << "Keluarga " << head->namaKeluarga << " kurang mampu" << endl;
        }else {
            cout << "Keluarga " << head->namaKeluarga << " mampu" << endl;
        }
        head = head->next;
    }
    continueMenu();
}

void Keluarga::printListSorting(Node* head)
{
    int i;
    while(head != NULL){
        i++;
        cout << i << ". Keluarga " << head->namaKeluarga << endl;
        cout << "Jumlah Pendapatan Keluarga : Rp" << head->jlhPendapatan << endl;
        cout << "Jumlah Anggota Keluarga    : " << head->jlhAnggota << endl;
        cout << "********************************\n" << endl;
        head = head->next;
    }
    cout << endl;
    continueMenu();
}

void Keluarga::printData(Node* head){
    int i = 0;
    while(head != NULL){
        i++;
        cout << i << ". Keluarga " << head->namaKeluarga << endl;
        cout << "==========================" << endl;
        cout << "Nama Ayah                  : " << head->namaAyah << endl;
        cout << "Nama Ibu                   : " << head->namaIbu << endl;
        cout << "Jumlah Pendapatan Keluarga : Rp" << head->jlhPendapatan << endl;
        cout << "Jumlah Anggota Keluarga    : " << head->jlhAnggota << endl;
        cout << "==========================\n" << endl;
        head = head->next;
    }
    continueMenu();
}

int getOption();

int main()
{

    Keluarga list;
    list.head = NULL;

    //Sesi input data linked list
    //Berikut maksud dari isi parameternya :
    //(alamat head, jlhAyah, jlhIbu, jlhAnak, jlhPendapatan, nama ayah, nama ibu, nama keluarga)
    list.pushValue(&list.head,1,1,10,8000,"Ucup", "Lisa", "Pak Ucup");
    list.pushValue(&list.head,1,1,7,12000,"Asep", "Butet", "Pak Asep");
    list.pushValue(&list.head,1,1,1,10000,"Aldi", "Andine", "Pak Aldi");
    list.setPengeluaranKeluarga(2000);

    //Sesi menu index program
    label_start:
    system("CLS");
    int pilihan = getOption();
    char opsi;

    if(pilihan == 1){
        list.jlhWarga(list.head);   //Menghitung jumlah total orang di daerah X
        goto label_start;
    } else if(pilihan == 2){
        list.sorting(list.head);    //Meminta kategori sort dari user dan melakukan sort
        list.printListSorting(list.head);
        goto label_start;
    } else if(pilihan == 3){
        list.meanPendapatan(list.head); //Menghitung rata-rata pendapatan keluarga
        goto label_start;
    } else if(pilihan == 4){
        list.cekMampu(list.head);   //Mengecek tingkat kemampuan keluarga
        goto label_start;
    } else if(pilihan == 5){
        list.printData(list.head);  //Menampilkan seluruh data
        goto label_start;
    } else if(pilihan == 6){
        goto label_stop;            //Terminator program
    }

    label_stop:
    // cout << "E N D" << endl;

    return 0;
}

int getOption()
{
    int pilihan;
    system("CLS");
    cout << "=== Survei Keluarga di Daerah X ===" << endl;
    cout << "***********************************" << endl;
    cout << "1. Jumlah total orang dari semua keluarga" << endl;
    cout << "2. Sortir data keluarga" << endl;
    cout << "3. Nilai pendapatan rata-rata" << endl;
    cout << "4. Survei keluarga mampu" << endl;
    cout << "5. Print seluruh data keluarga" << endl;
    cout << "6. FINISH." << endl;
    cout << "\n**************************" << endl;
    cout << "Pilihan [1-5] ? : ";
    cin >> pilihan;

    return pilihan;
}