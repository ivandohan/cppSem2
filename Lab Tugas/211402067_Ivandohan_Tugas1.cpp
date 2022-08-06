#include <iostream>
#include <string>
#define N 100

namespace ipan {
    void cout(std::string a){
        std::cout << "Getline String    : " << a << std::endl;
    }
}

int main()
{
    int n;
    char arr[N];
    std::string pan;

    std::cout << "Input kalimat 1   : ";
    std::cin.getline(arr, N);
    int a = std::cin.gcount() - 1;
    std::cout << "Jumlah Char       : " << a << std::endl;

    std::cout << "Getline char      : ";
    for(int i = 0; i < a; i++){
        std::cout << arr[i];
    }

    std::cout << "\n\nInput Kalimat 2   : ";
    std::getline(std::cin, pan);
    ipan::cout(pan);

    return 0;
}