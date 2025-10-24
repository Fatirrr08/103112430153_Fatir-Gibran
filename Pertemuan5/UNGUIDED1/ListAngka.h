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

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif
