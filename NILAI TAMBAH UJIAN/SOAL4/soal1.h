#pragma once
#include <string>

struct infotype_doc {
    std::string namaDok;
    std::string namaPengguna;
    int hal;
};

struct elmQ {
    infotype_doc info;
    elmQ* next;
};

typedef elmQ* address_queue;

class PrinterQueue {
public:
    PrinterQueue();  // Constructor
    ~PrinterQueue(); // Destructor (PENTING)

    bool is_empty() const;

    void enqueue(address_queue p);
    bool dequeue(address_queue &p);
    
    void antriPrinter(infotype_doc doc);
    void simulasiCetak(int kertas);

private:
    address_queue head;
    address_queue tail;
    
    address_queue createNewElm_queue(infotype_doc x);
};