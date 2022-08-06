#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define N 26

using namespace std;

typedef struct posisi PosisiHrf;
struct posisi									// buka file, akan ditulis, tutup file.
{
	int pos;
	PosisiHrf *next;
};

class hurufClass
{
	private:
		char Huruf[N]; // penampung huruf acak
		PosisiHrf *head;
	public:
		fstream myFile; //===============================================================
		int benar, salah, jlh_game;


		void openFile(){
			myFile.open("gihon.txt", ios::app);
		}

		void closeFile(){
			myFile.close();
		}

		hurufClass() { head = NULL; }
		void resetHead() { delete head; head = NULL; }
		void createHurufAcak();
		void printHuruf();
		int cariLetakHuruf(char);
		void putIntoList(int);
		void printLetak();

		void catatHurufacak();
		void catatStatistik();

		~hurufClass() { }
};

int main()
{
	hurufClass myHrf;
	char hrf, jwb;
	int letak;

	//===========================================
	int benar = 0, salah = 0, jlh_game = 0;
	
	do
	{
		system("cls");
		myHrf.resetHead();
		myHrf.createHurufAcak();

		cout << "Mencari Huruf dalam array" << endl;
		cout << "Berikan sebuah huruf ";
		cin >> hrf;

		letak = myHrf.cariLetakHuruf(hrf);
		if (letak == -99)
		{
			cout << "Huruf " << hrf << " tidak ada dalam array" << endl;
			salah++;
		}
		else
		{
			cout << "Huruf " << hrf << " ada di posisi:" << endl;
			myHrf.printLetak();
			benar++;
		}
		myHrf.printHuruf();
		
		jlh_game++;

		myHrf.catatHurufacak();

		myHrf.salah = salah;
		myHrf.benar = benar;
		myHrf.jlh_game = jlh_game;

		//Debugging
		cout << "Benar : " << myHrf.salah << endl;
		cout << "Salah : " << myHrf.benar << endl;
		cout << "Game  : " << myHrf.jlh_game << endl;


		cout << "Ulang (Y/T)? ";
		cin >> jwb;

	} while (jwb == 'Y');

	myHrf.catatStatistik();

    return 0;
}

void hurufClass::catatHurufacak(){
	openFile();

	//Cara nulis ke file
	myFile << string(Huruf);

}

void hurufClass::catatStatistik(){

}

void hurufClass::createHurufAcak()
{
	srand(time(NULL));

	for(int i=0; i<N; i++)
		Huruf[i] = ((rand() % N) + 65);
}

void hurufClass::printHuruf()
{
	cout << "Huruf Acak: " << endl;
	for(int i=0; i<N; i++)
		cout << (char) Huruf[i] << " ";
	cout << endl;
}

int hurufClass::cariLetakHuruf(char hrf)
{
    int letak = -99;

	if((hrf & 32) == 32)
		hrf ^= 32;
    for(int i=0; i<N; i++)
    {
        if(hrf == Huruf[i])
		{
            letak = i;
			putIntoList(letak);
		}
    }

    return letak;
}

void hurufClass::putIntoList(int letak)
{
	PosisiHrf *temp, *tail;
	
	temp = new PosisiHrf;
	temp->pos = letak;
	temp->next = NULL;
	
	if(head == NULL)
		head = temp;
	else
	{
		tail = head;
		while(tail->next)
			tail = tail->next;
		tail->next = temp;
	}
}

void hurufClass::printLetak()
{
	PosisiHrf *temp;
	
	temp = head;
	
	while (temp)
	{
		cout << temp->pos + 1;
		temp = temp->next;
		if (temp)
		{
			if(temp->next == NULL)
				cout << " dan ";
			else
				cout << ", ";
		}
	}
	cout << endl;
}