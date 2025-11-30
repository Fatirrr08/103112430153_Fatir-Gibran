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

// Fungsi tambahan (Untuk Soal 2)
int max(int a, int b) {
    return (a > b) ? a : b;
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo (address root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(hitungKedalaman(root->left), hitungKedalaman(root->right));
}