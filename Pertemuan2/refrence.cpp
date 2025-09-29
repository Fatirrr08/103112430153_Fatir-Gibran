#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int& ref = a;

    cout << "Nilai of a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref (Alias to a): " << ref << endl;
    cout << "Alamat ref (&raf): " << &ref << endl;

    ref = 30;
    cout << "\nSetelah ref = 50: " << a << endl;
    cout << "Nilai a: " << &a << endl;
    cout << "Nilai ref: " << ref << endl;

    Tukar(&a, &b);
    cout << "Setelah Tukar, Nilai a= " << a << " dan b=" << b << endl;
    return 0;
}

