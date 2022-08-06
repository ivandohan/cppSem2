#include<iostream> //IOSTREAM
#include<cstring>
#include<cstdlib>

using namespace std; //NAMESPACE

class buku	{ //CLASS
//ACCESS SPECIFIER
private:
	char *penulis,*judul,*penerbit;
	float *harga;
	int *stok;
public:	
	buku()	
    {
        penulis= new char[30];
	    judul=new char[30];
	    penerbit=new char[30];
	    harga= new float;
	    stok=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
};

void buku::feeddata()	{
	cin.ignore();
	cout<<"\nNama penulis: ";   cin.getline(penulis,30); //GETLINE
	cout<<"Judul buku: ";       cin.getline(judul,30); //GETLINE
	cout<<"Nama penerbit: ";    cin.getline(penerbit,30); //GETLINE
	cout<<"Harga: ";            cin>>*harga; 
	cout<<"Stok: ";             cin>>*stok;   
	
}

void buku::editdata()	{
	
	cout<<"\nNama penulis: ";   cin.getline(penulis,30); //GETLINE
	cout<<"Judul buku: ";       cin.getline(judul,30); //GETLINE
	cout<<"Nama penerbit: ";    cin.getline(penerbit,30); //GETLINE
	cout<<"Harga: ";            cin>>*harga;
	cout<<"Stok: ";             cin>>*stok;   
	
}

void buku::showdata()	{
	cout<<"\nNama penulis: "<<penulis;
	cout<<"\nJudul buku: "<<judul;
	cout<<"\nNama penerbit: "<<penerbit;
	cout<<"\nHarga: "<<*harga;
	cout<<"\nStok: "<<*stok;   
	
}

int buku::search(char jbuy[20],char pbuy[30] )	{
	if(strcmp(jbuy,judul)==0 && strcmp(pbuy,penulis)==0)
		return 1;
	else return 0;
		
}

void buku::buybook()	{
	int count;
	cout<<"\nMasukkan jumlah buku yang ingin dibeli: ";
	cin>>count;
	if(count<=*stok)	{
		*stok=*stok-count;
        cout<<"\nHarga: Rp. "<<(*harga)*count;
		cout<<"\nBerhasil dibeli";
	}
	else
		cout<<"\nStok tidak tersedia";
}

int main()	{
	buku *B[30];
	int i=0,r,t,choice;
	char judulbuy[20],penulisbuy[30];
	while(1)	{
		cout<<"\n\n\tMENU"
		<<"\n1. Memasukkan buku baru"
		<<"\n2. Edit data buku"
		<<"\n3. Mencari buku"
		<<"\n4. Membeli buku"
		<<"\n5. Exit"
		<<"\n\nMasukkan no pilihan dari menu: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new buku;
				B[i]->feeddata();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nJudul buku: "; cin.getline(judulbuy,30);
				cout<<"Penulis buku: ";  cin.getline(penulisbuy,30);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(judulbuy,penulisbuy))	{
						cout<<"\nBuku berhasil ditemukan";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nStok tidak tersedia";
				break;

			case 3: cin.ignore();
				cout<<"\nJudul buku: "; cin.getline(judulbuy,30); //GETLINE
				cout<<"Penulis buku: ";  cin.getline(penulisbuy,30); //GETLINE
				for(t=0;t<i;t++)	{
					if(B[t]->search(judulbuy,penulisbuy))	{
						cout<<"\nBuku berhasil ditemukan";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nStok tidak tersedia";
				break;
			
			case 4: cin.ignore();
				cout<<"\nJudul buku: "; cin.getline(judulbuy,30); //GETLINE
				cout<<"Penulis buku: ";  cin.getline(penulisbuy,30); //GETLINE
				for(t=0;t<i;t++)	{
					if(B[t]->search(judulbuy,penulisbuy))	{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nStok tidak tersedia";
			    break;
			case 5: exit(0);
			default: cout<<"\nInvalid";
			
		}
	}
	
	
	
	
	return 0;
}