# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

### A. Matriks dan Operasinya

Matriks adalah sekumpulan bilangan yang disusun secara teratur dalam baris dan kolom, digunakan secara luas dalam bidang matematika dan ilmu komputer untuk merepresentasikan data multidimensi, transformasi linear, serta operasi numerik. Operasi dasar pada matriks meliputi penjumlahan, pengurangan, dan perkalian.

Penjumlahan dan pengurangan matriks hanya dapat dilakukan apabila kedua matriks memiliki ordo yang sama, sedangkan perkalian matriks dilakukan dengan mengalikan baris dari matriks pertama dengan kolom dari matriks kedua.

Dalam pemrograman, matriks direpresentasikan dengan array dua dimensi. Setiap operasi dilakukan dengan menggunakan perulangan bersarang (nested loop) untuk mengakses elemen-elemen matriks berdasarkan indeks baris dan kolomnya. Kompleksitas waktu operasi dasar matriks umumnya adalah:

<br>Penjumlahan/Pengurangan: O(n²)
<br>Perkalian (klasik): O(n³)

Meskipun demikian, untuk ukuran kecil seperti 3x3, kompleksitas tidak menjadi masalah, namun pada skala besar diperlukan algoritma lebih efisien seperti Strassen Algorithm atau metode paralel. Matriks juga digunakan dalam berbagai aplikasi seperti grafika komputer, sistem persamaan linear, analisis data, hingga machine learning.

### B. Pointer dan Reference dalam C++

Dalam bahasa pemrograman C++, terdapat dua cara utama untuk memanipulasi nilai variabel melalui fungsi: pointer dan reference.

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat mengakses dan memodifikasi nilai dari lokasi memori tertentu menggunakan operator dereferensi (*). Pointer juga memungkinkan penggunaan dinamis memori, namun memiliki risiko seperti null pointer, dangling pointer, dan kesalahan dereferensi.

Reference adalah alias dari variabel lain, yang harus diinisialisasi saat deklarasi dan tidak dapat diubah untuk merujuk ke variabel lain. Reference memberikan cara yang lebih aman dan sederhana untuk mengakses nilai variabel dari luar fungsi tanpa risiko kesalahan memori seperti pointer.

Dalam konteks praktikum ini, pointer dan reference digunakan untuk menukar nilai tiga variabel melalui fungsi, menunjukkan konsep pass-by-pointer dan pass-by-reference.

### C. Pencarian Nilai Maksimum, Minimum, dan Rata-rata dalam Array

Array adalah struktur data statis yang menyimpan sekumpulan elemen dengan tipe data yang sama dan diakses menggunakan indeks. Untuk menemukan nilai maksimum dan minimum, dilakukan traversal dari elemen pertama hingga terakhir dan membandingkannya satu per satu.

Kompleksitas waktu untuk pencarian ini adalah O(n). Terdapat juga algoritma yang mengurangi jumlah perbandingan seperti pair method dan tournament method.
Untuk menghitung rata-rata, dilakukan penjumlahan seluruh elemen lalu dibagi dengan jumlah elemen array. Karena semua operasi dilakukan dengan satu loop, total kompleksitas tetap O(n).

Pada implementasi praktikum, digunakan tiga fungsi terpisah:
<br>cariMaksimum() untuk mencari nilai tertinggi
<br>cariMinimum() untuk mencari nilai terendah
<br>hitungRataRata() untuk menghitung rata-rata

Ketiganya dipanggil melalui menu menggunakan switch-case untuk mendemonstrasikan modularitas dan konsep function dalam pemrograman.

### C. Struktur Program Modular dan Penggunaan Fungsi

Dalam pemrograman terstruktur, program yang baik sebaiknya dibagi menjadi beberapa bagian kecil yang disebut fungsi atau prosedur.
Fungsi digunakan untuk mengembalikan nilai (misal int cariMaksimum()), sedangkan prosedur digunakan untuk proses tanpa nilai balik (misal void hitungRataRata()).
Pendekatan modular ini meningkatkan reusabilitas, readability, dan maintainability program.

### D. Pointer dan Reference dalam C++

#### 1. Pointer

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat mengakses atau memodifikasi data di lokasi memori tertentu menggunakan operator dereferensi *.
Kelebihan penggunaan pointer:

<br>Memungkinkan manipulasi data secara langsung.
<br>Digunakan dalam struktur data dinamis (seperti linked list).
<br>Memungkinkan komunikasi antar fungsi melalui alamat memori (pass-by-pointer).

