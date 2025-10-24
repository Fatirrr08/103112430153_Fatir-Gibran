# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori
Singly Linked List (SLL) merupakan salah satu bentuk dari linked list di mana setiap elemen (disebut node) terdiri dari dua bagian utama, yaitu data dan pointer (next) yang menunjuk ke node berikutnya. Tidak seperti array, linked list bersifat dinamis — ukuran list dapat bertambah atau berkurang selama program berjalan karena memori dialokasikan secara runtime menggunakan pointer.

Secara umum, singly linked list memiliki operasi-operasi dasar berikut:

1. Create List — membuat list baru yang masih kosong (pointer first = NULL).
2. Insert — menambahkan elemen baru pada posisi tertentu (awal, tengah, atau akhir).
3. Delete — menghapus node tertentu dari list.
4. Traversal / Print List — menampilkan seluruh isi list.
5. Update — mengubah nilai data pada node tertentu.
6. Search — mencari node berdasarkan data, alamat, atau rentang nilai.
7. Delete List — menghapus semua elemen dari list sekaligus.

Ciri khas dari SLL adalah arah aliran data searah (dari first ke next hingga NULL). Karena itu, kita tidak dapat menelusuri ke belakang, berbeda dengan doubly linked list.

Dalam konteks praktikum ini, konsep linked list tidak hanya diterapkan untuk menyimpan angka, tetapi juga dapat diadaptasi untuk menyimpan data kompleks seperti objek “Buah” (memiliki atribut nama, jumlah, dan harga).

Keuntungan penggunaan Singly Linked List:

1. Tidak memerlukan alokasi memori tetap seperti array.
2. Memudahkan operasi penyisipan dan penghapusan data.
3. Cocok untuk struktur data dinamis seperti stack, queue, dan graph.

Namun, kelemahannya adalah:

1. Tidak dapat diakses secara langsung berdasarkan indeks.
2. Membutuhkan manajemen pointer yang hati-hati.
3. Traversal hanya dapat dilakukan satu arah.

## Guided 

### 1. linkedLIst Buah

#### listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

#### listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

##### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Guided1.png)

### Penjelasan

Pada kode Guided 1, dibuat sebuah program untuk mengimplementasikan singly linked list dengan tipe data kompleks bernama buah yang memiliki atribut nama, jumlah, dan harga. File listBuah.h berisi deklarasi struct, alias tipe data (dataBuah dan address), serta daftar fungsi dan prosedur yang digunakan seperti createList, insertFirst, insertAfter, insertLast, delFirst, dan delAfter. Pada listBuah.cpp, setiap prosedur diimplementasikan dengan konsep pointer dan dynamic memory allocation menggunakan new dan delete. Fungsi alokasi() digunakan untuk membuat node baru, sedangkan dealokasi() untuk membebaskan memori. Prosedur insertFirst dan insertLast menambahkan node di posisi awal dan akhir list, sedangkan delFirst dan delLast menghapus node dengan memperhatikan kondisi list kosong atau tidak. Fitur tambahan seperti updateFirst, updateLast, dan updateAfter memungkinkan pengguna mengubah data buah tertentu, sementara FindNodeByData, FindNodeByAddress, dan FindNodeByRange melakukan pencarian berdasarkan nama, alamat memori, dan kisaran harga. Pada main.cpp, beberapa node buah dibuat dan dimasukkan ke dalam list, kemudian dilakukan operasi update, search, dan delete untuk menunjukkan fleksibilitas struktur linked list ini.

## Unguided 

### 1. Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian sebagai berikut :
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Soal1.png)

#### ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif
```

#### ListAngka.cpp
```C++
#include "ListAngka.h"

void createList(linkedList &L) { L.first = nullptr; }

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = nullptr;
    return p;
}

void dealokasi(address p) { delete p; }

