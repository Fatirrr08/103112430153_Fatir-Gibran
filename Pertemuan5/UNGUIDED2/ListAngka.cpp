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
