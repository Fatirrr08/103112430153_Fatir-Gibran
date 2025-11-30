#include "bst.h"
#include <iostream>

using namespace std;

int main() {
    address root = NULL;

    cout << "=== Soal 1: Insert dan InOrder ===" << endl;
    cout << "Memasukkan node: 1, 2, 6, 5, 3, 7" << endl;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    
    cout << "Hasil InOrder: ";
    printInorder(root);
    cout << "=" << endl; // Output InOrder terurut (1-2-3-5-6-7= jika 6,5,3,7 di-insert sesuai kriteria BST)

    infotype cari = 5;
    address found = findNode(cari, root);
    if (found != NULL) {
        cout << "Node " << cari << " ditemukan." << endl;
    } else {
        cout << "Node " << cari << " TIDAK ditemukan." << endl;
    }

    return 0;
}