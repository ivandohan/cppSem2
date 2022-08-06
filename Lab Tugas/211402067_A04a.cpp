#include <iostream>

using namespace std;

class UlangKarakter {
public :
    UlangKarakter (char ch = '*', int jlh = 45){
        for(int j = 0; j < jlh; j++){
            cout << ch;
        }
        cout << endl;
    }

    // void ulangChar (char ch = '*', int jlh = 45){
    //     for(int j = 0; j < jlh; j++){
    //         cout << ch;
    //     }
    //     cout << endl;
    // }
};

int main()
{
    UlangKarakter OOP = UlangKarakter();

    return 0;
}