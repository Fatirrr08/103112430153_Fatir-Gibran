#include "soal1.h"
#include <iostream>

// Constructor
PrinterQueue::PrinterQueue() : head(nullptr), tail(nullptr) {}

// Destructor: Membersihkan semua node
PrinterQueue::~PrinterQueue() {
    address_queue P = head;
    while (P != nullptr) {
        address_queue temp = P;
        P = P->next;
        delete temp;
    }
}

bool PrinterQueue::is_empty() const {
    return head == nullptr;
}

// Helper private
address_queue PrinterQueue::createNewElm_queue(infotype_doc x) {
    address_queue P = new elmQ;
    P->info = x;
    P->next = nullptr;
    return P;
}

// Soal 4a
void PrinterQueue::enqueue(address_queue p) {
    if (is_empty()) {
        head = p;
        tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

// Soal 4b
bool PrinterQueue::dequeue(address_queue &p) {
    if (is_empty()) {
        p = nullptr;
        return false; // Gagal
    }
    
    p = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    p->next = nullptr;
    return true; // Sukses
}

// Soal 4c
void PrinterQueue::antriPrinter(infotype_doc doc) {
    int count = 0;
    address_queue P_cek = head;
    while (P_cek != nullptr) {
        if (P_cek->info.namaPengguna == doc.namaPengguna) {
            count++;
        }
        P_cek = P_cek->next;
    }

    if (count < 3) {
        address_queue P_new = createNewElm_queue(doc);
        enqueue(P_new);
        std::cout << "AntriPrinter: Dokumen '" << doc.namaDok << "' oleh " << doc.namaPengguna << " BERHASIL ditambahkan.\n";
    } else {
        std::cout << "AntriPrinter: Dokumen '" << doc.namaDok << "' oleh " << doc.namaPengguna << " GAGAL (sudah punya " << count << " antrian).\n";
    }
}

// Soal 4d
void PrinterQueue::simulasiCetak(int kertas) {
    std::cout << "\nMemulai Simulasi Cetak dengan Kertas = " << kertas << " lembar.\n";

    while (!is_empty() && kertas >= head->info.hal) {
        address_queue P_cetak;
        
        dequeue(P_cetak);
        
        kertas -= P_cetak->info.hal;

        std::cout << "  > Mencetak: [" << P_cetak->info.namaDok
                  << "-" << P_cetak->info.namaPengguna
                  << "-" << P_cetak->info.hal
                  << "] | Sisa Kertas: " << kertas << "\n";
        
        delete P_cetak; // Dealokasi memori
    }

    if (is_empty()) {
        std::cout << "Simulasi Selesai: Semua dokumen berhasil dicetak.\n";
    } else {
        std::cout << "Simulasi Selesai: Kertas (" << kertas << ") tidak cukup untuk ["
                  << head->info.namaDok << "-" << head->info.namaPengguna
                  << "-" << head->info.hal << "].\n";
    }
}