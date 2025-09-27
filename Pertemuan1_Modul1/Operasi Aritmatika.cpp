#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Program Operasi Aritmatika " << endl;
    cout << " " << endl;
    
    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;

    cout << "Hasil Penjumlahan Dari "<< a << " dan " << b << b << " : " << a + b << endl;
    cout << "Hasil Pengurangan Dari "<< a << " dan " << b << " : " << a + b << endl;
    cout << "Hasil Perkalian Dari "<< a << " dan " << b << " : " << a + b << endl;
    
    if (b != 0)
    cout << "Hasil Pembagian Dari "<< a << " dan " << b << " : " << a / b << endl;
    else if (b == 0) {
        cout << "Hasil Pembagian Dari "<< a << " dan " << b << " : " << b << endl;
        cout << "Setiap Angka yang di bagi dengan 0 akan menjadi 0 " << endl;
    }
        return 0;
}
