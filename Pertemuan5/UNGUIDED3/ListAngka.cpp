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
