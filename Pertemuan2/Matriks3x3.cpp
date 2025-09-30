#include <iostream>

const int matriks3 = 3;

int main() {
    int matriksA[matriks3][matriks3];
    int matriksB[matriks3][matriks3];
    int hasil[matriks3][matriks3];

    std::cout << "=== Kalkulator Matriks 3 " << matriks3 << "x" << matriks3 << " ===" << std::endl;

    std::cout << "\n--- Masukkan Matriks A ---" << std::endl;
    for (int i = 0; i < matriks3; i++) {
        for (int j = 0; j < matriks3; j++) {
            std::cout << "  Elemen [" << i << "][" << j << "]: ";
            std::cin >> matriksA[i][j];
        }
    }

    std::cout << "\n--- Masukkan Matriks B ---" << std::endl;
    for (int i = 0; i < matriks3; i++) {
        for (int j = 0; j < matriks3; j++) {
            std::cout << "  Elemen [" << i << "][" << j << "]: ";
            std::cin >> matriksB[i][j];
        }
    }

    std::cout << "\n--- Hasil Penjumlahan (A + B) ---" << std::endl;
    for (int i = 0; i < matriks3; i++) {
        for (int j = 0; j < matriks3; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
            std::cout << hasil[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\n--- Hasil Pengurangan (A - B) ---" << std::endl;
    for (int i = 0; i < matriks3; i++) {
        for (int j = 0; j < matriks3; j++) {
            hasil[i][j] = matriksA[i][j] - matriksB[i][j];
            std::cout << hasil[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\n--- Hasil Perkalian (A * B) ---" << std::endl;
    for (int i = 0; i < matriks3; i++) {
        for (int j = 0; j < matriks3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < matriks3; k++) {
                hasil[i][j] += matriksA[i][k] * matriksB[k][j];
            }
            std::cout << hasil[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}