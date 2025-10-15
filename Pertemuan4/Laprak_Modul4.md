# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAМА) </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Struktur data Singly Linked List merupakan salah satu bentuk penyimpanan data dinamis di mana elemen-elemen data disebut sebagai node yang saling terhubung melalui pointer. Setiap node pada linked list terdiri dari dua bagian utama, yaitu data (yang menyimpan nilai informasi seperti integer, string, atau tipe data kompleks lainnya) dan pointer next yang menunjuk ke node berikutnya dalam urutan list. Berbeda dengan array yang bersifat statis dan memiliki ukuran tetap, linked list bersifat dinamis, sehingga dapat bertambah atau berkurang elemen tanpa harus menggeser posisi memori. Operasi utama pada singly linked list meliputi pembuatan list baru, penyisipan node di awal (insertFirst), di tengah (insertAfter), atau di akhir (insertLast), serta penghapusan node di berbagai posisi (deleteFirst, deleteLast, deleteAfter). Implementasi dalam C++ umumnya menggunakan struct untuk mendefinisikan node dan pointer sebagai penghubung antar node. Keunggulan utama struktur ini adalah efisiensi dalam menambah atau menghapus data tanpa perlu mengalokasikan ulang seluruh memori, namun memiliki kekurangan berupa akses yang tidak langsung (harus menelusuri node satu per satu). Dalam konteks pemrograman sistem, pemahaman linked list penting karena banyak digunakan untuk mengimplementasikan stack, queue, tabel hash, hingga manajemen proses dan memori dinamis di sistem operasi.

## Guided 

### 1. linkedLIst DataMahasiswa

#### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &L);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
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

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

##### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Guided1.png)

### Penjelasan
Program Guided 1 bertujuan mengenalkan konsep dasar pembuatan singly linked list dengan tipe data kompleks berupa struct mahasiswa yang menyimpan nama, nim, dan umur. Pada file list.h, didefinisikan struktur node yang berisi data mahasiswa dan pointer next untuk menghubungkan node lain. Fungsi-fungsi penting seperti createList() digunakan untuk menginisialisasi list kosong, alokasi() untuk membuat node baru di memori heap, dealokasi() untuk menghapus node dari memori, serta prosedur insertFirst(), insertAfter(), dan insertLast() untuk menambahkan node pada posisi berbeda. Pada file list.cpp, seluruh fungsi tersebut diimplementasikan dengan logika pointer, memastikan keterhubungan antar node terjaga dengan benar. Di main.cpp, beberapa node mahasiswa dialokasikan dan disambungkan menggunakan fungsi insert agar terbentuk urutan data. Program ini menggambarkan bagaimana data dinamis mahasiswa bisa diatur dalam struktur berantai tanpa batas ukuran tetap. Ketika printList() dijalankan, fungsi tersebut menelusuri pointer dari node pertama hingga akhir dan menampilkan seluruh isi list, membuktikan bahwa hubungan antar node berhasil dibentuk secara berurutan melalui alamat memori dinamis.

### 2. linkedLIst DataMahasiswa Delete

#### list.h
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &L);
address alokasi(string nama, string nim, int umur);
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

#endif
```

#### list.cpp
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;

typedef struct node *address;

struct node {
    dataMahasiswa isidata;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &L);
address alokasi(string nama, string nim, int umur);
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

#endif
```

#### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

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

##### Output Guided 2

![Screenshot Output guided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Guided2.png)

### Penjelasan
Program Guided 2 merupakan pengembangan dari Guided 1 dengan menambahkan operasi penghapusan node menggunakan prosedur delFirst(), delLast(), dan delAfter(). Fungsi delFirst() menghapus node paling depan dengan cara menggeser pointer first ke node berikutnya, sedangkan delLast() menelusuri node hingga sebelum node terakhir untuk menghapus node paling ujung. delAfter() digunakan untuk menghapus node yang berada di tengah, tepat setelah node tertentu (nodePrev). Tambahan fungsi nbList() berfungsi menghitung jumlah node dalam list, dan deleteList() digunakan untuk menghapus semua node secara keseluruhan dari memori heap agar tidak terjadi kebocoran memori (memory leak). Dalam main.cpp, data mahasiswa yang sama seperti pada Guided 1 dibuat dan kemudian dilakukan proses penghapusan bertahap. Hasil eksekusi menunjukkan jumlah node berkurang seiring setiap operasi delete dijalankan, lalu seluruh node dihapus hingga list menjadi kosong. Program ini memperlihatkan pentingnya pengelolaan memori dalam struktur data dinamis, di mana setiap node yang tidak digunakan harus dihapus secara eksplisit untuk menjaga efisiensi dan stabilitas program.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file "Singlylist.h" Kemudian buat implementasi ADT Singly Linked list pada file "Singlylist.cpp". Adapun isi data
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Soal1.png)

