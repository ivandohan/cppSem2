//Contoh4_1.cpp
#include <fstream>
#include <string>

using namespace std;

class OutFile
{
    private:
        ofstream ofile;
        string filename;
    public:
        OutFile(string fname) {
            filename = fname;
            }
        void openFile() {ofile.open(filename);}
        void writeFile();
        void closeFile() {ofile.close();}
        ~OutFile(){}
};

void OutFile::writeFile()
{
    ofile << "Nama: Afry Lianfauzan Siregar" <<
    endl;
    ofile << "NIM : 201402001" << endl;
    ofile << "Semester : 2" << endl;
    ofile << "Prog. Studi: Teknologi Informasi"
    << endl;
    ofile << "Fasilkom-TI USU Medan" << endl;
}

int main()
{
    OutFile myFile("Contoh4_1.txt");

    myFile.openFile();
    myFile.writeFile();
    myFile.closeFile();

    return 0;
}