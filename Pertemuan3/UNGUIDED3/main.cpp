#include <iostream>
#include "array_utils.h"

int main() {
    int arrayA[3][3];
    int arrayB[3][3];

    std::cout << "--- Input untuk Array A ---" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Masukkan elemen A[" << i << "][" << j << "]: ";
            std::cin >> arrayA[i][j];
        }
    }

    std::cout << "\n--- Input untuk Array B ---" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "Masukkan elemen B[" << i << "][" << j << "]: ";
            std::cin >> arrayB[i][j];
        }
    }
    
    int nilai1, nilai2;
    std::cout << "\n--- Input untuk Pointer ---" << std::endl;
    std::cout << "Masukkan nilai pertama: ";
    std::cin >> nilai1;
    std::cout << "Masukkan nilai kedua: ";
    std::cin >> nilai2;

    int* pointerA = &nilai1;
    int* pointerB = &nilai2;

    std::cout << "\n======================================\n" << std::endl;

    std::cout << "--- KONDISI AWAL ARRAY ---" << std::endl;
    std::cout << "Isi Array A:" << std::endl;
    tampilkanArray(arrayA);
    std::cout << "\nIsi Array B:" << std::endl;
    tampilkanArray(arrayB);

    tukarElemenArray(arrayA, arrayB, 1, 1);
    
    std::cout << "\n--- SETELAH ELEMEN [1][1] DITUKAR ---" << std::endl;
    std::cout << "Isi Array A:" << std::endl;
    tampilkanArray(arrayA);
    std::cout << "\nIsi Array B:" << std::endl;
    tampilkanArray(arrayB);

    std::cout << "\n======================================\n" << std::endl;

    std::cout << "--- KONDISI AWAL POINTER ---" << std::endl;
    std::cout << "Nilai yang ditunjuk pointerA (nilai1): " << *pointerA << std::endl;
    std::cout << "Nilai yang ditunjuk pointerB (nilai2): " << *pointerB << std::endl;

    tukarViaPointer(pointerA, pointerB);

    std::cout << "\n--- SETELAH NILAI POINTER DITUKAR ---" << std::endl;
    std::cout << "Nilai yang ditunjuk pointerA (nilai1): " << *pointerA << std::endl;
    std::cout << "Nilai yang ditunjuk pointerB (nilai2): " << *pointerB << std::endl;

    return 0;
}