### Cobalah hasil implementasi ADT pada file "main.cpp"
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Soal1a.png)

#### Singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

#endif
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
    } else {
        while (P != Nil) {
            std::cout << P->info << " ";
            P = P->next;
        }
        std::cout << std::endl;
    }
}
```

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P;

    CreateList(L);

    P = alokasi(2);
    insertFirst(L, P);

    P = alokasi(0);
    insertFirst(L, P);

    P = alokasi(8);
    insertFirst(L, P);

    P = alokasi(12);
    insertFirst(L, P);

    P = alokasi(9);
    insertFirst(L, P);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Unguided1.png)

### Penjelasan
Program Unguided 1 adalah bentuk dasar implementasi singly linked list menggunakan integer sebagai tipe data. Pada file Singlylist.h, didefinisikan struktur ElmList yang berisi elemen data (info) dan pointer next. Fungsi CreateList() membuat list kosong dengan First = Nil, sementara alokasi() bertugas mengalokasikan node baru di heap dan mengisi nilai data. Fungsi insertFirst() digunakan untuk menambahkan node di awal list, dengan cara menghubungkan node baru ke node pertama sebelumnya. Fungsi printInfo() menelusuri seluruh node untuk mencetak isi list secara berurutan. Di main.cpp, beberapa node dengan nilai 2, 0, 8, 12, dan 9 ditambahkan menggunakan insertFirst(), sehingga urutannya terbalik sesuai urutan input. Output program menampilkan seluruh isi list dalam satu baris. Secara keseluruhan, kode ini mendemonstrasikan prinsip dasar bagaimana pointer digunakan untuk membuat rantai data dinamis yang saling terhubung, menggantikan peran array statis yang terbatas.

### 2. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp” Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut : 
![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Soal2.png)

### Sehingga linkedlist yang dibuat akan seperti ini :
![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Soal2a.png)

#### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void insertAfter(Node* Prec, Node* P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node* Prec);
void printInfo(List L);
int nbList(List L);
void deleteList(List &L);

#endif
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, Node* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = L.first->next;
        delete P;
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* Q = L.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            delete Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

void printInfo(List L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
```

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(2));
    insertAfter(L.first, alokasi(12));

    cout << "Isi Linked List awal: ";
    printInfo(L);

    deleteFirst(L);

    deleteLast(L);

    deleteAfter(L.first);

    cout << "\nIsi Linked List setelah penghapusan: ";
    printInfo(L);

    cout << "\nJumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Unguided2.png)

### Penjelasan
Pada Unguided 2, program mulai menerapkan operasi insert dan delete lengkap pada list integer. Struktur Node dan List sama seperti sebelumnya, namun kini terdapat lebih banyak fungsi yang menangani seluruh operasi manipulasi data. Fungsi insertFirst(), insertLast(), dan insertAfter() mengatur posisi penyisipan node di awal, akhir, atau setelah node tertentu dengan logika pointer yang saling menghubungkan antar node. Fungsi deleteFirst(), deleteLast(), dan deleteAfter() digunakan untuk menghapus node dari posisi berbeda, dengan hati-hati memutus dan menghapus alamat memori yang sudah tidak dipakai agar tidak menimbulkan dangling pointer. Fungsi nbList() menghitung total node, sedangkan deleteList() menghapus seluruh elemen secara rekursif dari awal hingga akhir. Dalam main.cpp, list dibentuk dengan urutan 9 → 12 → 8 → 2, lalu beberapa operasi delete dilakukan sehingga list menjadi lebih pendek. Program ini menunjukkan bahwa setiap operasi penghapusan membutuhkan traversal dan manipulasi pointer yang akurat untuk menjaga integritas rantai data. Konsep ini penting karena kesalahan kecil dalam pengelolaan pointer dapat menyebabkan kebocoran memori atau crash program.

### 3. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruhnode menggunakan deleteList().Output yang diharapkan :
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Soal3.png) 

#### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

struct List {
    Node* first;
};

void createList(List &L);
Node* alokasi(int x);
void insertFirst(List &L, Node* P);
void insertLast(List &L, Node* P);
void insertAfter(Node* Prec, Node* P);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(Node* Prec);
void printInfo(List L);
int nbList(List L);
void deleteList(List &L);

#endif
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

