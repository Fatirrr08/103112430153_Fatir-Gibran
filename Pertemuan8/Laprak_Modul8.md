# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Queue (Antrean) adalah struktur data linier yang mengikuti prinsip FIFO (First-In, First-Out). Artinya, elemen data yang pertama kali dimasukkan (First-In) akan menjadi elemen yang pertama kali dikeluarkan (First-Out). Ini dapat diumpamakan seperti antrean di loket tiket, di mana orang yang pertama datang akan dilayani terlebih dahulu.

#### Operasi dasar pada Queue adalah

Enqueue (Insert): Proses untuk menambahkan elemen baru ke dalam antrean. Elemen baru selalu ditambahkan di posisi akhir (belakang) antrean, yang biasa disebut Tail.

Dequeue (Delete): Proses untuk menghapus atau mengambil elemen dari antrean. Elemen selalu diambil dari posisi paling depan antrean, yang biasa disebut Head.

#### Implementasi Queue dapat dilakukan dengan dua cara utama

Linked List (Senarai Berantai): Seperti pada Guided 1, implementasi ini menggunakan pointer. Head adalah pointer ke elemen pertama dan Tail adalah pointer ke elemen terakhir. Keuntungannya adalah ukuran antrean yang dinamis dan tidak terbatas (tergantung memori).

Array (Tabel): Seperti pada Guided 2 dan Unguided, implementasi ini menggunakan array dengan ukuran tetap. Terdapat beberapa alternatif untuk mengelola Head dan Tail dalam array:

Alternatif 1 (Head Diam): Head selalu berada di indeks 0. Operasi dequeue menjadi tidak efisien (O(n)) karena semua elemen harus digeser ke kiri.

Alternatif 2 (Head Bergerak): Head dan Tail bergerak maju. Dequeue menjadi efisien (O(1)), namun dapat terjadi kondisi "penuh semu" (pseudo-full) saat Tail mencapai akhir array. Saat ini terjadi, enqueue harus melakukan pergeseran elemen (O(n)).

Alternatif 3 (Circular Buffer): Implementasi array yang paling efisien. Head dan Tail bergerak "memutar" atau wrap-around menggunakan operasi modulo. Ini menghindari pergeseran elemen, sehingga enqueue dan dequeue tetap efisien (O(1)).

## Guided 

### 1. Implementasi Queue dengan Linked List (Dinamis)

#### Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);   
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

#### Queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```
#### main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```
#### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Guided1.png)

#### Penjelasan

Program Guided 1 mengimplementasikan Queue menggunakan Singly Linked List yang dinamis. struct Node didefinisikan untuk menyimpan nama (bertipe string) dan pointer next, sementara struct queue menyimpan dua pointer utama: head (menunjuk ke elemen pertama) dan tail (menunjuk ke elemen terakhir). Fungsi CreateQueue menginisialisasi antrean kosong dengan mengatur head dan tail ke nullptr. Operasi enQueue membuat Node baru di memori; jika antrean kosong, head dan tail akan menunjuk ke node baru tersebut, namun jika sudah terisi, node tail yang lama akan diarahkan (next) ke node baru, dan tail diperbarui untuk menunjuk ke node baru itu. Operasi deQueue menghapus elemen dari depan dengan menyimpan head saat ini, menggeser head ke head->next, dan membebaskan memori (delete) dari node yang disimpan tadi. Fungsi isFull selalu mengembalikan false karena sifat dinamis linked list yang hanya dibatasi oleh memori sistem.

### 2. Implementasi Queue dengan Array (Statis - Alternatif 1)

#### Queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

#### Queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

#### main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
#### Output Guided 2
![Screenshot Output guided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Guided2.png)

#### Penjelasan

Program Guided 2 mengimplementasikan Queue menggunakan Array statis dengan ukuran MAKSIMAL = 5 dan menerapkan mekanisme Alternatif 1 (Head Diam). Antrean kosong ditandai dengan head = -1 dan tail = -1. Fungsi enQueue akan mengatur head dan tail ke 0 saat elemen pertama masuk, dan untuk elemen-elemen berikutnya, hanya tail yang bergerak maju (tail++). Logika kunci terdapat pada deQueue: setelah mengambil elemen di Q.nama[Q.head] (yang selalu di indeks 0), sebuah looping for dieksekusi untuk menggeser semua elemen yang tersisa (dari i = 0 hingga Q.tail) satu posisi ke kiri. Setelah pergeseran, tail dikurangi (tail--). Ini adalah implementasi yang logikanya sederhana namun tidak efisien (O(n)) untuk operasi deQueue.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Soal1.png)

### Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### Queue.h
```C++
#ifndef queue_h
#define queue_h

#include <iostream>

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### Queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Antrean Penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        std::cout << "Antrean Kosong" << std::endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << "H:" << Q.head << " T:" << Q.tail << " | Queue: ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            std::cout << Q.info[i] << " ";
        }
        std::cout << std::endl;
    }
}
```

#### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;

    cout << "H-T \t | Queue Info" << endl;
    cout << "--------------------" << endl;

    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);

    return 0;
}
```

#### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided1.png)

#### Penjelasan

Program Unguided 1 adalah implementasi dari soal latihan PDF , yang secara spesifik menginstruksikan penggunaan Alternatif 1 (Head Diam), sama seperti pada Guided 2. Dengan MAX_SIZE = 5 dan infotype bertipe int, program ini menginisialisasi head dan tail ke -1. Fungsi enqueue mengatur head ke 0 saat elemen pertama masuk dan setelahnya hanya meng-increment tail. Fungsi dequeue mengambil nilai di Q.info[Q.head] (indeks 0), lalu melakukan pergeseran (shifting) semua elemen sisa satu langkah ke kiri menggunakan for loop, dan diakhiri dengan mengurangi tail. Program main yang digunakan sesuai dengan Gambar 8-18 , yang menampilkan status H (Head) dan T (Tail), di mana H terlihat selalu 0 (kecuali saat kosong) karena dequeue selalu menggeser elemen kembali ke depan.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### Queue.h
```C++
#ifndef queue_h
#define queue_h

