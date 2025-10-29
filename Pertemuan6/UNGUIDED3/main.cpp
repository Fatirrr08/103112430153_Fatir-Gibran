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
        cout << "\nMasukkan Nomor Polisi: ";
        getline(cin, k.nopol);

        // Cek duplikasi
        if (findElm(L, k.nopol) != NULL) {
            cout << "Nomor polisi sudah terdaftar\n";
            continue;
        }

        cout << "Masukkan Warna Kendaraan: ";
        getline(cin, k.warna);
        cout << "Masukkan Tahun Kendaraan: ";
        cin >> k.thnBuat;
        cin.ignore();

        insertFirst(L, alokasi(k));
    }

    // Cetak data sebelum penghapusan
    cout << "\nDATA SEBELUM PENGHAPUSAN:";
    printInfo(L);

    // Input nopol yang akan dihapus
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string hapus;
    getline(cin, hapus);

    address target = findElm(L, hapus);
    address P = NULL;

    if (target == NULL) {
        cout << "\nData tidak ditemukan.\n";
    } else if (target == L.first) {
        deleteFirst(L, P);
        cout << "\nData pertama berhasil dihapus: " << P->info.nopol << endl;
        dealokasi(P);
    } else if (target == L.last) {
        deleteLast(L, P);
        cout << "\nData terakhir berhasil dihapus: " << P->info.nopol << endl;
        dealokasi(P);
    } else {
        address prec = target->prev;
        deleteAfter(prec, P);
        cout << "\nData di tengah berhasil dihapus: " << P->info.nopol << endl;
        dealokasi(P);
    }

    // Cetak data sesudah penghapusan
    cout << "\nDATA SETELAH PENGHAPUSAN:";
    printInfo(L);
}