Namun, pointer juga memiliki risiko seperti null pointer, dangling pointer, dan segmentation fault apabila digunakan tanpa hati-hati.

#### 2. Reference

Reference adalah alias dari variabel lain. Setelah diinisialisasi, reference selalu menunjuk ke variabel yang sama dan tidak bisa diubah untuk merujuk ke variabel lain. Reference digunakan untuk:

<br>Pass-by-reference ke fungsi (tanpa menyalin nilai).
<br>Membuat kode lebih aman dan lebih mudah dibaca dibanding pointer.

Dalam konteks praktikum, keduanya digunakan untuk menukar nilai tiga variabel melalui dua pendekatan berbeda: tukar dengan pointer dan tukar dengan reference.

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[10] ;
    
    for (int i = 0; i < 10; i++) {
        cout << "Masukkan value index ke- " << i << ": " ;
        cin >> arr[i];
    }
    int j=0;
    while (j<10) {
        cout << "isi index ke- " << j << ": " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
##### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Guided1.png)

### Penjelasan

Program ini mendemonstrasikan penggunaan dasar array satu dimensi di C++. Pertama, sebuah array integer bernama arr dengan kapasitas 10 elemen dideklarasikan. Kemudian, program menggunakan perulangan for untuk meminta pengguna memasukkan 10 nilai, yang masing-masing disimpan ke dalam elemen array dari indeks 0 hingga 9. Setelah semua data terisi, program menggunakan perulangan while untuk menampilkan kembali setiap nilai yang telah disimpan dalam array ke layar, sesuai dengan urutan indeksnya.

### 2. Array 2 Dimensi"

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
##### Output Guided 2

![Screenshot Output guided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Guided2.png)

### Penjelasan

Program ini menunjukkan operasi penjumlahan dan perkalian matriks menggunakan array dua dimensi berordo 2x2. Dua matriks, arrA dan arrB, diinisialisasi dengan nilai. Untuk penjumlahan, program menggunakan perulangan bersarang untuk menjumlahkan setiap elemen yang bersesuaian dari arrA dan arrB, lalu menyimpannya di arrC. Untuk perkalian, digunakan tiga perulangan bersarang sesuai aturan perkalian matriks, di mana hasil perkalian baris arrA dengan kolom arrB diakumulasikan ke arrD. Terdapat fungsi tampilkanHasil yang dipanggil untuk mencetak matriks hasil ke layar agar kode lebih rapi dan tidak berulang.

### 3. Pointer

```C++
#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int *ptr;
    ptr = &a;
    
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored int ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a, &b);
    cout << "After Swaping, Value of a= " << a << " and b=" << b << endl;
    return 0;
}
```
##### Output Guided 3

![Screenshot Output guided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Guided3.png)

### Penjelasan

Program ini menjelaskan konsep pointer di C++. Sebuah variabel pointer ptr dideklarasikan dan diinisialisasi untuk menyimpan alamat memori dari variabel a (menggunakan operator &). Program kemudian menampilkan nilai a, alamat memori a, isi dari ptr (yang merupakan alamat a), dan nilai yang ditunjuk oleh ptr (menggunakan operator dereferensi *). Selanjutnya, fungsi Tukar dipanggil dengan mengirimkan alamat dari variabel a dan b. Di dalam fungsi Tukar, nilai-nilai pada alamat tersebut ditukar menggunakan variabel sementara temp, yang membuktikan bahwa fungsi dapat mengubah nilai variabel asli di main melalui pointer (pass-by-pointer).

### 4. Reference

```C++
#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int& ref = a;

    cout << "Nilai of a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref (Alias to a): " << ref << endl;
    cout << "Alamat ref (&raf): " << &ref << endl;

    ref = 30;
    cout << "\nSetelah ref = 50: " << a << endl;
    cout << "Nilai a: " << &a << endl;
    cout << "Nilai ref: " << ref << endl;

    Tukar(&a, &b);
    cout << "Setelah Tukar, Nilai a= " << a << " dan b=" << b << endl;
    return 0;
}
```
##### Output Guided 4

![Screenshot Output guided 4](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Guided4.png)

### Penjelasan

Program ini mendemonstrasikan konsep reference sebagai alias atau nama lain untuk sebuah variabel. Sebuah reference ref dideklarasikan dan diinisialisasi ke variabel a. Program menunjukkan bahwa a dan ref memiliki nilai dan alamat memori yang sama persis. Ketika nilai ref diubah menjadi 50, nilai a juga ikut berubah. Ini membuktikan bahwa reference terikat langsung ke variabel aslinya. Selanjutnya, fungsi Tukar yang menerima parameter sebagai reference (pass-by-reference) dipanggil. Karena fungsi bekerja pada reference, ia dapat menukar nilai variabel a dan b secara langsung tanpa perlu menggunakan pointer.

### 5. Function Procedure

``` C++
    #include <iostream>
    using namespace std;

    int cariMax(int arr[], int ukuran) {
        int max = arr[0];
        for (int i = 1; i < ukuran; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    void OperasiAritmatika(int arr[],int ukuran){
        int totaljumlah = 0;
        for(int i = 0; i < ukuran; i++){
            totaljumlah += arr[i];
        }
        cout << "Total perjumlah: " << totaljumlah << endl;

        int totalKali = 1;
        for(int i = 0; i < ukuran; i++){
            totalKali *= arr[i];
        }
        cout << "Total perkalian: " << totalKali << endl;
    }
        int main() {
            const int ukuran = 5;
            int arr[ukuran];
            for (int i = 0; i < ukuran; i++) {
            cout << "Masukkan Nilai Array ke-" << i << ": ";
            cin >> arr[i];    
            }
            cout << endl;
            cout << "Nilai Maksimum: " << cariMax(arr, ukuran) << endl;
        
            OperasiAritmatika(arr, ukuran);
            return 0;
        }
```

##### Output Guided 5

![Screenshot Output guided 5](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Guided4.png)

### Penjelasan

Program ini menunjukkan konsep program modular dengan memisahkan tugas ke dalam fungsi dan prosedur.

Fungsi cariMax: Bertipe int, berfungsi mencari nilai maksimum dalam array dan mengembalikan (return) nilai tersebut.
Prosedur OperasiAritmatika: Bertipe void, bertugas menghitung total penjumlahan dan perkalian semua elemen array, lalu langsung menampilkannya ke layar tanpa mengembalikan nilai.

Di dalam main, program meminta pengguna mengisi 5 elemen array, kemudian memanggil cariMax untuk mendapatkan dan menampilkan nilai tertinggi, serta memanggil OperasiAritmatika untuk melakukan perhitungan dan menampilkan hasilnya.

## Unguided 

### 1.Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3.

```C++
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
```
### Output Unguided 1 :

##### Output 

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Unguided1.png)

