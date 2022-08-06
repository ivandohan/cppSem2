// #include <iostream>
// #include <string>
// #include <fstream>
// #include <limits>
// #include <iomanip>

using namespace std;

// ========================================= Soal Nomor 1 =============================================
class Alfabet
{
    private:
        string filename;
    public:
        fstream output_file;
        Alfabet(string filename) {
            Alfabet::filename = filename;
        }
        void openFile() {
            output_file.open(filename, ios::out | ios::in);
        }
        void writeFile();
        void readFile();
        void closeFile() {output_file.close();}
};

void Alfabet::writeFile()
{
    openFile();
    for(char hrf='A'; hrf <= 'Z'; hrf++)
        output_file << int(hrf) << "\n";
    closeFile();
}

void Alfabet::readFile()
{
    openFile();

    if (output_file.is_open()){
        string line;
        while (getline(output_file, line)){
            int num = 0;
            for(int i = 0; i < line.length(); i++){
                num = num * 10 + (line[i] - '0');
                if(num>=32 && num<=122){
                    char ch = (char)num;
                    cout << ch << " ";
                    num = 0;
                }
            }
        }
    }

    closeFile();
}

// ========================================= Soal Nomor 2 =============================================
class Filing
{
    public:
        fstream output;
        fstream input;
        
        string Ofilename = "Kelompok6_A03b_output.txt";
        string ifilename = "Kelompok6_A03b_input.txt";

        void openOfile(){
            output.open(Ofilename, ios::in | ios::app);
        }
        void openIfile(){
            input.open(ifilename, ios::out | ios::in);
        }
        void closefile(){
            output.close();
            input.close();
        }
};

class Suhu {
    public:
        double suhu, c, k, f, r;
        void takeData(){
            Filing myFile;
            myFile.openIfile();
            cout << "Input Suhu  = ";
            cin >> suhu;
            myFile.input << suhu;
        }

        void celcius(){
            Filing myFile;
            myFile.openIfile();
            myFile.openOfile();
            takeData();
        
            myFile.input >> c;        
            f = ((9 * c) / 5) + 32;
            k = 273 + c;
            r = (4 * c) / 5;

            // Menuliskan hasil ke consol/terminal
            cout << "++++++++++++++++++++" << endl;
            cout << "Reamur      = " << r << endl;
            cout << "Fahrenheit  = " << f << endl;
            cout << "Kelvin      = " << k << endl;
            cout << "++++++++++++++++++++\n" << endl;
            
            // Menuliskan hasil ke file output
            myFile.output << c << setw(10) << r << setw(10)
                            << f << setw(10) << k << endl; 

            myFile.closefile();
        }

        void reamur(){
            Filing myFile;
            myFile.openIfile();
            myFile.openOfile();
            takeData();

            myFile.input >> r;
            c = ((5 * r) / 4);
            f = ((9 * r) / 4) + 32;
            k = ((5 * r) / 4) + 273;

            // Menuliskan hasil ke consol/terminal
            cout << "++++++++++++++++++++" << endl;
            cout << "Celcius     = " << c << endl;
            cout << "Fahrenheit  = " << f << endl;
            cout << "Kelvin      = " << k << endl;
            cout << "++++++++++++++++++++\n" << endl;
            
            // Menuliskan hasil ke file output
            myFile.output << c << setw(10) << r << setw(10)
                            << f << setw(10) << k << endl;

            myFile.closefile();
        }

        void fahrenheit(){
            Filing myFile;
            myFile.openIfile();
            myFile.openOfile();
            takeData();

            myFile.input >> f;
            c = (5 * (f - 32)) / 9;
            k = 273 + c;
            r = (4 * (f - 32)) / 9;

            // Menuliskan hasil ke consol/terminal
            cout << "++++++++++++++++++++" << endl;
            cout << "Celcius     = " << c << endl;
            cout << "Reamur      = " << r << endl;
            cout << "Kelvin      = " << k << endl;
            cout << "++++++++++++++++++++\n" << endl;
            
            // Menuliskan hasil ke file output
            myFile.output << c << setw(10) << r << setw(10)
                            << f << setw(10) << k << endl;
            
            myFile.closefile();
        }

