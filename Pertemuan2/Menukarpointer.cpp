#include <iostream>

using namespace std;

void tukarTigaPointer(int *x, int *y, int *z) {
    int temp = *x; 
    *x = *y;       
    *y = *z;       
    *z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "--- Nilai Awal (Call by Pointer) ---" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarTigaPointer(&a, &b, &c);

    cout << "\n--- Nilai Setelah Ditukar ---" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}