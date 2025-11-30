#include "bst.h"
#include <iostream>

using namespace std;

int main() {
    address root = NULL;

    cout << "=== Soal 2: Fungsi Penghitungan BST ===" << endl;
    cout << "Memasukkan node: 1, 2, 6, 4, 5, 3, 7" << endl;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    
    cout << "InOrder (Verifikasi): ";
    printInorder(root);
    cout << "=" << endl;
    cout << "\n";

    cout << "kedalaman: " << hitungKedalaman(root) << endl;
    cout << "jumlah Node: " << hitungJumlahNode(root) << endl;
    cout << "total: " << hitungTotalInfo(root) << endl;
    
    return 0;
}