# <h1 align="center">Laporan Praktikum Modul 13 MULTI LINKED LIST</h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Multi Linked List (MLL) adalah struktur data dinamis yang terdiri dari sekumpulan linked list yang saling terhubung. Tidak seperti Single Linked List atau Doubly Linked List biasa yang linear, MLL digunakan untuk merepresentasikan data yang memiliki hubungan hierarkis atau relasi One-to-Many (satu ke banyak). Dalam implementasinya, MLL sering digambarkan dengan konsep Parent (Induk) dan Child (Anak). Setiap node parent dapat memiliki pointer yang menunjuk ke list lain (list anak) yang berisi sekumpulan data yang berasosiasi dengan parent tersebut.

Secara umum, terdapat beberapa variasi bentuk Multi Linked List, antara lain:

- Variasi 1 (Array of Linked List): Pointer ke list child disimpan dalam sebuah array statis.
- Variasi 2 (Linked List of Linked List): List parent berupa linked list dinamis, di mana setiap node parent memiliki pointer ke list child yang juga berupa linked list. Ini adalah variasi yang digunakan dalam praktikum ini karena fleksibilitasnya dalam alokasi memori.
- Variasi 3 (Dynamic Mixed): Kombinasi bentuk kompleks di mana relasi antar node bisa lebih bebas.

Dalam manipulasi MLL, operasi yang dilakukan menjadi lebih kompleks dibandingkan list tunggal. Operasi Traversal (penelusuran) seringkali membutuhkan nested loop (perulangan bersarang); loop luar untuk menelusuri parent, dan loop dalam untuk menelusuri child dari parent tersebut. Operasi Deletion (penghapusan) pada parent memerlukan penanganan khusus yang disebut cascading delete, yaitu sebelum node parent dihapus, seluruh node child yang terhubung dengannya harus dihapus (di-dealokasi) terlebih dahulu untuk mencegah memory leak (kebocoran memori). Struktur data ini sangat berguna untuk kasus nyata seperti kategori produk dengan itemnya, data mahasiswa per kelas, atau klasifikasi biologi hewan.

## Guided 

### 1. Implementasi Multi Linked List untuk Manajemen Data Kategori dan Menu Makanan Restoran

#### mll.h
```C++
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```

#### mll.cpp
```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```
#### main.cpp
```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;
 
    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
#### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Guided1.png)

#### Penjelasan

Program pada Guided 1 mendemonstrasikan implementasi Multi Linked List untuk mengelola menu restoran, di mana "Kategori Makanan" berperan sebagai Parent dan "Menu Makanan" berperan sebagai Child. Struktur data didefinisikan dengan dua tipe node, yaitu nodeParent yang memiliki pointer next, prev, dan pointer ke list anak (L_Anak), serta nodeChild yang menyimpan detail makanan. Program melakukan operasi dasar seperti penyisipan (insert) kategori dan menu, pencarian (searching) bertingkat di mana program mencari ID parent terlebih dahulu baru kemudian mencari ID child di dalamnya, serta pembaruan data (update). Salah satu poin krusial dalam kode ini adalah fungsi deleteParent, yang menerapkan mekanisme penghapusan total; saat sebuah kategori dihapus, fungsi hapusListAnak dipanggil terlebih dahulu untuk membersihkan semua menu di dalamnya sebelum node kategori itu sendiri didealokasi.

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h”
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Soal1.png)

#### mll.h
```C++
#ifndef MLL_SOAL1_H
#define MLL_SOAL1_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

struct nodeChild {
    dataHewan info;
    adrChild next;
    adrChild prev;
};

struct listChild {
    adrChild first;
    adrChild last;
};

struct nodeParent {
    golonganHewan info;
    adrParent next;
    adrParent prev;
    listChild L_Child;
};

struct listParent {
    adrParent first;
    adrParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);
void printMLLStructure(listParent L);

#endif
```

#### mll.cpp
```C++
#include "mll.h"

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent;
    P->info.idGolongan = idGol;
    P->info.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild;
    P->info.idHewan = idHwn;
    P->info.namaHewan = namaHwn;
    P->info.habitat = habitat;
    P->info.ekor = tail;
    P->info.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void printMLLStructure(listParent L) {
    adrParent P = L.first;
    int i = 1;
    cout << "=== Output Soal 1 ===" << endl;
    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan   : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;
        
        adrChild C = P->L_Child.first;
        if (C == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int j = 1;
            while (C != NULL) {
                cout << "- Child " << j << ":" << endl;
                cout << "  ID Hewan    : " << C->info.idHewan << endl;
                cout << "  Nama Hewan  : " << C->info.namaHewan << endl;
                cout << "  Habitat     : " << C->info.habitat << endl;
                cout << "  Ekor        : " << C->info.ekor << endl;
                cout << "  Bobot       : " << C->info.bobot << endl;
                C = C->next;
                j++;
            }
        }
        cout << endl;
        P = P->next;
        i++;
    }
}
```

#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    adrParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    adrParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    insertLastParent(LP, allocNodeParent("G003", "Pisces")); // P3
    adrParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    insertLastParent(LP, allocNodeParent("G005", "Reptil")); // P5

    // Insert Child
    // Aves
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));
    
    // Mamalia
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));

    // Amfibi
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // Print
    printMLLStructure(LP);

    return 0;
}
```

#### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Unguided1.png)

#### Penjelasan

Pada Unguided 1, kode bertujuan membangun struktur hierarki klasifikasi hewan, dengan "Golongan Hewan" (seperti Aves, Mamalia) sebagai Parent dan spesimen hewan spesifik sebagai Child. Program mendefinisikan ADT (Abstract Data Type) MultiLL yang memisahkan deklarasi struktur di header file dan implementasi fungsi di file sumber terpisah. Fungsi allocNodeParent dan allocNodeChild digunakan untuk memesan memori secara dinamis bagi setiap entitas baru. Logika utama program ada pada fungsi insertLastParent dan insertLastChild yang merangkai node-node tersebut menjadi struktur list ganda (Doubly Linked List) di kedua level. Hasil akhirnya adalah struktur data yang mampu menampilkan data hewan yang terkelompok rapi berdasarkan golongannya saat fungsi printMLLStructure dijalankan.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan denganmenelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. Ekspektasi output : 
![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Soal2.png)

#### mll.h
```C++
#ifndef MLL_SOAL2_H
#define MLL_SOAL2_H

// Copy isi struct dari mll_soal1.h di sini
// ... (Bagian struct sama persis dengan soal 1) ...
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan { string idGolongan; string namaGolongan; };
struct dataHewan { string idHewan; string namaHewan; string habitat; bool ekor; float bobot; };
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;
struct nodeChild { dataHewan info; adrChild next; adrChild prev; };
struct listChild { adrChild first; adrChild last; };
struct nodeParent { golonganHewan info; adrParent next; adrParent prev; listChild L_Child; };
struct listParent { adrParent first; adrParent last; };

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);
void printMLLStructure(listParent L);

// --- TAMBAHAN UNTUK SOAL 2 ---
void searchHewanByEkor(listParent L, bool tail);

#endif
```

#### mll.cpp
```C++
#include "mll.h"

void createListParent(listParent &L) { L.first = NULL; L.last = NULL; }
void createListChild(listChild &L) { L.first = NULL; L.last = NULL; }
adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent; P->info.idGolongan = idGol; P->info.namaGolongan = namaGol;
    P->next = NULL; P->prev = NULL; createListChild(P->L_Child); return P;
}
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild; P->info.idHewan = idHwn; P->info.namaHewan = namaHwn;
    P->info.habitat = habitat; P->info.ekor = tail; P->info.bobot = weight;
    P->next = NULL; P->prev = NULL; return P;
}
void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) { L.first = P; L.last = P; } else { P->prev = L.last; L.last->next = P; L.last = P; }
}
void printMLLStructure(listParent L) {
    adrParent P = L.first; int i = 1;
    while (P != NULL) {
        cout << "Parent " << i << " (" << P->info.namaGolongan << ")" << endl;
        adrChild C = P->L_Child.first;
        if(C==NULL) cout << "(kosong)" << endl;
        while (C != NULL) { cout << " - " << C->info.namaHewan << endl; C = C->next; }
        P = P->next; i++; cout << endl;
    }
}

// --- Implementasi Soal 2 ---
void searchHewanByEkor(listParent L, bool tail) {
    adrParent P = L.first;
    int idxParent = 1;
    while (P != NULL) {
        adrChild C = P->L_Child.first;
        int idxChild = 1;
        while (C != NULL) {
            if (C->info.ekor == tail) {
                cout << "Data ditemukan pada list anak dari node parent " 
                     << P->info.namaGolongan << " pada posisi ke-" << idxParent << "!" << endl;
                cout << "--- Data Child ---" << endl;
                cout << "ID Child      : " << C->info.idHewan << endl;
                cout << "Posisi        : posisi ke-" << idxChild << endl;
                cout << "Nama Hewan    : " << C->info.namaHewan << endl;
                cout << "Habitat       : " << C->info.habitat << endl;
                cout << "Ekor          : " << C->info.ekor << endl;
                cout << "Bobot         : " << C->info.bobot << endl;
                cout << "--------------------------" << endl;
                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent     : " << P->info.idGolongan << endl;
                cout << "Posisi        : posisi ke-" << idxParent << endl;
                cout << "Nama Golongan : " << P->info.namaGolongan << endl;
                cout << "--------------------------" << endl << endl;
            }
            C = C->next;
            idxChild++;
        }
        P = P->next;
        idxParent++;
    }
}
```

