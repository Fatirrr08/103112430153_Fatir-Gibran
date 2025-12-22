#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string nama;
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
void inorder(adr root);
void preorder(adr root);
void postorder(adr root);
void deleteTree(adr &root);

#endif
