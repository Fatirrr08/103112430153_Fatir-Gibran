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

// Fungsi untuk Soal 3
void printPreorder(address root);
void printPostorder(address root);

#endif