#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    adrParent P1 = allocNodeParent("G001", "Aves"); insertLastParent(LP, P1);
    adrParent P2 = allocNodeParent("G002", "Mamalia"); insertLastParent(LP, P2);
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    adrParent P4 = allocNodeParent("G004", "Amfibi"); insertLastParent(LP, P4);
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    //Fungsi Search Soal 2
    cout << "=== OUTPUT SOAL 2 (SEARCH EKOR FALSE) ===" << endl;
    searchHewanByEkor(LP, false);

    return 0;
}
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Unguided2.png)

#### Penjelasan

Kode pada Unguided 2 berfokus pada pengembangan fitur pencarian (searching) spesifik dengan kondisi boolean, yaitu mencari hewan yang tidak memiliki ekor (tail == false). Prosedur searchHewanByEkor bekerja dengan cara melakukan traversi (penelusuran) bersarang. Loop utama (outer loop) bergerak menelusuri setiap node Parent (Golongan Hewan), dan di setiap iterasi parent, terdapat loop sekunder (inner loop) yang menelusuri seluruh Child yang dimiliki parent tersebut. Di dalam loop sekunder inilah kondisi if (C->info.ekor == tail) diperiksa. Jika kondisi terpenuhi, program akan mencetak detail hewan beserta informasi golongan induknya, memungkinkan pengguna menemukan data spesifik yang tersebar di berbagai kategori parent yang berbeda.

### 3.Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linkedlistnya berubah menjadi seperi ini :
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Soal3.png)

#### mll.h
```C++
#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

// --- Definisi Pointer dan Node ---
typedef struct nodeParent *adrParent;
typedef struct nodeChild *adrChild;

// Node Child (Anak)
struct nodeChild {
    dataHewan info;
    adrChild next;
    adrChild prev;
};

// List Child
struct listChild {
    adrChild first;
    adrChild last;
};

// Node Parent (Induk)
struct nodeParent {
    golonganHewan info;
    adrParent next;
    adrParent prev;
    listChild L_Child;
};

// List Parent
struct listParent {
    adrParent first;
    adrParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void insertLastParent(listParent &L, adrParent P);
void insertLastChild(listChild &L, adrChild P);

// --- Fungsi Khusus Soal 3 (Delete & Print) ---
void deleteParent(listParent &L, string idGol); // Menghapus Parent beserta anaknya
void printMLLStructure(listParent L);           // Menampilkan output sesuai format

#endif
```

