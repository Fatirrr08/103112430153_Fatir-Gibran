#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};

string terbilang(int n) {
    if (n == 0) return "nol";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa > 0) hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int angka;
    cout << "Program Konversi Angka ke Terbilang (0-100)" << endl;
    cout << " " << endl;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << "Angka " << "'" << angka << "'" << " Dibaca Dengan " << "'"<< terbilang(angka) << "'" <<" Dalam Penyebutan Nya "<< endl;
    }

    return 0;
}
