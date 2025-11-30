#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

typedef address BinTree;

address alokasi (infotype x);
void insertNode(address& root, infotype x);
void printInorder(address root);

// Fungsi untuk Soal 2
int hitungJumlahNode(address root);
int hitungTotalInfo (address root);
int hitungKedalaman(address root);
int max(int a, int b);

#endif