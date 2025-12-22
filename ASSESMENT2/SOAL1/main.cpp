#include "bst.h"

int main() {
    adr root = NULL;

    cout << "===== INPUT DATA BST =====" << endl;
    insertNode(root,50,"Monitor LED",10);
    insertNode(root,30,"Keyboard RGB",20);
    insertNode(root,70,"Mouse Gaming",15);
    insertNode(root,20,"Kabel HDMI",50);
    insertNode(root,40,"Headset 7.1",12);
    insertNode(root,60,"Webcam HD",8);
    insertNode(root,80,"Speaket BT",5);

    cout << endl << "===== INORDER TRAVERSAL =====" << endl;
    inOrder(root);

    cout << endl << "===== PREORDER TRAVERSAL =====" << endl;
    preOrder(root);

    cout << endl << "===== POSTORDER TRAVERSAL =====" << endl;
    postOrder(root);

    cout << endl << "===== SEARCH BY ID =====" << endl;
    adr p = searchById(root,40);
    if (p != NULL)
        cout << "Data ditemukan: " << p->namaProduk << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    p = searchById(root,99);
    if (p != NULL)
        cout << "Data ditemukan: " << p->namaProduk << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    cout << endl << "===== SEARCH BY PRODUCT =====" << endl;
    p = searchByProduct(root,"Webcam HD");
    if (p != NULL)
        cout << "Data ditemukan: ID " << p->idProduk << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    p = searchByProduct(root,"Printer");
    if (p != NULL)
        cout << "Data ditemukan: ID " << p->idProduk << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    cout << endl << "===== FIND MIN & MAX =====" << endl;
    adr mn = findMin(root);
    adr mx = findMax(root);
    if (mn != NULL) cout << "ID Produk Terkecil : " << mn->idProduk << endl;
    if (mx != NULL) cout << "ID Produk Terbesar : " << mx->idProduk << endl;

    cout << endl << "===== DELETE NODE 20 =====" << endl;
    root = deleteNode(root,20);
    inOrder(root);

    cout << endl << "===== DELETE NODE 30 =====" << endl;
    root = deleteNode(root,30);
    inOrder(root);

    cout << endl << "===== DELETE NODE 50 =====" << endl;
    root = deleteNode(root,50);
    inOrder(root);

    cout << endl << "===== DELETE TREE =====" << endl;
    deleteTree(root);
    inOrder(root);
}