        void kelvin(){
            Filing myFile;
            myFile.openIfile();
            myFile.openOfile();
            takeData();

            myFile.input >> k;
            c = k - 273;
            f = ((9 * c) / 5) + 32;
            r = (4 * (k - 273)) / 5;

            // Menuliskan hasil ke consol/terminal
            cout << "++++++++++++++++++++" << endl;
            cout << "Celcius     = " << c << endl;
            cout << "Reamur      = " << r << endl;
            cout << "Fahrenheit  = " << f << endl;
            cout << "++++++++++++++++++++\n" << endl;
            
            // Menuliskan hasil ke file output
            myFile.output << c << setw(10) << r << setw(10)
                            << f << setw(10) << k << endl;

            myFile.closefile();
        }
};

// ============================================== INTI BODY ========================================

int pilihantugas3();
int pilihantugas3_2();
void soalP3_1();
void soalP3_2();
void soalP3_3();

void TugasPertemuan3()
{
	int pilihan = pilihantugas3();
	char is_continue;

	enum option{SOAL3_1 = 1, SOAL3_2, SOAL3_3, FINISH};

	while(pilihan != FINISH){

		switch(pilihan){
			case SOAL3_1:
				cout << "Soal Pertemuan 3 : Nomor 1" << endl;
                soalP3_1();
				break;
			case SOAL3_2:
				cout << "Soal Pertemuan 3 : Nomor 2" << endl;
                soalP3_2();
				break;
			case SOAL3_3:
				cout << "Soal Pertemuan 3 : Nomor 3" << endl;
                soalP3_3();
				break;
			default:
				cout << "Tidak Dikenali" << endl;
				break;
		}

		label_continue:

		cout << "\nLihat Nomor Lain? (y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){
			pilihan = pilihantugas3();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else {
			goto label_continue;
		}
	}

}

int pilihantugas3()
{
    int input;
	system("CLS");
	// system("cls");
	cout << "\nTugas Pertemuan 3" << endl;
	cout << "=============================" << endl;
	cout << "1. Menuliskan Kode ASCII ke dalam file, dan menampilkan output berupa char" << endl;
	cout << "2. Konversi suhu dengan 2 file .txt" << endl;
	cout << "3. Menampilkan 100 byte pertama dari file .docx berupa karakter ASCII " << endl;
	cout << "4. END" << endl;
	cout << "=============================" << endl;
	cout << "Pilih [1-4]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	return input;
}

void soalP3_1()
{
    Alfabet myFile = Alfabet("Kelompok6_A03a.txt");
    myFile.writeFile();
    cout << "Kode ASCII telah dituliskan ke dalam file" << endl;
    cout << "Ditampilkan kembali dalam bentuk char alfabet : " << endl;
    myFile.readFile();
}

void soalP3_2()
{
    Suhu test;
	int pilihan = pilihantugas3_2();
	char is_continue;

	enum option{CELCIUS = 1, REAMUR, FAHRENHEIT, KELVIN, FINISH};

	while(pilihan != FINISH){

		switch(pilihan){
			case CELCIUS:
				cout << "Celcius" << endl;
                test.celcius();
				break;
			case REAMUR:
				cout << "Reamur" << endl;
                test.reamur();
				break;
			case FAHRENHEIT:
				cout << "Fahrenheit" << endl;
                test.fahrenheit();
				break;
			case KELVIN:
				cout << "Kelvin" << endl;
                test.kelvin();
				break;
			default:
				cout << "Tidak Dikenali" << endl;
				break;
		}

		label_continue:

		cout << "Konversi Lagi? (y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){
			pilihan = pilihantugas3_2();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else {
			goto label_continue;
		}
	}
}

void soalP3_3()
{
    // :-(
    cout << "Belum Selesai" << endl;
}

int pilihantugas3_2()
{
    int input;
	system("CLS");
	// system("cls");
	cout << "\nProgram Konversi Suhu" << endl;
	cout << "=============================" << endl;
	cout << "1. Celcius" << endl;
	cout << "2. Reamur" << endl;
	cout << "3. Fahrenheit" << endl;
	cout << "4. Kelvin" << endl;
	cout << "5. END" << endl;
	cout << "=============================" << endl;
	cout << "Pilih Suhu Awal [1-5]? : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	return input;
}