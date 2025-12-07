#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

// --- Definisi Pointer dan Node ---
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

// Node Child (Anak)
struct nodeChild {
    dataHewan info;
    adrChild next;
    adrChild prev;
};

// List Child
struct listChild {
    adrChild first;
    adrChild last;
};

// Node Parent (Induk)
struct nodeParent {
    golonganHewan info;
    adrParent next;
    adrParent prev;
    listChild L_Child;
};

// List Parent
struct listParent {
    adrParent first;
    adrParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);

// --- Fungsi Khusus Soal 3 (Delete & Print) ---
void deleteParent(listParent &L, string idGol); // Menghapus Parent beserta anaknya
void printMLLStructure(listParent L);           // Menampilkan output sesuai format

#endif