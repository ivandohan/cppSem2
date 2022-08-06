#include<iostream>
using namespace std;

void swapping(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void printArray(int *array, int size) {
    for(int i = 0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void selectionSort(int *array, int size) {
    int i, j, imin;
    for(i = 0; i<size-1; i++) {
        imin = i;
        for(j = i+1; j<size; j++)
            if(array[j] < array[imin])
                imin = j;
        swap(array[i], array[imin]);
    }
}

int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Sebelum disortir :\n";
    printArray(data, size);

    selectionSort(data, size);
    
    cout << "Setelah disortir :\n";
    printArray(data, size);
}