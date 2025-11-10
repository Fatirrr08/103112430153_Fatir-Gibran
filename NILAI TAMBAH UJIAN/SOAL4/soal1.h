#pragma once
#include <string>

// Struct untuk data
struct infotype_doc {
    std::string namaDok;
    std::string namaPengguna;
    int hal;
};

// Struct untuk node
struct elmQ {
    infotype_doc info;
    elmQ* next;
};

typedef elmQ* address_queue;

// Class untuk Queue
class PrinterQueue {
public:
    PrinterQueue();  // Constructor
    ~PrinterQueue(); // Destructor (PENTING)

    bool is_empty() const;

    // Soal 4a: Prosedur enqueue
    void enqueue(address_queue p);
    // Soal 4b: Prosedur dequeue (return bool)
    bool dequeue(address_queue &p);
    
    // Soal 4c: Prosedur antriPrinter
    void antriPrinter(infotype_doc doc);
    // Soal 4d: Prosedur simulasiCetak
    void simulasiCetak(int kertas);

private:
    address_queue head;
    address_queue tail;
    
    // Helper function dijadikan private
    address_queue createNewElm_queue(infotype_doc x);
};