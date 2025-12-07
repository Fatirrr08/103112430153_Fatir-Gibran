#include "mll.h"

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent;
    P->info.idGolongan = idGol;
    P->info.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild;
    P->info.idHewan = idHwn;
    P->info.namaHewan = namaHwn;
    P->info.habitat = habitat;
    P->info.ekor = tail;
    P->info.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printMLLStructure(listParent L) {
    adrParent P = L.first;
    int i = 1;
    cout << "=== Output Soal 1 ===" << endl;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;
        
        adrChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int j = 1;
            while (C != NULL) {
                cout << "- Child " << j << ":" << endl;
                cout << "  ID Hewan    : " << C->info.idHewan << endl;
                cout << "  Nama Hewan  : " << C->info.namaHewan << endl;
                cout << "  Habitat     : " << C->info.habitat << endl;
                cout << "  Ekor        : " << C->info.ekor << endl;
                cout << "  Bobot       : " << C->info.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}