// Nama : Tito Trinidad Situmorang
// Nim  : 211402133
// Program queue untuk menyimpan jenis-jenis data

#include<iostream>

using namespace std;

template<class T>                  //template class
struct Node                       //struct node
{
    T  val;
    Node *next;
};

template<class T>                 //template class
 class Queue                                    
{
    private:
        Node <T> *first;
        Node <T> *trav;
        T empty;
    public:
        Queue() 
        {
            first=NULL;
            empty=1;
        }
        ~Queue(){}
        void push(T x);
        T pop();
        void print();
        T is_empty();
};

template <class T>
void Queue<T>::push(T x)           //fungsi push data
{
    Node <T> *temp;
    temp = new Node <T>;
    temp->val = x;
    temp->next = NULL;
    if(first == NULL)
        first = temp;
    else 
    {
        trav = first;
        while(trav->next!=NULL)
            trav = trav->next;
        trav->next = temp;
    }
    empty=0;
}

template<class T>
T Queue<T>::pop()                            //fungsi pop data
{ 
    if(first == NULL)
    {
        cout << "Queue Kosong" << endl;
        return -1;
    }
    else
    {
        int r = first->val; first = first->next;
        if(first == NULL)
            empty = 1;
        return r;
    }
}

template <class T>                            //fungsi print data
void Queue<T>::print()
{
    trav = first;
    while(trav != NULL)
    {
        cout << trav->val << endl;
        trav = trav->next;
   }
}

template <class T>                           //fungsi cek data empty atau tidak
T Queue<T>::is_empty()
{
    return empty;
}

int main()     //fungsi main
{
    Queue<int> q;
    Queue<double> r;
// menyimpan jenis-jenis data pada queue     
    //untuk bilangan double
    r.push(4.0);
    r.push(4.7);
    r.print();
    r.pop();
    
    // untuk bilangan integer
    q.push(10);
    q.push(9);
    q.print();
    
;
    while(!q.is_empty()){
        cout << "Popping out (" << q.pop()<< ")..." << endl;
    }
        
    system("pause");

    return 0;
}