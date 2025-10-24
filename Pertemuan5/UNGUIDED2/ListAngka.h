#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

// Fungsi dasar dari Soal 1
void createList(linkedList &L);
address alokasi(dataAngka x);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
void printList(linkedList L);

// Update
void updateFirst(linkedList &L, int newVal);
void updateLast(linkedList &L, int newVal);
void updateAfter(linkedList &L, address prec, int newVal);

// Search
void searchByData(linkedList L, int data);
void searchByAddress(linkedList L, address p);
void searchByRange(linkedList L, int nilaiMin);

#endif
