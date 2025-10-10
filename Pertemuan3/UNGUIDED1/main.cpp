#include <iostream>
#include <string>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah mahasiswa melebihi batas maksimum (10)!" << endl;
        return 0;
    }

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        getline(cin, mhs[i].nim);
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Tampilkan data
    tampilkanData(mhs, n);

    return 0;
}
