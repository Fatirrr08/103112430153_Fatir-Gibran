/* File: mll.cpp */
#include "mll.h"

// --- Create List ---
void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

// --- Alokasi Node ---
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

// --- Insert Last ---
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

// --- DELETE PARENT & CHILD (Inti Soal 3) ---
void deleteListChild(listChild &L) {
    adrChild P = L.first;
    while (P != NULL) {
        adrChild temp = P;
        P = P->next;
        delete temp; // Hapus node anak dari memori
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteParent(listParent &L, string idGol) {
    adrParent P = L.first;
    // Mencari parent berdasarkan ID
    while (P != NULL && P->info.idGolongan != idGol) {
        P = P->next;
    }

    if (P != NULL) {
        // 1. Hapus semua anak dari parent ini terlebih dahulu
        deleteListChild(P->L_Child);

        // 2. Hapus node Parent dari list
        if (P == L.first && P == L.last) { // Satu-satunya elemen
            L.first = NULL;
            L.last = NULL;
        } else if (P == L.first) { // Elemen pertama
            L.first = P->next;
            L.first->prev = NULL;
        } else if (P == L.last) { // Elemen terakhir
            L.last = P->prev;
            L.last->next = NULL;
        } else { // Di tengah
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        delete P; // Dealokasi memori parent
    }
}

// --- Print Sesuai Output Soal ---
void printMLLStructure(listParent L) {
    adrParent P = L.first;
    int i = 1;

    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;

        if (P->L_Child.first == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            adrChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "- Child " << j << ":" << endl;
                cout << "  ID Hewan : " << C->info.idHewan << endl;
                cout << "  Nama Hewan : " << C->info.namaHewan << endl;
                cout << "  Habitat : " << C->info.habitat << endl;
                cout << "  Ekor : " << C->info.ekor << endl;
                cout << "  Bobot : " << C->info.bobot << endl;
                C = C->next;
                j++;
            }
        }
        // Jarak antar parent jika perlu, di soal outputnya rapat tapi parent baru di baris baru
        // Kita beri enteryang wajar
        if (P->next != NULL) cout << endl; 
        
        P = P->next;
        i++;
    }
    cout << endl;
}