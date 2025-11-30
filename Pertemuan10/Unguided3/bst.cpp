#include "bst.h"
#include <cstdlib>

using namespace std;

// Fungsi dasar (Dari Soal 1)
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
}

void printInorder(address root) {
    if (root != NULL) {
        printInorder(root->left);
        cout << root->info << "-";
        printInorder(root->right);
    }
}

// Fungsi tambahan (Untuk Soal 3)
void printPreorder(address root) {
    if (root != NULL) {
        cout << root->info << "-";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << "-";
    }
}