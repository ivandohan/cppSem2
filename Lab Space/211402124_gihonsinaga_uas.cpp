#include <iostream>

using namespace std;

// class
class Convert{
    // Access Specifier
    public:
        //Attribute
        //tipe_data nama_variable
        float konversi;
        float hitung_konversi();
        float hitung_konversi2();
        //Method
        //tipe_method nama_method() 
        void OtherToRp();
        void RpToOther();
};
// inheritance
// Multiple Inheritance
class Konversi_matauang:public Convert{
    private:
        int menu, uang, total;
        int pilih;
        float n, dollar, rupee, euro, baht;
    public:
       void OtherToRp(){

        menu:
        cout << endl; 
        cout << "PROGRAM CONVERT MATA UANG ASING KE MATA UANG INDONESIA(RUPIAH)" << endl;
        cout << "1. US Dollar --> Rupiah " << endl;
        cout << "2. Rupee --> Rupiah " << endl;
        cout << "3. Euro --> Rupiah " << endl;
        cout << "4. Baht --> Rupiah " << endl;
        cout << "5. Back "<< endl;
        cout << endl;

        cout<<"Pilih salah satu : ";
        cin >> pilih;
        cout << endl;
       }
       
       float hitung_konversi(){
        switch(pilih){
            
            case 1 :
            { 
                cout<<"Masukkan jumlah 'US Dollar' yang diinginkan : ";
                cin>> n;
                cout<<endl;
                dollar = n*14539;
                cout<<n<<" US Dollar = Rp."<<dollar<<endl;
                cout<<endl;
                break;
            }
            
            case 2 :
            {
                cout<< "Masukkan jumlah 'Rupee' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                rupee = n*187;
                cout<<n<<" Rupee = Rp."<<rupee<<endl;
                cout<<endl;
                break;
            }            

            case 3 :
            {
                cout<< "Masukkan jumlah 'Euro' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                euro = n*15609;
                cout<<n<<" Euro = Rp."<<euro<<endl;
                cout<<endl;
                break;
            }
            
            case 4 :
            {
                cout<< "Masukkan jumlah 'Baht' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                baht = n*426;
                cout<<n<<" Baht = Rp."<<baht<<endl;
                cout<<endl;
                break;

            }
        }
    }
};

// Multiple Inheritance
class Konversi_matauang2:public Convert{
    private:
        int menu, uang, total;
        int pilih;
        float n, dollar, rupee, euro, baht;
    public:
        void RpToOther(){
            menu:
            cout << endl; 
            cout << "PROGRAM CONVERT MATA UANG INDONESIA KE MATA UANG LUAR(ASING)" << endl;
            cout << "1. Rupiah --> US Dollar " << endl;
            cout << "2. Rupiah --> Rupee " << endl;
            cout << "3. Rupiah --> Euro " << endl;
            cout << "4. Rupiah --> Baht " << endl;
            cout << endl;

            cout<<"Pilih salah satu : ";
            cin >> pilih;
            cout << endl;
        }

    float hitung_konversi2(){
        switch(pilih){
            
            case 1 :
            { 
                cout<<"Masukkan jumlah 'Rupiah' yang diinginkan : ";
                cin>> n;
                cout<<endl;
                dollar = n/14539;
                cout <<"Rp." <<n<<" = "<<dollar<<" dollar"<<endl;
                cout<<endl;
                break;
            }
            
            case 2 :
            {
                cout<< "Masukkan jumlah 'Rupiah' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                rupee = n/187;
                cout <<"Rp." <<n<<" = "<<rupee<<" rupee"<<endl;
                cout<<endl;
                break;
            }            

            case 3 :
            {
                cout<< "Masukkan jumlah 'Rupiah' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                euro = n/15609;
                cout <<"Rp." <<n<<" = "<<euro<<" euro"<<endl;
                cout<<endl;
                break;
            }
            
            case 4 :
            {
                cout<< "Masukkan jumlah 'Rupiah' yang diinginkan : ";
                cin>>n;
                cout<<endl;
                baht = n/426;
                cout <<"Rp." <<n<<" = "<<baht<<" baht"<<endl;
                cout<<endl;
                break;
            }
        }        
    }
};

int main(){
    // deklarasi objek
    Konversi_matauang obj;
    Konversi_matauang2 ob;
    char opsi;

    do{
        cout << endl;
        cout << "PROGRAM CONVERT NILAI MATA UANG" << endl;
        cout << "1. convert mata uang asing ke rupiah " << endl;
        cout << "2. convert rupiah ke mata uang asing" << endl;
        cout << "3. Quit " << endl;

        cout << "pilih salah satu : ";
        cin >> opsi;

        switch(opsi){

        case '1' :
            obj.OtherToRp();
            obj.hitung_konversi();
            break;

        case '2' :
            ob.RpToOther();
            ob.hitung_konversi2();
            break;
        }
    }
    while(opsi < '2');
    return 0;
}