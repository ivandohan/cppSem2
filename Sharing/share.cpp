#include <iostream>
#include <vector>
#include <cstdlib>
#define N 10

using namespace std;

class MiniProject {
public:
    int opsi;
    vector<int> vect;
    
    void genBilAcak(){
        srand(time(0));
        for(int i = 0; i < N; i++){
            int rd = rand() % 20;
            vect.push_back(rd);
        }
    }

    void cekSum(int userSum){
        cout << "\n\n===== Result =====" << endl;
        for(int i = 0; i < vect.size(); i++)
            for(int j = 0; j < vect.size(); j++)
                if((vect[i] + vect[j]) == userSum)
                    cout << "( " << i << ", " << j << " ) = "
                        << "( " << vect[i] << ", " << vect[j] << " )" << endl;
    }

    void displayVector(){
        genBilAcak();
        cout << "\n\n===== Random Number =====" << endl;
        cout << "{ ";
        for(int i = 0; i < N; i++){
            cout << vect[i] << ", ";
        }
        cout << " }" << endl;
    }
};

int main(){
    MiniProject asd;
    int opsi;

    system("CLS");
    cout << "=== Mini Project 3 : Find awokwok ===" << endl;

    cout << "Berikan sebuah bilangan : "; cin >> opsi;
    asd.displayVector();

    cout << "\n\nBilangan berjumlah " << opsi << " ada di posisi : " << endl;
    asd.cekSum(opsi);

    return 0;
}
