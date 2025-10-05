#include <iostream>
using namespace std;

void TukarTigaPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "--- Sebelum ditukar (Pointer) ---" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai b: " << b << endl;
    cout << "Nilai c: " << c << endl;

    TukarTigaPointer(&a, &b, &c);

    cout << "\n--- Setelah ditukar (Pointer) ---" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai b: " << b << endl;
    cout << "Nilai c: " << c << endl;

    return 0;
}