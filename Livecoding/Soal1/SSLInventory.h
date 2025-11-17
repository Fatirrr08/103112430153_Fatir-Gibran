#ifndef SINGLELIST_H
#define SINGELIST_H
#define Nill NULL
#include <iostream>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

typedef Product dataProduct;

typedef struct node *address;

struct node {
    dataProduct info;
    address next;
};

struct List {
    address first;
};

bool isEmpty(List List);
void createList(List &List);
address allocate(string nama, string sku, int jumlah, float hargaSatuan, float DiskonPersen);
void deallocate(address &node);
void printlist(List List);
void insertFirst(List &List, address nodeBaru);
void insertAfter(List &List, address nodeBaru, address Prev);
void insertLast(List &List, address nodeBaru); //Q adalah node setelah mana insert
void deleteFirst(List &List, address &nodeHapus);
void deleteAfter(List &List, address &nodeHapus, address Prev);
void deleteLast(List &List, address &nodeHapus);
void updateAtPosition(List &List, int posisi, dataProduct dataBaru);
void viewList(List List);
void searchByFinalPriceRange(List List, float minPrice, float maxPrice);
void MAXHargaAkhir(List List); //bagian b

#endif