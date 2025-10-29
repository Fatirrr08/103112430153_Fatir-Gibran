#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukkan jumlah data kendaraan: ";
    cin >> n;
    cin.ignore();

    // Input data kendaraan
    for (int i = 0; i < n; i++) {
        kendaraan k;
        cout << "\nMasukkan nomor polisi: ";
        getline(cin, k.nopol);

        // Cek duplikasi nopol
        if (findElm(L, k.nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, k.warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> k.thnBuat;
        cin.ignore();

        insertFirst(L, alokasi(k));
    }

    // Tampilkan semua data
    printInfo(L);

    // Pencarian data berdasarkan nopol
    cout << "\nMasukkan nomor polisi yang ingin dicari: ";
    string cari;
    getline(cin, cari);

    address hasil = findElm(L, cari);
    cout << "\nHASIL PENCARIAN\n";
    if (hasil != NULL) {
        cout << "no polisi : " << hasil->info.nopol << endl;
        cout << "warna     : " << hasil->info.warna << endl;
        cout << "tahun     : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan.\n";
    }
}