Node* alokasi(int x) {
    Node* P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void insertFirst(List &L, Node* P) {
    P->next = L.first;
    L.first = P;
}

void insertLast(List &L, Node* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        Node* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(Node* Prec, Node* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* P = L.first;
        L.first = L.first->next;
        delete P;
    }
}

void deleteLast(List &L) {
    if (L.first != nullptr) {
        if (L.first->next == nullptr) {
            delete L.first;
            L.first = nullptr;
        } else {
            Node* Q = L.first;
            while (Q->next->next != nullptr) {
                Q = Q->next;
            }
            delete Q->next;
            Q->next = nullptr;
        }
    }
}

void deleteAfter(Node* Prec) {
    if (Prec != nullptr && Prec->next != nullptr) {
        Node* P = Prec->next;
        Prec->next = P->next;
        delete P;
    }
}

void printInfo(List L) {
    Node* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    Node* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    Node* P = L.first;
    while (P != nullptr) {
        Node* temp = P;
        P = P->next;
        delete temp;
    }
    L.first = nullptr;
}
```

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(9));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(2));
    insertAfter(L.first, alokasi(12));

    cout << "Linked List awal: ";
    printInfo(L);

    deleteFirst(L);

    deleteLast(L);

    deleteAfter(L.first);

    cout << "\nLinked List setelah penghapusan: ";
    printInfo(L);

    cout << "\nJumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

##### Output 

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan4/OUTPUT/Unguided3.png)

### Penjelasan
Program Unguided 3 merupakan penerapan langsung dari soal latihan yang meminta penghapusan node berdasarkan posisi dan urutan logis. Pada tahap awal, program membangun list berisi 9 → 12 → 8 → 2 menggunakan kombinasi fungsi insertFirst, insertLast, dan insertAfter. Selanjutnya, dilakukan penghapusan node secara berurutan menggunakan deleteFirst() untuk menghapus node 9, deleteLast() untuk menghapus node 2, serta deleteAfter() untuk menghapus node 8 yang berada setelah node 12. Setelah setiap penghapusan, fungsi nbList() dipanggil untuk menghitung jumlah node yang tersisa, dan printInfo() digunakan untuk menampilkan isi list terkini. Terakhir, fungsi deleteList() dijalankan untuk menghapus seluruh node yang tersisa agar list benar-benar kosong. Kode ini menggambarkan penerapan penuh seluruh operasi dasar linked list: pembuatan, penyisipan, penghapusan selektif, dan pembersihan memori. Implementasi ini menegaskan bahwa Singly Linked List memberikan fleksibilitas tinggi dalam manajemen data, namun membutuhkan kontrol logika pointer yang hati-hati agar struktur data tetap konsisten dan tidak terjadi kehilangan referensi memori.

## Kesimpulan
Dari seluruh percobaan Guided dan Unguided pada Modul 4, dapat disimpulkan bahwa Singly Linked List adalah struktur data dinamis yang sangat fleksibel dalam pengelolaan elemen data karena dapat melakukan operasi tambah, hapus, dan ubah tanpa perlu menggeser data seperti pada array. Namun, penggunaan linked list membutuhkan pemahaman mendalam tentang pointer dan manajemen memori agar tidak menimbulkan error seperti memory leak atau dangling pointer. Implementasi fungsi seperti insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, serta deleteList memperlihatkan bagaimana hubungan antar node dikelola secara manual oleh programmer. Dengan memanfaatkan fungsi bantu seperti nbList() dan printInfo(), data dalam list dapat diakses, dihitung, dan ditampilkan dengan mudah. Secara keseluruhan, praktikum ini memperkuat pemahaman konsep data structure linking dan keterampilan teknis dalam pemrograman berbasis pointer di C++, yang menjadi dasar penting untuk memahami struktur data lanjutan seperti stack, queue, tree, dan graph.

## Referensi

[1] Munir, Rinaldi. Algoritma dan Struktur Data. Informatika Bandung, 2019.
<br>[2] Drozdek, Adam. Data Structures and Algorithms in C++. Cengage Learning, 2012.
<br>[3] Weiss, Mark Allen. Data Structures and Algorithm Analysis in C++. Addison-Wesley, 2014.
<br>[4] Sedgewick, Robert & Wayne, Kevin. Algorithms, 4th Edition. Pearson, 2011.
<br>[5] GeeksforGeeks. “Singly Linked List in C++”, https://www.geeksforgeeks.org/singly-linked-list-in-cpp/
<br>[6] utorialsPoint. “Data Structures – Linked List”, https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm
<br>[7] Malik, D. S. C++ Programming: From Problem Analysis to Program Design, Cengage Learning, 2018. 