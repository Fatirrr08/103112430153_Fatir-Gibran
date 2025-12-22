#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;

struct ElmChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    ElmChild *next;
    ElmChild *prev;
};

struct ElmParent {
    string IDGenre;
    string namaGenre;
    ElmParent *next;
    ElmParent *prev;
    ElmChild *firstChild;
    ElmChild *lastChild;
};

struct ListChild {
    ElmChild *first;
    ElmChild *last;
};

struct ListParent {
    ElmParent *first;
    ElmParent *last;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);

ElmParent* alokasiNodeParent(string id, string nama);
ElmChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);

void dealokasiNodeParent(ElmParent* &P);
void dealokasiNodeChild(ElmChild* &C);

void insertFirstParent(ListParent &LP, ElmParent *P);
void insertLastChild(ElmParent *P, ElmChild *C);

void deleteAfterParent(ListParent &LP, ElmParent *prev);
void hapusListChild(ElmParent *P);

void searchFilmByRatingRange(ListParent LP, float min, float max);
void printStrukturMLL(ListParent LP);

#endif
