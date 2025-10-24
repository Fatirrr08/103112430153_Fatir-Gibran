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