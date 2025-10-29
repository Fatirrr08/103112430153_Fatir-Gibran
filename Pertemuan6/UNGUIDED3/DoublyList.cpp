#include "Doublylist.h"
using namespace std;

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

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

address findElm(List L, string nopol) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.nopol == nopol)
            return P;
        P = P->next;
    }
    return NULL;
}

void printInfo(List L) {
    cout << "\nDATA LIST 3\n";
    if (L.first == NULL) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.first;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
        P = P->next;
        if (P != NULL) cout << endl;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first == NULL) return;
    P = L.first;

    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = L.first->next;
        L.first->prev = NULL;
    }
    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) return;
    P = L.last;

    if (L.first == L.last) {
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = L.last->prev;
        L.last->next = NULL;
    }
    P->prev = NULL;
}

void deleteAfter(address Prec, address &P) {
    if (Prec == NULL || Prec->next == NULL) return;

    P = Prec->next;
    Prec->next = P->next;
    if (P->next != NULL)
        P->next->prev = Prec;
    P->next = NULL;
    P->prev = NULL;
}
