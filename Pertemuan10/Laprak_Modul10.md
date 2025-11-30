# <h1 align="center">Laporan Praktikum Modul 10 - TREE (BAGIAN PERTAMA) </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Binary Search Tree (BST) adalah implementasi khusus dari Binary Tree yang menerapkan aturan terurut: seluruh node pada subtree kiri bernilai lebih kecil dari parent-nya dan seluruh node pada subtree kanan bernilai lebih besar. BST memungkinkan operasi pencarian yang efisien serupa konsep Binary Search Algorithm dengan kompleksitas rata-rata O(log n) jika pohon cukup seimbang.

Pada praktikum ini, BST diimplementasikan menggunakan linked list (pointer-based dynamic nodes) melalui ADT (Abstract Data Type). Implementasi berbasis pointer memberi fleksibilitas manajemen memori menggunakan teknik alokasi/dealokasi dari sistem (heap memory). Operasi utama BST meliputi:

- Insert: node ditempatkan di subtree kiri/kanan sesuai perbandingan nilai.
- Search: traversal menuruni jalur kiri/kanan hingga nilai ditemukan atau mencapai pointer NULL.
- Delete: memiliki 4 case (leaf, 1 child kiri, 1 child kanan, 2 children dengan successor/pengganti).
- Traversal: Pre-order, In-order, Post-order untuk menampilkan struktur pohon.

Untuk menunjang implementasi, digunakan library standar input/output dari ISO C++ Standard Library seperti iostream, serta manajemen memori dari heap menggunakan operator new dan delete.

Queue dalam BST (Permintaan Unguided)

Queue adalah struktur data linear dengan prinsip FIFO (First-In-First-Out). Pada permintaan Unguided, kamu diminta mengimplementasikan queue dengan alternatif: head diam, tail bergerak — mekanisme ini identik dengan implementasi Singly Linked List Queue, dimana:
- enqueue menambah data di belakang (tail "bergerak")
- dequeue menghapus data di depan (head "diam")
Queue dapat digunakan pada tree untuk traversal level-order, penjadwalan node, atau buffering operasi lain ke depannya.

## Guided 

### 1. Implementasi ADT Binary Search Tree (BST) dengan Operasi CRUD, Pencarian, dan Traversal Rekursif di C++

#### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node;

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```

#### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}
```
#### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
#### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Guided1.png)

#### Penjelasan

Guided 1 mengimplementasikan ADT Binary Search Tree secara lengkap mencakup manajemen memori dan operasi dasar pohon biner terurut. File bst.h mendefinisikan abstraksi simpul berbasis pointer (typedef struct BST *node) yang nantinya dialokasikan di heap. Fungsi createTree menginisialisasi root menjadi NULL sebagai empty tree agar traversal aman, sedangkan alokasi membuat node baru menggunakan operator new, mengisi data integer (angka), serta mengatur pointer left dan right menjadi NULL. Fungsi insertNode ditulis rekursif: jika subtree kosong maka node baru menjadi root/subroot, jika nilai lebih kecil masuk ke subtree kiri, jika lebih besar ke subtree kanan, sehingga penempatan selalu memenuhi aturan BST. searchByData menggunakan loop iteratif untuk menuruni tree sambil menyimpan parent, lalu menampilkan relasi node berupa parent, sibling, dan child kiri/kanan agar praktikan memahami hubungan struktural dalam tree. Traversal pohon dilakukan dengan DFS melalui preOrder (root–kiri–kanan), inOrder (kiri–root–kanan, yang pasti menghasilkan keluaran terurut pada BST), dan postOrder (kiri–kanan–root). Operasi deleteNode menangani 4 case terstruktur: leaf, satu child kiri, satu child kanan, serta dua child dengan mengambil successor paling kiri dari subtree kanan sebagai pengganti agar tree tetap valid setelah penghapusan. Fungsi mostLeft dan mostRight menelusuri child kiri/kanan hingga ujung untuk mendapatkan nilai minimum/maksimum, sementara size dan height menghitung properti tree secara rekursif menyeluruh (Full Tree DFS) dengan logika akumulasi dan pemilihan branch terdalam. File main.cpp bertugas sebagai driver program dengan antarmuka menu, memanggil setiap fungsi ADT secara terkontrol, serta menampilkan output runtime sebagai verifikasi bahwa operasi berjalan sesuai konsep BST terurut dan pointer-based dynamic memory yang benar.

