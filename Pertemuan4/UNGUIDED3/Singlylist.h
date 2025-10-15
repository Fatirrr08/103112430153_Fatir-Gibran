#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void insertAfter(Node* Prec, Node* P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node* Prec);
void printInfo(List L);
int nbList(List L);
void deleteList(List &L);

#endif
