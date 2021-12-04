#include <iostream>
#include "Array.h"
using namespace std;

/* NAO MEXA DAQUI PRA BAIXO */
int main() {
    Array arr1 {8};
    Array arr2 {8};
    Array arr3 {5};

    for(int i = 0; i < 8; ++i) {
        arr1[i] = 2 * i;
        arr2[i] = 2 * i;
    }

    for(int i = 0; i < 5; ++i) {
        arr3[i] = 3 * i;
    }

    cout << "arr1: " << arr1 << endl;
    cout << "arr2: " << arr2 << endl;
    cout << "arr3: " << arr3 << endl;

    if(arr1 == arr2) {
        cout << "arr1 == arr2" << endl;
    }
    if(arr1 != arr3) {
        cout << "arr1 != arr3" << endl;
    }

    Array arr4 {arr3};
    cout << "arr 4 é uma cópia de arr3: " << arr4 << endl;

    arr4 = arr4;
    cout << "arr4: " << arr4 << endl;

    return 0;
}