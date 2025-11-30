#include "bst.h"
#include <cstdlib>

using namespace std;

// Implementasi alokasi
address alokasi (infotype x) {
    address temp = new Node;
    if (temp != NULL) {
        temp->info = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    return NULL;
}

void insertNode(address& root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
        return;
    }
    if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
    // Abaikan jika nilai sama
}

address findNode(infotype x, address root) {
    if (root == NULL || root->info == x) {
        return root;
    }
    if (x < root->info) { 
        return findNode(x, root->left);
    }
    else {
        return findNode(x, root->right);
    }
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << "-";
        printInorder(root->right);
    }
}