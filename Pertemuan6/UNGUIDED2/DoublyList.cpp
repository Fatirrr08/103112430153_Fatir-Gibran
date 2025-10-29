#include "Doublylist.h"
using namespace std;

// Membuat list kosong
void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Menyisipkan di awal (insertFirst)
void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

// Mencari elemen berdasarkan nomor polisi
address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return NULL;
}

// Menampilkan seluruh data kendaraan
void printInfo(List L) {
    cout << "\nDATA LIST 2\n";
    if (L.first == NULL) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.first;
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->next;
        if (P != NULL) cout << endl;
    }
}
