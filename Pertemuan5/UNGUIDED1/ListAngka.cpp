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
