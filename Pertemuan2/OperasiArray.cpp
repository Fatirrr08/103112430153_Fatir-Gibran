#include <iostream>

using namespace std;

void tampilkanArray(int arr[], int ukuran) {
    cout << "Isi Array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int cariMaksimum(int arr[], int ukuran) {
    int maks = arr[0]; 
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

int cariMinimum(int arr[], int ukuran) {
    int min = arr[0]; 
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungRataRata(int arr[], int ukuran) {
    float total = 0;
    for (int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    float rata_rata = total / ukuran;
    cout << "Nilai Rata-rata: " << rata_rata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    const int ukuran = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray(arrA, ukuran);
                break;
            case 2:
                cout << "Nilai Maksimum: " << cariMaksimum(arrA, ukuran) << endl;
                break;
            case 3:
                cout << "Nilai Minimum: " << cariMinimum(arrA, ukuran) << endl;
                break;
            case 4:
                hitungRataRata(arrA, ukuran);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}