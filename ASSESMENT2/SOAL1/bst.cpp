#include "bst.h"

void insertNode(adr &root, int id, string nama, int stok) {
    if (root == NULL) {
        root = new Node{id,nama,stok,NULL,NULL};
    } else if (id < root->id) {
        insertNode(root->left,id,nama,stok);
    } else {
        insertNode(root->right,id,nama,stok);
    }
}

adr searchById(adr root, int id) {
    if (root == NULL || root->id == id) return root;
    if (id < root->id) return searchById(root->left,id);
    return searchById(root->right,id);
}

adr searchByProduct(adr root, string nama) {
    if (root == NULL) return NULL;
    if (root->nama == nama) return root;
    adr L = searchByProduct(root->left,nama);
    if (L != NULL) return L;
    return searchByProduct(root->right,nama);
}

adr findMin(adr root) {
    while (root->left != NULL) root = root->left;
    return root;
}

adr findMax(adr root) {
    while (root->right != NULL) root = root->right;
    return root;
}

adr deleteNode(adr root, int id) {
    if (root == NULL) return root;
    if (id < root->id) root->left = deleteNode(root->left,id);
    else if (id > root->id) root->right = deleteNode(root->right,id);
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
        root->id = t->id;
        root->nama = t->nama;
        root->stok = t->stok;
        root->right = deleteNode(root->right,t->id);
    }
    return root;
}

void inorder(adr root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "ID Produk   : " << root->id << endl;
        cout << "Nama Produk : " << root->nama << endl;
        cout << "Stok        : " << root->stok << endl;
        cout << "-----------------------------" << endl;
        inorder(root->right);
    }
}

void preorder(adr root) {
    if (root != NULL) {
        cout << "ID Produk   : " << root->id << endl;
        cout << "Nama Produk : " << root->nama << endl;
        cout << "Stok        : " << root->stok << endl;
        cout << "-----------------------------" << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(adr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << "ID Produk   : " << root->id << endl;
        cout << "Nama Produk : " << root->nama << endl;
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
