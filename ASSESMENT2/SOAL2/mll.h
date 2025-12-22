#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;

struct Film {
    string id;
    string judul;
    int durasi;
    int tahun;
    float rating;
    Film *next;
    Film *prev;
};

struct Genre {
    string id;
    string nama;
    Genre *next;
    Genre *prev;
    Film *firstChild;
    Film *lastChild;
};

struct ListParent {
    Genre *first;
    Genre *last;
};

void createListParent(ListParent &L);
Genre* alokasiParent(string id, string nama);
Film* alokasiChild(string id, string judul, int durasi, int tahun, float rating);
void insertLastParent(ListParent &L, Genre *P);
void insertLastChild(Genre *P, Film *C);
void hapusListChild(Genre *P);
void deleteAfterParent(ListParent &L, Genre *prev);
void printStrukturMLL(ListParent L);
void searchFilmByRatingRange(ListParent L, float min, float max);

#endif
