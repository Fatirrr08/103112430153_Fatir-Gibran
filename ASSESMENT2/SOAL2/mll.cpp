#include "mll.h"

void createListParent(ListParent &LP) {
    LP.first = LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = LC.last = NULL;
}

ElmParent* alokasiNodeParent(string id, string nama) {
    ElmParent *P = new ElmParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = P->prev = NULL;
    P->firstChild = P->lastChild = NULL;
    return P;
}

ElmChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    ElmChild *C = new ElmChild;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = C->prev = NULL;
    return C;
}

void dealokasiNodeParent(ElmParent* &P) {
    delete P;
    P = NULL;
}

void dealokasiNodeChild(ElmChild* &C) {
    delete C;
    C = NULL;
}

void insertFirstParent(ListParent &LP, ElmParent *P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(ElmParent *P, ElmChild *C) {
    if (P->firstChild == NULL) {
        P->firstChild = P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void hapusListChild(ElmParent *P) {
    ElmChild *C = P->firstChild;
    while (C != NULL) {
        ElmChild *temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    P->firstChild = P->lastChild = NULL;
}

void deleteAfterParent(ListParent &LP, ElmParent *prev) {
    ElmParent *P = prev->next;
    if (P != NULL) {
        prev->next = P->next;
        if (P->next != NULL) P->next->prev = prev;
        else LP.last = prev;
        hapusListChild(P);
        dealokasiNodeParent(P);
    }
}

void searchFilmByRatingRange(ListParent LP, float min, float max) {
    ElmParent *P = LP.first;
    int posParent = 1;
    while (P != NULL) {
        ElmChild *C = P->firstChild;
        int posChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre << " pada posisi ke-" << posChild << "!" << endl << endl;
                cout << "Data Film (Child)" << endl;
                cout << "Judul Film " << C->judulFilm << endl;
                cout << "Posisi dalam list child posisi ke-" << posChild << endl;
                cout << "ID Film: " << C->IDFilm << endl;
                cout << "Durasi Film: " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl << endl;
                cout << "Data Genre (Parent)" << endl;
                cout << "ID Genre : " << P->IDGenre << endl;
                cout << "Posisi dalam list parent posisi ke-" << posParent << endl;
                cout << "Nama Genre: " << P->namaGenre << endl << endl;
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}

void printStrukturMLL(ListParent LP) {
    ElmParent *P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre: " << P->IDGenre << endl;
        cout << "Nama Genre: " << P->namaGenre << endl;
        ElmChild *C = P->firstChild;
        int j = 1;
        if (C == NULL) cout << "-" << endl;
        while (C != NULL) {
            cout << endl;
            cout << "Child " << j << ":" << endl;
            cout << "ID Film: " << C->IDFilm << endl;
            cout << "Judul Film: " << C->judulFilm << endl;
            cout << "Durasi Film: " << C->durasiFilm << " menit" << endl;
            cout << "Tahun Tayang : " << C->tahunTayang << endl;
            cout << "Rating Film : " << C->ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << endl;
        P = P->next;
        i++;
    }
}
