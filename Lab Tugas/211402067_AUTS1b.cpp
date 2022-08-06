/*
        Nama File   : 211402067_AUTS1b.cpp
        NIM         : 211402067
        Nama        : Ivandohan Samuel Siregar
        
*/


#include <iostream>
#include <cctype>
#define N 100

using namespace std;

class Vowels
{
	private:
		int ctVowel;
        char ch[N];
	public:
		void getSentence();
		int cekVowel(char);
		void printResult();
};

void Vowels::getSentence()
{
	cout << "Input sebuah kalimat :  ";
	ctVowel = 0;
	cin.get(ch, N);

    for(int i = 0; i < N; i++){
        if(cekVowel(ch[i]))
            ctVowel++;
    }
}

int Vowels::cekVowel(char ch)
{
	switch(toupper(ch))
	{
		case 'A':
		case 'I':
		case 'U':
		case 'E':
		case 'O': return 1;
			break;
		default: return 0;
	}
}

void Vowels::printResult()
{
    cout << "\n== Hasil Penghitungan ==" << endl;
    cout << "Kalimat yang diinput   : " << ch << endl;
	cout << "Jumlah huruf hidup     : " << ctVowel << endl;
}

int main()
{
	Vowels myVowel;

    system("CLS");
    cout << "== Program Penghitung Jumlah Vowel dalam Kalimat ==" << endl;

	myVowel.getSentence();
	myVowel.printResult();
	
	return 0;
}