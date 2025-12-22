#include "mll.h"

void createListParent(ListParent &L) {
    L.first = L.last = NULL;
}

Genre* alokasiParent(string id, string nama) {
    Genre *P = new Genre{id,nama,NULL,NULL,NULL,NULL};
    return P;
}

Film* alokasiChild(string id, string judul, int durasi, int tahun, float rating) {
    Film *C = new Film{id,judul,durasi,tahun,rating,NULL,NULL};
    return C;
}

void insertLastParent(ListParent &L, Genre *P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertLastChild(Genre *P, Film *C) {
    if (P->firstChild == NULL) {
        P->firstChild = P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void hapusListChild(Genre *P) {
    Film *C = P->firstChild;
    while (C != NULL) {
        Film *t = C;
        C = C->next;
        delete t;
    }
    P->firstChild = P->lastChild = NULL;
}

void deleteAfterParent(ListParent &L, Genre *prev) {
    Genre *P = prev->next;
    if (P != NULL) {
        prev->next = P->next;
        if (P->next != NULL) P->next->prev = prev;
        else L.last = prev;
        hapusListChild(P);
        delete P;
    }
}

void printStrukturMLL(ListParent L) {
    Genre *P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << "===== PARENT " << i << " =====" << endl;
        cout << "ID Genre   : " << P->id << endl;
        cout << "Nama Genre : " << P->nama << endl;
        Film *C = P->firstChild;
        int j = 1;
        if (C == NULL) cout << "-" << endl;
        while (C != NULL) {
            cout << "  Child " << j << endl;
            cout << "  ID Film      : " << C->id << endl;
            cout << "  Judul Film   : " << C->judul << endl;
            cout << "  Durasi Film  : " << C->durasi << " menit" << endl;
            cout << "  Tahun Tayang : " << C->tahun << endl;
            cout << "  Rating Film  : " << C->rating << endl;
            C = C->next;
            j++;
        }
        cout << "-----------------------------" << endl;
        P = P->next;
        i++;
    }
}

void searchFilmByRatingRange(ListParent L, float min, float max) {
    Genre *P = L.first;
    while (P != NULL) {
        Film *C = P->firstChild;
        while (C != NULL) {
            if (C->rating >= min && C->rating <= max) {
                cout << "Judul Film : " << C->judul << endl;
                cout << "Genre      : " << P->nama << endl;
                cout << "Rating     : " << C->rating << endl;
                cout << "-----------------------------" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}
