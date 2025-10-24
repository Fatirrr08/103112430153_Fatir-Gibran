#include <iostream>
#include <cstdlib> // Diperlukan untuk fungsi rand() dan srand()
#include <ctime>   // Diperlukan untuk fungsi time()

int main() {
    // 1. Inisialisasi generator angka acak
    // Menggunakan waktu saat ini sebagai "seed" agar angka yang dihasilkan selalu berbeda
    srand(time(0));

    // 2. Hasilkan angka acak antara 1 dan 100
    int angkaRahasia = rand() % 100 + 1;
    int tebakanPengguna = 0;
    int jumlahTebakan = 0;

    // 3. Sambutan dan instruksi
    std::cout << "======================================" << std::endl;
    std::cout << " Selamat Datang di Game Tebak Angka! " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Saya telah memilih sebuah angka antara 1 dan 100." << std::endl;
    std::cout << "Coba tebak angka tersebut!" << std::endl;

    // 4. Mulai loop permainan
    do {
        std::cout << "\nMasukkan tebakan Anda: ";
        std::cin >> tebakanPengguna;
        jumlahTebakan++; // Tambah jumlah tebakan setiap kali user memasukkan angka

        // 5. Periksa tebakan pengguna
        if (tebakanPengguna > angkaRahasia) {
            std::cout << "Tebakan Anda terlalu TINGGI! Coba lagi." << std::endl;
        } else if (tebakanPengguna < angkaRahasia) {
            std::cout << "Tebakan Anda terlalu RENDAH! Coba lagi." << std::endl;
        } else {
            std::cout << "\n*********************************************" << std::endl;
            std::cout << "Selamat! Anda berhasil menebak angkanya!" << std::endl;
            std::cout << "Angka rahasianya adalah: " << angkaRahasia << std::endl;
            std::cout << "Anda memerlukan " << jumlahTebakan << " kali tebakan." << std::endl;
            std::cout << "*********************************************" << std::endl;
        }
    } while (tebakanPengguna != angkaRahasia);

    return 0;
}