#include <iostream>

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### Queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Antrean Penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            if (Q.tail == MAX_SIZE - 1) {
                int i = Q.head;
                int j = 0;
                while (i <= Q.tail) {
                    Q.info[j] = Q.info[i];
                    i++;
                    j++;
                }
                Q.head = 0;
                Q.tail = j - 1;
            }
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        std::cout << "Antrean Kosong" << std::endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << "H:" << Q.head << " T:" << Q.tail << " | Queue: ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            std::cout << Q.info[i] << " ";
        }
        std::cout << std::endl;
    }
}
```

#### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;

    cout << "H-T \t | Queue Info" << endl;
    cout << "--------------------" << endl;

    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);

    return 0;
}
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided2.png)

#### Penjelasan

Program Unguided 2 mengimplementasikan Alternatif 2 (Head Bergerak). Berbeda dengan Alternatif 1, fungsi dequeue di sini jauh lebih efisien (O(1)) karena tidak lagi melakukan pergeseran; ia hanya menggeser penanda head satu langkah ke depan (Q.head++). Namun, kompleksitas pergeseran (O(n)) kini berpindah ke fungsi enqueue untuk menangani "penuh semu". Fungsi enqueue memiliki logika khusus: jika tail == MAX_SIZE - 1 (mentok di akhir) tetapi head tidak di 0 (ada ruang kosong di depan), maka enqueue akan menggeser semua elemen yang ada (dari head ke tail) kembali ke awal array, memperbarui head dan tail, baru kemudian menambahkan elemen baru . Program main menunjukkan H (Head) yang ikut bergerak maju (misalnya menjadi H:1, H:2) saat dequeue dipanggil.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### Queue.h
```C++
#ifndef queue_h
#define queue_h

#include <iostream>

#define MAX_SIZE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_SIZE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### Queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == MAX_SIZE - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Antrean Penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
            Q.info[Q.tail] = x;
        } else {
            if (Q.tail == MAX_SIZE - 1) {
                int i = Q.head;
                int j = 0;
                while (i <= Q.tail) {
                    Q.info[j] = Q.info[i];
                    i++;
                    j++;
                }
                Q.head = 0;
                Q.tail = j - 1;
            }
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        std::cout << "Antrean Kosong" << std::endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head++;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << "H:" << Q.head << " T:" << Q.tail << " | Queue: ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            std::cout << Q.info[i] << " ";
        }
        std::cout << std::endl;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;

    cout << "H-T \t | Queue Info" << endl;
    cout << "--------------------" << endl;

    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);

    return 0;
}
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan8/OUTPUT/Unguided3.png)

#### Penjelasan

Program Unguided 3 mengimplementasikan Alternatif 3 (Circular Buffer), yang merupakan metode implementasi array paling efisien. Pada metode ini, baik enqueue maupun dequeue memiliki efisiensi O(1) karena tidak ada pergeseran elemen sama sekali. Logika ini dicapai dengan memperlakukan array seolah-olah "melingkar" menggunakan operasi modulo (%). Fungsi enqueue menggerakkan tail dengan rumus Q.tail = (Q.tail + 1) % MAX_SIZE, dan dequeue menggerakkan head dengan Q.head = (Q.head + 1) % MAX_SIZE . Fungsi isFullQueue juga harusnya menggunakan logika modulo ((Q.tail + 1) % MAX_SIZE == Q.head) untuk mendeteksi antrean penuh secara akurat dalam kondisi sirkular. Dengan main yang sama, antrean dapat "berputar" di dalam array, memanfaatkan kembali slot-slot kosong di depan yang ditinggalkan oleh head tanpa perlu pergeseran.

## Kesimpulan

Praktikum Modul 8 ini mendemonstrasikan konsep dan implementasi struktur data Queue yang berprinsip FIFO (First-In, First-Out), di mana elemen pertama masuk adalah elemen pertama keluar. Terdapat dua metode implementasi utama yang dipelajari: Linked List (diterapkan pada Guided 1), yang bersifat dinamis sehingga ukurannya fleksibel dan tidak ada batasan "penuh" selain memori; serta Array (diterapkan pada Guided 2 dan Unguided 1-3), yang bersifat statis dengan ukuran tetap. Implementasi array dipelajari lebih lanjut melalui tiga alternatif, di mana Alternatif 1 (Head Diam)  memiliki kelemahan pada efisiensi dequeue (O(n)) karena memerlukan pergeseran seluruh elemen. Alternatif 2 (Head Bergerak) meningkatkan efisiensi dequeue (O(1)) namun masih berpotensi tidak efisien (O(n)) saat terjadi "penuh semu" dan memaksa dilakukannya pergeseran. Terakhir, Alternatif 3 (Circular Buffer) terbukti menjadi metode array paling efisien karena operasi enqueue dan dequeue sama-sama O(1) dengan memanfaatkan operasi modulo untuk "berputar" tanpa perlu pergeseran elemen.

## Referensi

[1] Modul 8 - QUEUE. Fakultas Informatika, Telkom University.
<br>[2] GeeksforGeeks. (2024). Queue Data Structure.
<br>[3] Programiz. (2024). Queue Data Structure.
<br>[4] cplusplus.com. (2024). std::queue.
<br>[5] Malik, D. S. (2018). Data Structures Using C++ (Edisi ke-3). Cengage Learning.
<br>[6] Lafore, R. (2002). Data Structures & Algorithms in Java (Edisi ke-2). Sams Publishing.
