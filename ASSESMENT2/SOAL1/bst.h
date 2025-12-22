#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idProduk;
    string namaProduk;
    int stok;
    Node *left;
    Node *right;
};

typedef Node* adr;

void insertNode(adr &root, int id, string nama, int stok);
adr searchById(adr root, int id);
adr searchByProduct(adr root, string nama);
adr findMin(adr root);
adr findMax(adr root);
adr deleteNode(adr root, int id);
void inOrder(adr root);
void preOrder(adr root);
void postOrder(adr root);
void deleteTree(adr &root);

#endif