### Penjelasan

Program ini adalah kalkulator matriks 3x3 yang melakukan tiga operasi dasar secara berurutan. Pertama, program meminta pengguna untuk memasukkan 9 elemen untuk matriksA dan 9 elemen untuk matriksB melalui perulangan for bersarang. Setelah input selesai, program langsung mengeksekusi:
Penjumlahan: Menghitung matriksA[i][j] + matriksB[i][j] dan langsung mencetak hasilnya.
Pengurangan: Menghitung matriksA[i][j] - matriksB[i][j] dan mencetak hasilnya.
Perkalian: Menghitung perkalian matriks menggunakan tiga perulangan bersarang dan mencetak hasilnya.

Semua logika ditempatkan di dalam fungsi main untuk alur program yang sederhana dan linear. Penggunaan const int matriks3 = 3; membuat kode lebih mudah dibaca dan dimodifikasi jika ukuran matriks ingin diubah.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

#### Pointer
```C++
#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int *ptr;
    ptr = &a;
    
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored int ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a, &b);
    cout << "After Swaping, Value of a= " << a << " and b=" << b << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Unguided2a.png)

### Penjelasan
Program ini mendemonstrasikan cara menukar nilai tiga variabel (a, b, c) menggunakan pointer. Fungsi TukarTiga menerima tiga parameter berupa pointer integer (int *). Di dalam fungsi, nilai-nilai dari variabel asli di main diakses dan dimodifikasi menggunakan operator dereferensi *. Penukaran dilakukan secara siklik: nilai a pindah ke b, b ke c, dan c ke a dengan bantuan variabel temp. Saat memanggil fungsi dari main, kita mengirimkan alamat memori dari variabel a, b, dan c menggunakan operator &.

#### Pointer
```C++
#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int *ptr;
    ptr = &a;
    
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored int ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a, &b);
    cout << "After Swaping, Value of a= " << a << " and b=" << b << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Unguided2b.png)

### Penjelasan

