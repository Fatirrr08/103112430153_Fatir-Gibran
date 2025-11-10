#include <iostream>
#include "Soal1.h" // Hanya include Soal 4

int main() {
    std::cout << "========================================\n";
    std::cout << "PENGUJIAN SOAL 4: Queue Antrian Printer\n";
    std::cout << "========================================\n";

    // Blok untuk tes skenario 1
    {
        std::cout << "--- Tes Skenario 1 (Kertas = 50) ---\n";
        PrinterQueue Q_sim1; // Constructor
        Q_sim1.antriPrinter({"Surat Tugas", "Ayu", 10});
        Q_sim1.antriPrinter({"Undangan", "Sasa", 3});
        Q_sim1.antriPrinter({"Notula Rapat", "Ayu", 15});
        Q_sim1.antriPrinter({"Pedoman KPI", "Ayu", 85});
        Q_sim1.antriPrinter({"Presensi", "Nia", 24});
        
        std::cout << "\nTes (4c) Uji Batas Maksimal 3 Dokumen:\n";
        Q_sim1.antriPrinter({"Laporan Bulanan", "Ayu", 5}); 

        Q_sim1.simulasiCetak(50);
        // Destructor Q_sim1 dipanggil
    }

    // Blok untuk tes skenario 2
    {
        std::cout << "\n--- Tes Skenario 2 (Kertas = 150) ---\n";
        PrinterQueue Q_sim2; // Constructor
        Q_sim2.antriPrinter({"Surat Tugas", "Ayu", 10});
        Q_sim2.antriPrinter({"Undangan", "Sasa", 3});
        Q_sim2.antriPrinter({"Notula Rapat", "Ayu", 15});
        Q_sim2.antriPrinter({"Pedoman KPI", "Ayu", 85});
        Q_sim2.antriPrinter({"Presensi", "Nia", 24});

        Q_sim2.simulasiCetak(150);
        // Destructor Q_sim2 dipanggil
    }

    return 0;
}