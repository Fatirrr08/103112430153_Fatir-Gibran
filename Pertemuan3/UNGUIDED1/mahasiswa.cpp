#include <iostream>
#include "mahasiswa.h"
using namespace std;

// Implementasi fungsi hitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(Mahasiswa mhs[], int n) {
    cout << "\n============================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "============================================\n";
    cout << "No\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t"
             << mhs[i].nim << "\t"
             << mhs[i].nama << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }
}
