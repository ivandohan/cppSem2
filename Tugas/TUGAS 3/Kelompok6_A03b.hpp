// #include <iostream>
// #include <cctype>
// #include <cstdlib>
// #include <ctime>

#define N 26

using namespace std;

// ========================================= Soal Nomor 1 =============================================

class Vowel
{
	private:
		int ctVowel;
	public:
		void getSentence();
		int cekVowel(char);
		void displayResult();
};

void Vowel::getSentence()
{
	char ch;
	
	cout << "----- Menghitung Huruf Hidup -----" << endl;
	cout << "Tuliskan sebuah kalimat: " << endl;
	ctVowel = 0;
	cin.get(ch);
	while(ch != '\n')
	{
		if (cekVowel(ch))
			ctVowel++;
		cin.get(ch);
	}
}

int Vowel::cekVowel(char ch)
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

void Vowel::displayResult()
{
	cout << "Jumlah huruf hidup = " << ctVowel << endl;
}

// ========================================= Soal Nomor 2 =============================================

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
		hurufClass() { head = NULL; }
		void resetHead() { delete head; head = NULL; }
		void createHurufAcak();
		void printHuruf();
		int cariLetakHuruf(char);
		void putIntoList(int);
		void printLetak();
		~hurufClass() { }
};

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

// ========================================= INTI BODY =============================================


int pilihantugas2();
void soalP2_a();
void soalP2_b();
void soalP2_c();

void TugasPertemuan2()
{
	int pilihan = pilihantugas2();
	char is_continue;

	enum option{SOAL2_1 = 1, SOAL2_2, SOAL2_3, FINISH};

	while(pilihan != FINISH){

		switch(pilihan){
			case SOAL2_1:
				cout << "Soal Pertemuan 2 : Nomor 1" << endl;
                soalP2_a();
				break;
			case SOAL2_2:
				cout << "Soal Pertemuan 2 : Nomor 2" << endl;
                soalP2_b();
				break;
			case SOAL2_3:
				cout << "Soal Pertemuan 2 : Nomor 3" << endl;
                soalP2_c();
				break;
			default:
				cout << "Tidak Dikenali" << endl;
				break;
		}

		label_continue:

		cout << "\nLihat Nomor Lain? (y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){
			pilihan = pilihantugas2();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else {
			goto label_continue;
		}
	}

}


int pilihantugas2()
{
    int input;
	system("CLS");
	// system("cls");
	cout << "\nTugas Pertemuan 2" << endl;
	cout << "=============================" << endl;
	cout << "1. Menghitung Jumlah Huruf Hidup dalam Suatu Kalimat" << endl;
	cout << "2. Tabulasi Banyak Angka dan Abjad pada Sebuah Kalimat" << endl;
	cout << "3. Mencari Huruf pada Tumpukan Char" << endl;
	cout << "4. END" << endl;
	cout << "=============================" << endl;
	cout << "Pilih [1-4]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	return input;
}

void soalP2_a()
{
    Vowel myVowel;
	
	myVowel.getSentence();
    cout << "Hasil = " << endl;
	myVowel.displayResult();
}

void soalP2_b(){
	cout << "Dalam Proses" << endl;
}

void soalP2_c()
{
    hurufClass myHrf;
	char hrf, jwb;
	int letak;
	
	do
	{
		system("cls");
		myHrf.resetHead();
		myHrf.createHurufAcak();

		cout << "----- Mencari Huruf dalam array -----" << endl;
		cout << "Berikan sebuah huruf = ";
		cin >> hrf;

		letak = myHrf.cariLetakHuruf(hrf);
		if (letak == -99)
			cout << "Huruf " << hrf << " tidak ada dalam array" << endl;
		else
		{
			cout << "Huruf " << hrf << " ada di posisi:" << endl;
			myHrf.printLetak();
		}
		myHrf.printHuruf();
		
		cout << "Cari Lagi (y/t)? ";
		cin >> jwb;
	} while (jwb == 'Y');
}