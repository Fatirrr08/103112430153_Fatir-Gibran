#include "SSLInventory.h"
#include <iostream>
using namespace std;

bool isEmpty(List List) {
    if(List.first == Nill) {
        return true;
    } else {
        return false;
    }
}

void createList(List &List) {
    List.first = Nill;
}

address allocate(string nama, string sku, int jumlah, float hargaSatuan, float DiskonPersen) {
    address nodeBaru = new node;
    nodeBaru->info.Nama = nama;
    nodeBaru->info.SKU = sku;
    nodeBaru->info.Jumlah = jumlah;
    nodeBaru->info.HargaSatuan = hargaSatuan;
    nodeBaru->info.DiskonPersen = DiskonPersen;
    nodeBaru->next = Nill;
    return nodeBaru;
}

void deallocate(address &node) {
    node->next = Nill;
    delete node;
}

void insertFirst(List &List, address nodeBaru) {
    if(isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first = nodeBaru;
    }
}

void insertAfter(List &List, address nodeBaru, address Prev) {
    if (Prev != Nill) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(List &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address last = List.first;
        while (last->next != Nill) {
            last = last->next;
        }
        last->next = nodeBaru;
    }
}

void deleteFirst(List &List, address &nodeHapus) {
    if (!isEmpty(List)) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nill;
    } else {
        nodeHapus = Nill;
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }
}

void deleteAfter(List &List, address &nodeHapus, address Prev) {
    if (Prev != Nill && Prev->next != Nill) {
        nodeHapus = Prev->next;
        Prev->next = nodeHapus->next;
        nodeHapus->next = Nill;
    } else {
        nodeHapus = Nill;
        cout << "Node sebelumnya tidak valid atau tidak ada node setelahnya." << endl;
    }
}

void deleteLast(List &List, address &nodeHapus) {
    if (!isEmpty(List)) {
        if (List.first->next == Nill) {
            nodeHapus = List.first;
            List.first = Nill;
        } else {
            address prev = Nill;
            address curr = List.first;
            while (curr->next != Nill) {
                prev = curr;
                curr = curr->next;
            }
            nodeHapus = curr;
            prev->next = Nill;
        }
    } else {
        nodeHapus = Nill;
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }
}

void updateAtPosition(List &List, int posisi, dataProduct dataBaru) {
    if (!isEmpty(List)) {
        address curr = List.first;
        int index = 0;
        while (curr != Nill && index < posisi) {
            curr = curr->next;
            index++;
        }
        if (curr != Nill) {
            curr->info = dataBaru;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void viewList(List List) {
    if (!isEmpty(List)) {
        address curr = List.first;
        int index = 0;
        while (curr != Nill) {
            cout << "Produk ke-" << index + 1 << ":" << endl;
            cout << "Nama: " << curr->info.Nama << endl;
            cout << "SKU: " << curr->info.SKU << endl;
            cout << "Jumlah: " << curr->info.Jumlah << endl;
            cout << "Harga Satuan: " << curr->info.HargaSatuan << endl;
            cout << "Diskon Persen: " << curr->info.DiskonPersen << "%" << endl;
            cout << "------------------------" << endl;
            curr = curr->next;
            index++;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void searchByFinalPriceRange(List List, float minPrice, float maxPrice) {
    if (!isEmpty(List)) {
        address curr = List.first;
        bool found = false;
        while (curr != Nill) {
            float finalPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);
            if (finalPrice >= minPrice && finalPrice <= maxPrice) {
                cout << "Produk ditemukan dalam rentang harga:" << endl;
                cout << "Nama: " << curr->info.Nama << endl;
                cout << "SKU: " << curr->info.SKU << endl;
                cout << "Jumlah: " << curr->info.Jumlah << endl;
                cout << "Harga Satuan: " << curr->info.HargaSatuan << endl;
                cout << "Diskon Persen: " << curr->info.DiskonPersen << "%" << endl;
                cout << "Harga Akhir: " << finalPrice << endl;
                cout << "------------------------" << endl;
                found = true;
            }
            curr = curr->next;
        }
        if (!found) {
            cout << "Tidak ada produk dalam rentang harga yang ditentukan." << endl;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

// Bagian b
void MAXHargaAkhir(List List) {
    if (!isEmpty(List)) {
        address curr = List.first;
        address maxNode = curr;
        float maxPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);
        curr = curr->next;
        while (curr != Nill) {
            float finalPrice = curr->info.HargaSatuan * (1 - curr->info.DiskonPersen / 100);
            if (finalPrice > maxPrice) {
                maxPrice = finalPrice;
                maxNode = curr;
            }
            curr = curr->next;
        }
        cout << "Produk dengan harga akhir tertinggi:" << endl;
        cout << "Nama: " << maxNode->info.Nama << endl;
        cout << "SKU: " << maxNode->info.SKU << endl;
        cout << "Jumlah: " << maxNode->info.Jumlah << endl;
        cout << "Harga Satuan: " << maxNode->info.HargaSatuan << endl;
        cout << "Diskon Persen: " << maxNode->info.DiskonPersen << "%" << endl;
        cout << "Harga Akhir: " << maxPrice << endl;
    } else {
        cout << "List kosong." << endl;
    }
}