#### mll.cpp
```C++
/* File: mll.cpp */
#include "mll.h"

// --- Create List ---
void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
}

// --- Alokasi Node ---
adrParent allocNodeParent(string idGol, string namaGol) {
    adrParent P = new nodeParent;
    P->info.idGolongan = idGol;
    P->info.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

adrChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    adrChild P = new nodeChild;
    P->info.idHewan = idHwn;
    P->info.namaHewan = namaHwn;
    P->info.habitat = habitat;
    P->info.ekor = tail;
    P->info.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// --- Insert Last ---
void insertLastParent(listParent &L, adrParent P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertLastChild(listChild &L, adrChild P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// --- DELETE PARENT & CHILD (Inti Soal 3) ---
void deleteListChild(listChild &L) {
    adrChild P = L.first;
    while (P != NULL) {
        adrChild temp = P;
        P = P->next;
        delete temp; // Hapus node anak dari memori
    }
    L.first = NULL;
    L.last = NULL;
}

void deleteParent(listParent &L, string idGol) {
    adrParent P = L.first;
    // Mencari parent berdasarkan ID
    while (P != NULL && P->info.idGolongan != idGol) {
        P = P->next;
    }

    if (P != NULL) {
        // 1. Hapus semua anak dari parent ini terlebih dahulu
        deleteListChild(P->L_Child);

        // 2. Hapus node Parent dari list
        if (P == L.first && P == L.last) { // Satu-satunya elemen
            L.first = NULL;
            L.last = NULL;
        } else if (P == L.first) { // Elemen pertama
            L.first = P->next;
            L.first->prev = NULL;
        } else if (P == L.last) { // Elemen terakhir
            L.last = P->prev;
            L.last->next = NULL;
        } else { // Di tengah
            P->prev->next = P->next;
            P->next->prev = P->prev;
        }
        delete P; // Dealokasi memori parent
    }
}

// --- Print Sesuai Output Soal ---
void printMLLStructure(listParent L) {
    adrParent P = L.first;
    int i = 1;

    while (P != NULL) {
        cout << "Parent " << i << endl;
        cout << "ID Golongan : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;

        if (P->L_Child.first == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            adrChild C = P->L_Child.first;
            int j = 1;
            while (C != NULL) {
                cout << "- Child " << j << ":" << endl;
                cout << "  ID Hewan : " << C->info.idHewan << endl;
                cout << "  Nama Hewan : " << C->info.namaHewan << endl;
                cout << "  Habitat : " << C->info.habitat << endl;
                cout << "  Ekor : " << C->info.ekor << endl;
                cout << "  Bobot : " << C->info.bobot << endl;
                C = C->next;
                j++;
            }
        }
        // Jarak antar parent jika perlu, di soal outputnya rapat tapi parent baru di baris baru
        // Kita beri enteryang wajar
        if (P->next != NULL) cout << endl; 
        
        P = P->next;
        i++;
    }
    cout << endl;
}
```
#### main.cpp
```C++
#include "mll.h"

int main() {
    listParent LP;
    createListParent(LP);

    // Parent 1: Aves
    adrParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);
    insertLastChild(P1->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(P1->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0));

    // Parent 2: Mamalia
    adrParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);
    insertLastChild(P2->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0));
    insertLastChild(P2->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0));
    insertLastChild(P2->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0));

    // Parent 3: Pisces
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));

    // Parent 4: Amfibi (Ini yang akan dihapus)
    adrParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);
    insertLastChild(P4->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    // Parent 5: Reptil
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    // 3. Operasi DELETE Soal No 3
    // Menghapus node G004 (Amfibi)
    deleteParent(LP, "G004");

    // 4. Menampilkan Output
    // Output diharapkan: Aves, Mamalia, Pisces, Reptil (Amfibi hilang)
    printMLLStructure(LP);

    return 0;
}
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan11/OUTPUT/Unguided3.png)

#### Penjelasan

Unguided 3 menitikberatkan pada operasi manipulasi data destruktif, yaitu menghapus sebuah node parent tertentu (dalam kasus ini, golongan "Amfibi" dengan ID "G004") dari rangkaian Multi Linked List. Fungsi deleteParent dirancang untuk menangani integritas memori; sebelum node parent dihapus, fungsi secara otomatis memanggil deleteListChild untuk menghapus dan men-dealokasi semua node anak (hewan) yang berada di bawah naungan parent tersebut. Setelah list anak kosong, barulah pointer next dan prev dari node parent tetangga diperbarui untuk memutus rantai node target, dan memori parent tersebut dibebaskan menggunakan perintah delete. Hal ini memastikan struktur list tetap tersambung dengan benar (Aves -> Mamalia -> Pisces -> Reptil) tanpa meninggalkan data sampah di memori.

## Kesimpulan

Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa Multi Linked List (MLL) adalah struktur data yang sangat efektif untuk merepresentasikan data yang memiliki hubungan hierarkis one-to-many. Implementasi menggunakan Linked List of Linked List (Parent dan Child berupa list dinamis) memberikan fleksibilitas tinggi dalam penambahan dan pengurangan data tanpa batasan ukuran array statis. Pemahaman mendalam mengenai manajemen pointer sangat diperlukan, terutama dalam operasi manipulasi seperti penghapusan (deletion), di mana penghapusan Parent wajib didahului oleh penghapusan seluruh Child-nya untuk menjaga integritas memori. Meskipun implementasinya lebih kompleks dibandingkan linked list tunggal karena melibatkan nested traversal, MLL menawarkan pengelompokan data yang lebih logis dan terstruktur.

## Referensi

[1] R. Sedgewick and K. Wayne, Algorithms, 4th ed. Upper Saddle River, NJ: Addison-Wesley, 2011.
<br>[2] A. Drozdek, Data Structures and Algorithms in C++, 4th ed. Boston, MA: Cengage Learning, 2013.
<br>[3] M. T. Goodrich, R. Tamassia, and D. M. Mount, Data Structures and Algorithms in C++, 2nd ed. New York: John Wiley & Sons, 2011.
<br>[4] B. Stroustrup, The C++ Programming Language, 4th ed. Upper Saddle River, NJ: Addison-Wesley, 2013.
<br>[5] GeeksforGeeks, "Multi-level Linked List Implementation," GeeksforGeeks, 2023. [Online]. Available: https://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/. [Accessed: 07-Dec-2025].
