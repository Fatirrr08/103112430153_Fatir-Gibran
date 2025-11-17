#include "SSLInventory.h"

int main(){
    List L;
    createList(L);

    Product prod1 = {"Pulpen", "A001", 20, 2500.0, 0.0};
    Product prod2 = {"BukuTulis", "A002", 15, 5000.0, 10.0};
    Product prod3 = {"Penghapus", "A003", 30, 1580.0, 0.0};

    address P1 = allocate(prod1.Nama, prod1.SKU, prod1.Jumlah, prod1.HargaSatuan, prod1.DiskonPersen);
    address P2 = allocate(prod2.Nama, prod2.SKU, prod2.Jumlah, prod2.HargaSatuan, prod2.DiskonPersen);
    address P3 = allocate(prod3.Nama, prod3.SKU, prod3.Jumlah, prod3.HargaSatuan, prod3.DiskonPersen);

    insertLast(L, P1);
    insertLast(L, P2);
    insertLast(L, P3);

    cout << "Viewing all products in the list:\n";
    viewList(L);

    cout << "\nSearching for products with final price of 7000.0:\n";
    searchByFinalPriceRange(L, 2000.0, 7000.0);

    cout << "\nUpdating position of the second product:\n";
    updateAtPosition(L, 1, {"Stabilo", "A010", 40, 9000, 5.0});
    viewList(L);

    //bagian b
    cout << "\nFinding product with maximum final price:\n";
    MAXHargaAkhir(L);
    return 0;
}