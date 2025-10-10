#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

// Struct Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Deklarasi fungsi
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanData(Mahasiswa mhs[], int n);

#endif
