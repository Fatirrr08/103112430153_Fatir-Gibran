#include "bst.h"
#include <iostream>

using namespace std;

int main() {
    address root = NULL;

    cout << "=== Soal 3: Traversal Pre-Order & Post-Order ===" << endl;
    cout << "Memasukkan node: 6, 4, 7, 2, 5, 3" << endl;
    
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 3);

    cout << "\n--- Hasil Traversal ---" << endl;
    
    cout << "InOrder: ";
    printInorder(root); 
    cout << endl;
    
    cout << "PreOrder: ";
    printPreorder(root); 
    cout << endl;
    
    cout << "PostOrder: ";
    printPostorder(root); 
    cout << endl;

    return 0;
}