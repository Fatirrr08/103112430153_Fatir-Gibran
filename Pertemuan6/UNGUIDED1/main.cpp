#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    createList(L);

    int n;
    cout << "Masukkan jumlah data kendaraan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        kendaraan k;
        cout << "\nMasukkan nomor polisi: ";
        getline(cin, k.nopol);

        // Cek duplikasi nopol
        if (findElm(L, k.nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar\n";
            continue; // skip input berikutnya
        }

        cout << "Masukkan warna kendaraan: ";
        getline(cin, k.warna);
        cout << "Masukkan tahun kendaraan: ";
        cin >> k.thnBuat;
        cin.ignore();

        insertFirst(L, alokasi(k));
    }

    printInfo(L);
}