void printList(linkedList L) {
    address p = L.first;
    cout << "Isi list: ";
    while (p != nullptr) {
        cout << p->angka << " ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == nullptr) L.first = p;
    else {
        address q = L.first;
        while (q->next != nullptr) q = q->next;
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != nullptr) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}
```

### main.cpp
```C++
#include "ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);

    cout << "-----------------------------------------------------------" << endl;
    cout << "------------------------Sebelum delete---------------------" << endl;
    printList(L);
    
    address delNode;
    delAfter(L, delNode, nodeC);
    
    cout << "-----------------------------------------------------------" << endl;
    cout << "--------------Setelah delAfter nodeB setelah nodeC---------" << endl;
    printList(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Unguided1.png)

### Penjelasan

Program Unguided 1 berisi pembuatan ADT ListAngka yang menyimpan data bertipe int. Pada file ListAngka.h, didefinisikan struktur node dengan atribut angka dan next, serta struktur linkedList yang hanya berisi pointer first. Fungsi-fungsi dasar seperti createList, alokasi, dealokasi, insertFirst, insertLast, insertAfter, delAfter, dan printList dideklarasikan di sini. Dalam ListAngka.cpp, fungsi-fungsi tersebut diimplementasikan untuk mengatur alokasi memori dinamis dan manipulasi pointer. Pada main.cpp, enam node dibuat (8, 13, 18, 25, 33, 40) dan dimasukkan ke dalam list menggunakan kombinasi operasi insert. Setelah itu, dilakukan penghapusan node tertentu dengan delAfter untuk menguji pengelolaan pointer antar-node. Program ini menampilkan hasil sebelum dan sesudah penghapusan untuk memperlihatkan perubahan list.

### 2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan rincian sebagai berikut :
![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Soal2.png) 

#### ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

// Fungsi dasar dari Soal 1
void createList(linkedList &L);
address alokasi(dataAngka x);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
void printList(linkedList L);

// Update
void updateFirst(linkedList &L, int newVal);
void updateLast(linkedList &L, int newVal);
void updateAfter(linkedList &L, address prec, int newVal);

// Search
void searchByData(linkedList L, int data);
void searchByAddress(linkedList L, address p);
void searchByRange(linkedList L, int nilaiMin);

#endif
```

#### ListAngka.cpp
```C++
#include "ListAngka.h"

void createList(linkedList &L) { L.first = nullptr; }

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = nullptr;
    return p;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == nullptr) L.first = p;
    else {
        address q = L.first;
        while (q->next != nullptr) q = q->next;
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void printList(linkedList L) {
    address p = L.first;
    cout << "Isi list: ";
    while (p != nullptr) {
        cout << p->angka << " ";
        p = p->next;
    }
    cout << endl;
}

// UPDATE
void updateFirst(linkedList &L, int newVal) {
    if (L.first != nullptr) L.first->angka = newVal;
}

void updateLast(linkedList &L, int newVal) {
    address p = L.first;
    if (p == nullptr) return;
    while (p->next != nullptr) p = p->next;
    p->angka = newVal;
}

void updateAfter(linkedList &L, address prec, int newVal) {
    if (prec != nullptr && prec->next != nullptr)
        prec->next->angka = newVal;
}

// SEARCH
void searchByData(linkedList L, int data) {
    address p = L.first;
    while (p != nullptr) {
        if (p->angka == data) {
            cout << "Data " << data << " ditemukan di address: " << p << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data " << data << " tidak ditemukan." << endl;
}

void searchByAddress(linkedList L, address cari) {
    address p = L.first;
    while (p != nullptr) {
        if (p == cari) {
            cout << "Node ditemukan, data: " << p->angka << endl;
            return;
        }
        p = p->next;
    }
    cout << "Address tidak ditemukan." << endl;
}

void searchByRange(linkedList L, int nilaiMin) {
    address p = L.first;
    cout << "Data >= " << nilaiMin << ": ";
    while (p != nullptr) {
        if (p->angka >= nilaiMin) cout << p->angka << " ";
        p = p->next;
    }
    cout << endl;
}
```

### main.cpp
```C++
#include "ListAngka.h"

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);


    cout << "-----------------------------------------------------------" << endl;
    cout << "Procedure SearchByData, SearchByAddress, dan SearchByRange " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Sebelum update:" << endl;
    printList(L);
    
    // UPDATE
    updateFirst(L, 50);
    updateLast(L, 29);
    updateAfter(L, nodeD, 45);
    updateAfter(L, nodeB, 20);
    
    cout << "-----------------------------------------------------------" << endl;
    cout << "Setelah update:" << endl;
    printList(L);
    
    // SEARCH
    cout << "-----------------------------------------------------------" << endl;
    cout << "Hasil dari pemanggilan fungsi dan prosedur Search:" << endl;
    searchByData(L, 20);
    searchByData(L, 55);
    searchByAddress(L, nodeB);
    searchByAddress(L, nodeA);
    searchByRange(L, 40);

    return 0;
}
```

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Unguided2.png)

### Penjelasan

Pada Unguided 2, program dikembangkan dengan menambahkan fitur update dan search pada struktur ListAngka. Fungsi updateFirst, updateLast, dan updateAfter digunakan untuk mengubah data node pertama, terakhir, atau node setelah node tertentu. Sedangkan searchByData, searchByAddress, dan searchByRange digunakan untuk mencari data berdasarkan isi node, alamat memori node, dan nilai minimum tertentu. Implementasi di ListAngka.cpp menggunakan traversal pointer yang dimulai dari node pertama (L.first) dan berlanjut hingga akhir (NULL). Pada main.cpp, setelah data dimasukkan ke list, program melakukan beberapa update nilai seperti mengganti 40 menjadi 50 dan 33 menjadi 45. Selanjutnya, dilakukan pencarian nilai 20 dan 55, serta pencarian berdasarkan alamat node dan range nilai ≥ 40. Hasilnya ditampilkan untuk menunjukkan kemampuan program dalam menavigasi dan memodifikasi data menggunakan pointer.

### 3. Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai awal adalah 1.Output yang diharapkan :
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Soal3.png) 

#### ListAngka.h
```C++
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void insertLast(linkedList &L, address p);
void printList(linkedList L);
void operasiAritmetika(linkedList L);

#endif
```

#### ListAngka.cpp
```C++
#include "ListAngka.h"

void createList(linkedList &L) { L.first = nullptr; }

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = nullptr;
    return p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == nullptr) L.first = p;
    else {
        address q = L.first;
        while (q->next != nullptr) q = q->next;
        q->next = p;
    }
}

