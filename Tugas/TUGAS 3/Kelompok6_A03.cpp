/*
    ===== Tugas Kelompok 6 =====
    Anggota :
        1. Ivandohan Samuel Siregar (211402067)
        2. Adelweys Margaretha Sijabat (211402103)
        3. Aurelia Priscilia Simamora (211402091)
        4. Amanda Bendicta Sembiring (211402082)

    Note : 
        File header cpp berisi tugas-tugas dari pertemuan 1.

		======= Ada Limit File Di Elearning, sehingga tidak dapat menampung semua file yang dibutuhkan,
		sehingga akan terjadi error pada source code =========
*/


//Standard Library
#include <iostream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>

//Library Tugas 1 s.d 3
#include "Kelompok6_A03a.hpp"
#include "Kelompok6_A03b.hpp"
#include "Kelompok6_A03c.hpp"

using namespace std;

int getOption();

int main()
{
	int pilihan = getOption();
	char is_continue;

	enum option{PERTMN1 = 1, PERTMN2, PERTMN3, FINISH};

	while(pilihan != FINISH){

		switch(pilihan){
			case PERTMN1:
				cout << "+++ Pertemuan 1 +++" << endl;
                TugasPertemuan1();
				break;
			case PERTMN2:
				cout << "+++ Pertemuan 2 +++" << endl;
                TugasPertemuan2();
				break;
			case PERTMN3:
				cout << "+++ Pertemuan 3 +++" << endl;
                TugasPertemuan3();
				break;
			default:
				break;
		}

		label_continue:

		cout << "Cek Tugas Lainnya? (y/n) : ";
		cin >> is_continue;
		if ( (is_continue == 'y') | (is_continue == 'Y')){
			pilihan = getOption();
		} else if ((is_continue == 'n') | (is_continue == 'N')){
			break;
		} else {
			goto label_continue;
		}
	}

	cout << "=== E N D ===" << endl;


    return 0;
}

int getOption()
{
    int input;
	system("CLS");
	// system("cls");
	cout << "\nProgram Tugas Pertemuan 1 s.d 3" << endl;
	cout << "=============================" << endl;
	cout << "1. Tugas Pertemuan 1" << endl;
	cout << "2. Tugas Pertemuan 2" << endl;
	cout << "3. Tugas Pertemuan 3" << endl;
	cout << "4. END" << endl;
	cout << "=============================" << endl;
	cout << "Pilih Tugas yang Akan Dilihat [1-4] : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return input;
}