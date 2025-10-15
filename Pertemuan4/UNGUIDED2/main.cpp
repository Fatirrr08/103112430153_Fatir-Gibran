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