Program ini melakukan tugas yang sama dengan sebelumnya, yaitu menukar nilai tiga variabel, tetapi kali ini menggunakan reference. Fungsi TukarTiga menerima tiga parameter reference (int &). Artinya, a, b, dan c di dalam fungsi adalah alias langsung dari variabel di main. Setiap perubahan yang dilakukan pada a, b, dan c di dalam fungsi akan langsung memengaruhi variabel aslinya. Saat memanggil fungsi, kita cukup mengirimkan variabelnya secara langsung, tanpa perlu operator & atau *, sehingga sintaksnya menjadi lebih bersih dan aman dibandingkan pointer.

### 3.  Buatlah program yang dapat memberikan input dan output sbb.
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Soal.png)

```C++
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
```
### Output Unguided 3 :

##### Output 

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan2/OUTPUT/Unguided3.png)

### Penjelasan

Program ini merupakan aplikasi analisis data sederhana pada sebuah array yang sudah ditentukan isinya. Program ini sangat modular, di mana setiap tugas spesifik dipecah ke dalam fungsi-fungsinya sendiri: tampilkanArray, cariMaksimum, cariMinimum, dan hitungRataRata. Fungsi main bertugas sebagai pengontrol utama yang menampilkan menu interaktif kepada pengguna. Program menggunakan perulangan do-while agar menu terus ditampilkan setelah sebuah operasi selesai, dan akan berhenti hanya jika pengguna memilih 0. Struktur switch-case digunakan untuk memanggil fungsi yang sesuai berdasarkan input pilihan dari pengguna, membuat alur program menjadi terstruktur dan mudah dibaca.

## Kesimpulan

Berdasarkan hasil praktikum Modul 2, dapat disimpulkan bahwa bahasa C++ mampu mengimplementasikan konsep dasar struktur data dan pemrograman modular secara efektif. Melalui tugas operasi matriks 3x3, program berhasil melakukan penjumlahan, pengurangan, dan perkalian menggunakan array dua dimensi dan perulangan bersarang. Pada tugas penukaran tiga variabel menggunakan pointer dan reference, dipahami bahwa keduanya dapat memodifikasi nilai variabel asli dari dalam fungsi, di mana pointer bekerja melalui alamat memori sementara reference bertindak sebagai alias yang lebih aman. Terakhir, pada implementasi program menu untuk analisis data array, konsep modularitas terbukti efektif dengan memisahkan tugas pencarian nilai maksimum, minimum, dan rata-rata ke dalam fungsi-fungsi terpisah yang dipanggil melalui struktur kontrol switch-case. Secara keseluruhan, praktikum ini memberikan pemahaman menyeluruh tentang pengelolaan data menggunakan array, pointer, dan reference, serta bagaimana mengintegrasikannya dalam sebuah program yang terstruktur, efisien, dan interaktif.

## Referensi

[1]Rizani, M. (2022). Matrix: Basic Concepts And Practical Applications In Daily Life. Jurnal Ilmiah Informatika dan Komputer. ejournal.rizaniamedia.com
<br>[2]Yusuf, A. (2023). Matrix-Based Computation in Informatics: A Conceptual Review of Linear Algebra Applications. Jurnal Ilmiah Informatika dan Komputer.
<br>[3]Lemire, D. (2022). Matrix Operations for Engineers and Scientists: An Essential Guide in Linear Algebra. SpringerLink.
<br>[4]Hamed, T. (2021). Pointers in C++. University of Mosul. ResearchGate.
<br>[5]Mogha, P. (2018). Pointers in C. International Journal of Research (IJR), 5(2).
<br>[6]Mahar, M. S., & Bisht, D. S. (2019). Features of Pointers in C. International Journal of Research.
<br>[7]GeeksforGeeks. (2023). Maximum and Minimum in an Array.
<br>[8]Lemire, D. (2006). Streaming Maximum-Minimum Filter Using No More than Three Comparisons per Element. arXiv preprint cs/0610046.
<br>[9]OpenGenus. (2021). Min and Max Element in Array.
<br>[10]Pressman, R. S. (2010). Software Engineering: A Practitioner's Approach. McGraw-Hill.
<br>[11]Tanenbaum, A. (2015). Structured Programming Concepts. Pearson Education.
<br>[12]Hamed, T. (2021). Pointers in C++. University of Mosul, ResearchGate.
<br>[13]Mogha, P. (2018). Pointers in C. International Journal of Research (IJR).
<br>[14]Mahar, M. S., & Bisht, D. S. (2019). Features of Pointers in C. IJR.