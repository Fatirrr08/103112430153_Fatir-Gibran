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
