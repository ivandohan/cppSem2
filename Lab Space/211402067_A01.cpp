/*
		Nama File		: 211402067_A01.cpp

		Nama			: Ivandohan Samuel Siregar
		NIM				: 211402067

		---------- Modifikasi Program Latihan pada Kuliah 4 (File Handling) ----------
*/ 

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

#define N 26

using namespace std;

typedef struct posisi PosisiHrf;
struct posisi
{
	int pos;
	PosisiHrf *next;
};

class hurufClass
{
	private:
		char Huruf[N];
		PosisiHrf *head;
	public:
		fstream myFile;
		string username;
		int benar, salah, jlh_game;

		hurufClass() { head = NULL; }

		void openFile(){
			myFile.open("211402067_A01.txt", ios::app | ios::in);
		}
		void closeFile(){
			myFile.close();
		}

		void resetHead() { delete head; head = NULL; }
		void createHurufAcak();
		void printHuruf();
		int cariLetakHuruf(char);
		void putIntoList(int);
		void writeIntoFileP1();
		void writeIntoFileP2();
		void printLetak();
		~hurufClass() { }
};

int main()
{
	hurufClass myHrf;
	char hrf, jwb;
	int flag, letak, salah = 0, benar = 0, jlh_game = 0;

	system("CLS");

	cout << "\nProgram Tebak-Tebakan Huruf Acak" << endl;
	cout << "================================\n" << endl;

	cout << "Username				 : ";
	cin >> myHrf.username;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	myHrf.openFile();
	myHrf.myFile << "===== " << "Username : " << myHrf.username << " =====" << "\nHuruf Acak = " << endl;
	myHrf.closeFile();

	cout << "Halo, " << myHrf.username << "! Semoga Beruntung!" << endl;
	cout << "\nTekan <enter> untuk melanjutkan...";
	
	flag = getchar();

	cout << "Sedang membuka program....";
	this_thread::sleep_for(600ms);

	do
	{
		system("cls");
		myHrf.resetHead();
		myHrf.createHurufAcak();

		cout << "===== Saatnya Menebak! =====" << endl;
		cout << "\n-> " << myHrf.username << " (Anda)" << endl;
		cout << "\nTebak sebuah huruf  		: ";
		cin >> hrf;

		letak = myHrf.cariLetakHuruf(hrf);
		if (letak == -99){
			cout << "\nOopss, huruf " << hrf << " tidak tersedia.\nTebakan anda salah!\n" << endl;
			salah++;
		}
		else
		{
			cout << "\nYeayy, huruf " << hrf << " tersedia.\nTebakan anda benar!\n" << endl;
			cout << "Posisi			 	: ";
			myHrf.printLetak();
			benar++;
		}

		myHrf.printHuruf();

		jlh_game++;

		myHrf.benar = benar;
		myHrf.salah = salah;
		myHrf.jlh_game = jlh_game;

		cout << "\nBenar	: " << benar << endl;
		cout << "Salah	: " << salah << endl;
		cout << "Game	: " << jlh_game << endl;

		myHrf.writeIntoFileP1();

		cout << "\nTebak Lagi? (y/t) ";
		cin >> jwb;
	} while (jwb == 'y');
	
	myHrf.writeIntoFileP2();
    
	cout << "~ Bye bye ...\n" << endl;

	return 0;
}

void hurufClass::writeIntoFileP1()
{
	string cvhuruf = Huruf;
	openFile();
	// myFile << string(Huruf) << endl;
	myFile << cvhuruf << endl;
	closeFile();
}

void hurufClass::writeIntoFileP2()
{
	openFile();

	myFile << "\nBenar		= " << benar << endl;
	myFile << "Salah		= " << salah << endl;
	myFile << "Jumlah Game	= " << jlh_game << endl;
	// myFile << "=================================== <END>" << endl;
	myFile << "\n";

	closeFile();
}

void hurufClass::createHurufAcak()
{
	srand(time(NULL));

	for(int i=0; i<N; i++)
		Huruf[i] = ((rand() % N) + 65);
}

void hurufClass::printHuruf()
{
	cout << "Huruf-huruf acak yang tersedia	: " << endl;
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
				cout << ", dan ";
			else
				cout << ", ";
		}
	}
	cout << endl;
}