## Unguided 

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Soal1.png)

### Buatlah implementasi ADT Queue pada file “bst.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

// Definisikan tipe data
typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

typedef address BinTree;

address alokasi (infotype x);
void insertNode(address& root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif // BSTREE_H
```

#### bst.cpp
```C++
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
```

#### main.cpp
```C++
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
```

#### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided1.png)

#### Penjelasan

Unguided 1 membangun versi minimal ADT BST berbasis pointer menggunakan Linked Node Structure untuk menyimpan elemen pohon di heap. Struktur Node menyimpan info (integer) dan pointer left/right sebagai children. Fungsi alokasi membuat simpul baru dengan operator new, mengisi data input, dan menginisialisasi children ke NULL. insertNode didefinisikan rekursif: jika subtree kosong (NULL) node baru disisipkan, jika nilai input lebih kecil menuruni subtree kiri, jika lebih besar menuruni subtree kanan, dan duplicate input diabaikan agar aturan BST tidak dilanggar. Fungsi pencarian findNode bekerja secara rekursif, menuruni jalur kiri/kanan sampai data ditemukan atau pointer mencapai NULL sebagai kondisi berhenti, lalu mengembalikan address node yang dicari. Traversal yang diimplementasikan printInorder menggunakan DFS kiri–root–kanan, yang dalam BST akan mencetak node dalam keadaan terurut, menjadi bukti bahwa proses insert sudah menempatkan node sesuai aturan binary search property. File main.cpp berperan sebagai driver untuk menguji ADT, mulai dari inisialisasi root = NULL, memanggil insertNode dengan deret data tertentu, lalu mencetak hasil inorder dan menguji keberhasilan findNode, sehingga praktikan dapat memverifikasi bahwa ADT dasar BST berjalan benar pada dynamic memory dan recursion logic.

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut
![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Soal2.png)

#### bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

typedef address BinTree;

address alokasi (infotype x);
void insertNode(address& root, infotype x);
void printInorder(address root);

// Fungsi untuk Soal 2
int hitungJumlahNode(address root);
int hitungTotalInfo (address root);
int hitungKedalaman(address root);
int max(int a, int b);

#endif
```

#### bst.cpp
```C++
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
```

#### main.cpp
```C++
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
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided2.png)

#### Penjelasan

Ungguided 2 melanjutkan implementasi ADT BST dengan menambahkan fungsi-fungsi properti pohon melalui pendekatan DFS menyeluruh. Fungsi hitungJumlahNode dibuat rekursif untuk menghitung total semua simpul di tree dengan logika 1 + kiri + kanan sampai seluruh subtree habis, menjadi implementasi Full Tree DFS Count, dan mengembalikan 0 jika pointer NULL sebagai basis berhenti. hitungTotalInfo menjumlahkan nilai yang disimpan pada setiap simpul (root->info + kiri + kanan) secara rekursif sehingga menghasilkan total akumulasi data numerik yang ada pada tree. Fungsi kedalaman maksimal dihitung oleh hitungKedalaman dengan menurun ke subtree kiri dan kanan, memilih nilai terbesar di antara keduanya using helper max, lalu ditambah 1 untuk merepresentasikan level tree dari branch terpanjang, sehingga memberikan kedalaman terdalam dari root. File main.cpp dipakai sebagai driver test case untuk memasukkan node tertentu, mencetak traversal inorder sebagai validasi ordering, lalu memanggil fungsi jumlah node, kedalaman, dan total info, sehingga praktikan dapat memverifikasi properti tree hasil insert, memahami cara kerja rekursi pada branch depth dan akumulasi node count, sekaligus memastikan hasil operasi sesuai ilustrasi tree tanpa terjadi memory fault pada dynamic nodes.

### 3. Print tree secara pre-order dan post-order.
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Soal3.png)

#### bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

typedef int infotype;
typedef struct Node* address;

typedef struct Node {
    infotype info;
    address left;
    address right;
} Node;

typedef address BinTree;

address alokasi (infotype x);
void insertNode(address& root, infotype x);
void printInorder(address root);

// Fungsi untuk Soal 3
void printPreorder(address root);
void printPostorder(address root);

#endif
```

#### bst.cpp
```C++
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
```
#### main.cpp
```C++
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
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided3.png)

#### Penjelasan

Ungguided 3 menambah pemahaman traversal pada BST dengan mengimplementasikan fungsi printPreorder dan printPostorder menggunakan pendekatan DFS yang sulit digantikan secara iteratif pada struktur non-linear. printPreorder mencetak data pada setiap simpul dengan pola root–left–right secara rekursif, mulai dari root, lalu menurun ke subtree kiri secara preorder dan subtree kanan secara preorder juga, agar urutan structur insertion terlihat dalam bentuk penelusuran top-down. printPostorder melakukan traversal left–right–root, memanggil dirinya pada subtree kiri sampai habis, kemudian subtree kanan sampai habis, lalu mencetak root/subroot di akhir, menghasilkan tampilan bottom-up dari struktur tree. File main.cpp digunakan untuk insert node sesuai ilustrasi tree, kemudian memanggil traversal inorder, preorder, dan postorder, sehingga praktikan dapat membandingkan tiga pola traversal DFS untuk memahami perbedaan urutan proses: inorder sebagai sorted verification khas BST, preorder sebagai kunjungan berbasis root dulu, dan postorder sebagai kunjungan children dulu baru root, semuanya menggunakan mekanisme recursion call stack yang benar pada node-node dinamis berbasis pointer.

## Kesimpulan

Kesimpulan dari seluruh praktikum ini adalah bahwa struktur Binary Search Tree (BST) berhasil diimplementasikan menggunakan linked list berbasis pointer di heap memory, yang memperkuat pemahaman tentang alokasi memori dinamis (new–delete) serta hubungan hierarki antar node (root, parent, sibling, child). Operasi insert baik pada Guided maupun Unguided bekerja dengan pola rekursi untuk menentukan posisi node di subtree kiri atau kanan berdasarkan perbandingan nilai, sehingga pada traversal inorder selalu menghasilkan keluaran terurut menaik, yang menjadi indikator utama bahwa properti BST terpenuhi. Operasi search mengajarkan proses penurunan tree dengan logika percabangan kiri/kanan hingga data ditemukan atau pointer menjadi NULL sebagai kondisi berhenti, sedangkan operasi delete pada bagian Guided menerapkan 4 kasus terstruktur termasuk mekanisme successor untuk node dengan 2 children agar tree tetap valid pasca penghapusan. Traversal pre-order dan post-order pada Unguided 3 memperluas wawasan terhadap variasi DFS (Depth-First Search) untuk membaca alur struktur tree dari sudut top-down maupun bottom-up, yang sulit diganti secara iteratif pada struktur non-linear. Selain itu, konsep queue (head diam, tail bergerak) yang diminta pada soal Ungguided relevan sebagai dasar untuk Level-Order Traversal di pengembangan berikutnya. Secara keseluruhan, praktikum ini membuktikan bahwa rekursi adalah pendekatan yang paling natural pada operasi tree, mempermudah penulisan dan pemahaman logika program, meskipun memiliki trade-off pada penggunaan memori stack, namun tetap sangat sesuai untuk penyelesaian permasalahan berbasis pohon biner terurut.

## Referensi

[1] T. H. Cormen, C. E. Leiserson, R. L. Rivest, dan C. Stein, Introduction to Algorithms, 4th ed. Cambridge, MA: MIT Press, 2022.
<br>[2] M. A. Weiss, Data Structures and Algorithm Analysis in C++, 4th ed. Boston, MA: Pearson, 2014.
<br>[3] D. S. Malik, C++ Programming: Program Design Including Data Structures, 8th ed. Boston, MA: Cengage Learning, 2018.
<br>[4] S. Lipschutz, Data Structures (Schaum's Outline Series), 2nd ed. New York: McGraw-Hill, 2011.
<br>[5] N. Karumanchi, Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles, 5th ed. CareerMonk        Publications, 2016.
<br>[6] GeeksforGeeks, "Binary Search Tree Data Structure," GeeksforGeeks, 2024. [Online]. Available: https://www.geeksforgeeks.org/binary-search-tree-data-structure/. [Accessed: 30-Nov-2025].