void printList(linkedList L) {
    address p = L.first;
    cout << "Isi list: ";
    while (p != nullptr) {
        cout << p->angka << " ";
        p = p->next;
    }
    cout << endl;
}

void operasiAritmetika(linkedList L) {
    if (L.first == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    int sum = 0, mult = 1, diff = L.first->angka;
    address p = L.first;

    while (p != nullptr) {
        sum += p->angka;
        mult *= p->angka;
        if (p != L.first) diff -= p->angka;
        p = p->next;
    }

    cout << "Hasil Penjumlahan : " << sum << endl;
    cout << "Hasil Pengurangan : " << diff << endl;
    cout << "Hasil Perkalian   : " << mult << endl;
}
```

### main.cpp
```C++
#include "ListAngka.h"

int main() {
    cout << "-----------------------------------------------------------" << endl;
    cout << "--------------------- Operasi Aritmetika ------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    linkedList L;
    createList(L);
    insertLast(L, alokasi(50));
    insertLast(L, alokasi(20));
    insertLast(L, alokasi(25));
    insertLast(L, alokasi(45));
    insertLast(L, alokasi(29));

    cout << "-----------------Isi linked list saat ini------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    printList(L);
    operasiAritmetika(L);

    return 0;
}
```

##### Output 

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan5/OUTPUT/Unguided3.png)

### Penjelasan
Pada Unguided 3, program berfokus pada penerapan operasi aritmetika menggunakan data di dalam linked list. Dalam file ListAngka.cpp, dibuat fungsi operasiAritmetika() yang menghitung penjumlahan, pengurangan, dan perkalian dari seluruh elemen list dengan melakukan traversal dari node pertama hingga terakhir. Nilai awal untuk penjumlahan adalah 0, untuk pengurangan adalah nilai node pertama, dan untuk perkalian adalah 1. Fungsi ini memanfaatkan loop pointer untuk mengakses tiap elemen dan memperbarui hasil operasi. Pada main.cpp, list diisi dengan nilai 50, 20, 25, 45, 29, kemudian fungsi aritmetika dipanggil untuk menampilkan hasil semua operasi. Program ini menunjukkan bagaimana data numerik dalam linked list dapat diolah seperti array dinamis.

## Kesimpulan
Secara keseluruhan, dari seluruh percobaan Guided dan Unguided pada Modul 5, dapat disimpulkan bahwa Singly Linked List adalah struktur data dinamis yang fleksibel dan efisien dalam pengelolaan data. Konsep pointer dan alokasi memori dinamis memungkinkan manipulasi elemen tanpa batasan ukuran tetap seperti pada array. Operasi dasar seperti insert dan delete memberikan kemampuan untuk membangun struktur data dinamis, sedangkan fitur update, search, dan operasi aritmetika memperlihatkan bagaimana linked list dapat diadaptasi untuk berbagai kebutuhan. Pemahaman konsep ini menjadi fondasi penting dalam mempelajari struktur data lanjutan seperti stack, queue, tree, dan graph, karena seluruhnya berakar pada prinsip keterhubungan node melalui pointer.

## Referensi

[1] Deitel, P. & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson Education.
<br>[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in C++. Wiley.
<br>[3] Nugroho, Adi. (2015). Struktur Data dengan C++. Informatika Bandung.
<br>[4] Sedgewick, Robert & Wayne, Kevin. Algorithms, 4th Edition. Pearson, 2011.
<br>[5] Modul Praktikum Struktur Data Ganjil 2025 – Modul 5: Singly Linked List, Universitas Telkom.
<br>[6] Silberschatz, A., Galvin, P. B., & Gagne, G. (2018). Operating System Concepts (10th ed.). Wiley.