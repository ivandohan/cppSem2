// Nama file: hurufAcak.cpp
// Menyimpan dan mencari huruf di dalam array yang berisi huruf secara acak

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#define N 26

using namespace std;

class Huruf
{
	private:
		ofstream output_file;
		char filename[80];
		char Abjad[N];
		int ct;
		char ch;
	
	public:
		Huruf(char []);
		void openFile() {output_file.open(filename);}
		void closeFile() {output_file.close();}
		void printAbjad();
		void cariHuruf();
		void printHasil();
		void printHuruf(){
			cout << "Huruf yang dicari: " << ch << endl;
		}
		~Huruf(){}
};

Huruf::Huruf(char fname[])
{
	strcpy(filename, fname);
	srand(time(0));
	
	ct = 0;
	for(int i=0; i<N; i++)
	{
		Abjad[i] = (rand() % N) + 65;
	}
}

void Huruf::printAbjad()
{
	for(int i=0; i< N; i++)
	{
		if(Abjad[i] == toupper((char)ch))
		{
			cout << "Found " << char(toupper(ch)) <<"!"<<endl;
			if((i>0) && (i%10 == 0))
				output_file << endl;
			output_file << "<<" << Abjad[i] << ">>" << " ";
		}
		else
		{
			if((i>0) && (i%10 == 0))
				output_file << endl;
			output_file << Abjad[i] << " ";
		}
	}
	output_file << endl;
}

void Huruf::cariHuruf()
{
	cout << "Berikan sebuah huruf: ";
	cin.get(ch);

	for(int i=0; i<N; i++)
	{
		if(toupper((char)ch) == Abjad[i])
		{
			ct++;
		}
	}
}

void Huruf::printHasil()
{
	output_file << "Ada " << ct << " huruf " 
	            << char(toupper(ch)) << endl;
}

int main()
{
	Huruf acakHuruf("abcd.txt");
	
	acakHuruf.openFile();
	acakHuruf.cariHuruf();
	acakHuruf.printHuruf();
	acakHuruf.printAbjad();
	acakHuruf.printHasil();
	acakHuruf.closeFile();

	return 0;
}