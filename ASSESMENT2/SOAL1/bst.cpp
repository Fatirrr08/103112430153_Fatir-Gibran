#include "bst.h"

void insertNode(adr &root, int id, string nama, int stok) {
    if (root == NULL) {
        root = new Node{id,nama,stok,NULL,NULL};
    } else if (id < root->idProduk) {
        insertNode(root->left,id,nama,stok);
    } else {
        insertNode(root->right,id,nama,stok);
    }
}

adr searchById(adr root, int id) {
    if (root == NULL) return NULL;
    if (root->idProduk == id) return root;
    if (id < root->idProduk) return searchById(root->left,id);
    return searchById(root->right,id);
}

adr searchByProduct(adr root, string nama) {
    if (root == NULL) return NULL;
    if (root->namaProduk == nama) return root;
    adr L = searchByProduct(root->left,nama);
    if (L != NULL) return L;
    return searchByProduct(root->right,nama);
}

adr findMin(adr root) {
    if (root == NULL) return NULL;
    while (root->left != NULL) root = root->left;
    return root;
}

adr findMax(adr root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) root = root->right;
    return root;
}

adr deleteNode(adr root, int id) {
    if (root == NULL) return root;
    if (id < root->idProduk) root->left = deleteNode(root->left,id);
    else if (id > root->idProduk) root->right = deleteNode(root->right,id);
    else {
        if (root->left == NULL) {
            adr t = root->right;
            delete root;
            return t;
        }
        if (root->right == NULL) {
            adr t = root->left;
            delete root;
            return t;
        }
        adr t = findMin(root->right);
        root->idProduk = t->idProduk;
        root->namaProduk = t->namaProduk;
        root->stok = t->stok;
        root->right = deleteNode(root->right,t->idProduk);
    }
    return root;
}

void inOrder(adr root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << "ID Produk   : " << root->idProduk << endl;
        cout << "Nama Produk : " << root->namaProduk << endl;
        cout << "Stok        : " << root->stok << endl;
        cout << "-----------------------------" << endl;
        inOrder(root->right);
    }
}

void preOrder(adr root) {
    if (root != NULL) {
        cout << "ID Produk   : " << root->idProduk << endl;
        cout << "Nama Produk : " << root->namaProduk << endl;
        cout << "Stok        : " << root->stok << endl;
        cout << "-----------------------------" << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(adr root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "ID Produk   : " << root->idProduk << endl;
        cout << "Nama Produk : " << root->namaProduk << endl;
        cout << "Stok        : " << root->stok << endl;
        cout << "-----------------------------" << endl;
    }
}

void deleteTree(adr &root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
