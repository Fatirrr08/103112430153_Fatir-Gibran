# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematis dari sebuah objek data yang mendefinisikan tipe data dari objek tersebut serta operasi-operasi yang dapat dilakukan terhadapnya, tanpa memperlihatkan detail implementasinya. Konsep utama dari ADT adalah enkapsulasi, yaitu menyembunyikan detail internal dan hanya mengekspos fungsionalitas yang esensial.

Dalam pemrograman C++, ADT biasanya diimplementasikan dengan memisahkan antarmuka (interface) dari implementasinya.

Antarmuka (Header File .h): Bagian ini mendeklarasikan "apa" yang bisa dilakukan oleh ADT. Ini termasuk definisi struct atau class dan prototipe (deklarasi) dari fungsi-fungsi yang beroperasi pada tipe data tersebut. File header bertindak sebagai "kontrak" yang memberitahu bagian lain dari program cara berinteraksi dengan ADT.

Implementasi (Source File .cpp): Bagian ini mendefinisikan "bagaimana" operasi-operasi tersebut dilakukan. Ini berisi kode aktual atau body dari fungsi-fungsi yang dideklarasikan di file header. Dengan memisahkan implementasi, kita bisa mengubah cara kerja internal sebuah fungsi tanpa harus mengubah kode lain yang menggunakannya, selama antarmukanya tetap sama.

Pendekatan ini membuat kode menjadi lebih modular, mudah dikelola, dan dapat digunakan kembali (reusable).

## Guided 

### 1. Struck

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
        string nama;
        float nilai1, nilai2;
};

void input(mahasiswa &mhs){
        cout<<"Masukkan Nama : ";
        cin>>mhs.nama;
        cout<<"Masukkan Nilai 1 : "; 
        cin>>mhs.nilai1;
        cout<<"Masukkan Nilai 2 : "; 
        cin>>mhs.nilai2;
}

float rata2(mahasiswa mhs){
        return (mhs.nilai1 + mhs.nilai2)/2;
}
int main(){
        mahasiswa mhs;
        input(mhs);
        cout<<"Rata-rata Nilai : "<<rata2(mhs)<<endl;
        return 0;
}
```
##### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/Guided1.png)

### Penjelasan

Program ini mendemonstrasikan penggunaan dasar struct untuk membungkus data nama dan dua nilai mahasiswa dalam satu tipe data. Sebuah prosedur input digunakan untuk mengisi data ke dalam struct dengan metode pass-by-reference (&mhs), sementara fungsi rata2 menghitung dan mengembalikan rata-rata nilai. Fungsi main kemudian mendeklarasikan variabel struct mahasiswa, memanggil kedua fungsi tersebut secara berurutan untuk mengisi data lalu menampilkannya, menunjukkan alur kerja program prosedural yang sederhana dalam satu file.

### 2. Pelajar

#### pelajar.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampilan_pelajaran(pelajaran pel);
#endif
```

#### pelajar.cpp
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampilan_pelajaran(pelajaran pel){
    cout<<"Nama Mata Pelajaran : "<<pel.namaMapel<<endl;
    cout<<"Kode Mata Pelajaran : "<<pel.kodeMapel<<endl;
}
```

#### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "stuktur data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampilan_pelajaran(pel);
    return 0;
}
```
##### Output Guided 2

![Screenshot Output guided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/Guided2.png)

### Penjelasan

Program ini mengimplementasikan konsep ADT dengan memisahkan kode ke dalam tiga file. File pelajar.h bertindak sebagai antarmuka (interface) yang mendefinisikan struct pelajaran dan mendeklarasikan prototipe fungsi. File pelajar.cpp berisi implementasi atau logika sebenarnya dari fungsi create_pelajaran (sebagai constructor) dan tampilan_pelajaran. Terakhir, main.cpp berfungsi sebagai driver yang menggunakan ADT tersebut dengan cara meng-#include file header, membuat objek pelajaran, dan memanggil fungsinya untuk menampilkan hasil.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

#### mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

// Struct Mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

// Deklarasi fungsi
float hitungNilaiAkhir(float uts, float uas, float tugas);
void tampilkanData(Mahasiswa mhs[], int n);

#endif
```

#### mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

// Implementasi fungsi hitung nilai akhir
float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanData(Mahasiswa mhs[], int n) {
    cout << "\n============================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "============================================\n";
    cout << "No\tNIM\t\tNama\t\tNilai Akhir\n";
    cout << "--------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << "\t"
             << mhs[i].nim << "\t"
             << mhs[i].nama << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }
}
```

### main.cpp
```C++
#include <iostream>
#include <string>
#include "mahasiswa.h"
using namespace std;

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah mahasiswa melebihi batas maksimum (10)!" << endl;
        return 0;
    }

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        getline(cin, mhs[i].nim);
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        // Hitung nilai akhir
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    // Tampilkan data
    tampilkanData(mhs, n);

    return 0;
}
```

### Output Unguided 1 :

##### Output 

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/Unguided1.png)

### Penjelasan

Program ini menerapkan ADT untuk mengelola data dari banyak mahasiswa menggunakan sebuah array of struct. File mahasiswa.h mendefinisikan struct Mahasiswa dan prototipe fungsi untuk menghitung nilai akhir serta menampilkan data. Implementasi dalam mahasiswa.cpp menyediakan logika untuk fungsi hitungNilaiAkhir sesuai rumus pembobotan dan fungsi tampilkanData yang mencetak output dalam format tabel. File main.cpp mengatur alur program utama: meminta jumlah mahasiswa, melakukan perulangan untuk input data, memanggil fungsi untuk menghitung nilai akhir setiap mahasiswa, dan terakhir memanggil fungsi untuk menampilkan seluruh data yang telah diolah.

### 2.  Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
```C++
Type pelajaran <
namaMapel : string kodeMapel : string
function create_pelajaran( namapel : string, kodepel: string ) → pelajaran
procedure tampil_pelajaran( input pel: pelajaran)
```
#### Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"

#### Cobalah hasil implementasi ADT pada file "main.cpp"
```C++
using namespace std;
int main() {
    string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran (namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```

#### Contoh output hasil:

![Contoh output hasil](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/hasil.png)

#### pelajar.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaMapel, string kodepel);

void tampilan_pelajaran(pelajaran pel);
#endif
```

#### pelajar.cpp
```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampilan_pelajaran(pelajaran pel){
    cout<<"Nama Mata Pelajaran : "<<pel.namaMapel<<endl;
    cout<<"Kode Mata Pelajaran : "<<pel.kodeMapel<<endl;
}
```

### main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "stuktur data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampilan_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2 :

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/Unguided2.png)

### Penjelasan
Program ini bertujuan untuk memperkuat pemahaman tentang ADT dengan mengimplementasikan ulang ADT pelajaran. Seperti pada contoh guided, program dibagi menjadi tiga file: pelajar.h sebagai antarmuka yang berisi definisi struct dan deklarasi fungsi, pelajar.cpp sebagai file implementasi yang berisi kode rinci dari fungsi create_pelajaran dan tampilan_pelajaran, serta main.cpp sebagai program utama yang menggunakan ADT tersebut untuk membuat dan menampilkan data satu mata pelajaran.


### 3. Buatlah program dengan ketentuan : 
#### 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer 
#### fungsi/prosedur yang menampilkan isi sebuah array integer 2D fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu 
#### fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buahpointer


#### array_utils.h
```C++
#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

void tampilkanArray(const int arr[3][3]);
void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom);
void tukarViaPointer(int* ptr1, int* ptr2);

#endif
```

#### array_utils.cpp
```C++
#include "array_utils.h"
#include <iostream>
#include <iomanip>

void tampilkanArray(const int arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << std::setw(4) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    if (baris >= 0 && baris < 3 && kolom >= 0 && kolom < 3) {
        int temp = arr1[baris][kolom];
        arr1[baris][kolom] = arr2[baris][kolom];
        arr2[baris][kolom] = temp;
    } else {
        std::cout << "Posisi baris/kolom tidak valid!" << std::endl;
    }
}

void tukarViaPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

### main.cpp
```C++
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
```

##### Output 

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan3/OUTPUT/Unguided3.png)

### Penjelasan

Program ini membangun sebuah ADT utilitas untuk operasi array dan pointer yang interaktif dengan pengguna. Antarmuka fungsi dideklarasikan di array_utils.h, yang mencakup fungsi untuk menampilkan array 2D, menukar elemen antara dua array, dan menukar nilai yang ditunjuk oleh dua pointer. Logika dari ketiga fungsi tersebut, termasuk algoritma swap untuk elemen dan pointer, diimplementasikan dalam array_utils.cpp. File main.cpp kemudian menjadi program utama yang dinamis, di mana semua nilai untuk kedua array dan kedua variabel pointer diinput oleh pengguna sebelum fungsi-fungsi dari ADT dipanggil untuk memanipulasi dan menampilkan data tersebut.

## Kesimpulan

Pada praktikum Modul 3 ini, konsep Abstract Data Type (ADT) telah berhasil dipelajari dan diimplementasikan. ADT memungkinkan pemisahan antara antarmuka (deklarasi dalam file .h) dan implementasi (definisi dalam file .cpp). Pendekatan ini terbukti membuat struktur program menjadi lebih terorganisir, modular, dan mudah untuk dikelola, terutama pada program yang lebih kompleks. Melalui pengerjaan guided dan unguided, dapat disimpulkan bahwa penggunaan ADT dengan struct dan fungsi sangat efektif untuk membungkus data dan operasi yang berkaitan dengannya, yang merupakan inti dari prinsip enkapsulasi.

## Referensi

[1] GeeksforGeeks. (2023). Abstract Data Types. [Online]. Tersedia di: https://www.geeksforgeeks.org/abstract-data-types/
<br>[2] TutorialsPoint. (2023). C++ Structures. [Online]. Tersedia di: https://www.tutorialspoint.com/cplusplus/cpp_structures.htm
<br>[3] Learn C++. (2023). 10.2 — Header files. [Online]. Tersedia di: https://www.learncpp.com/cpp-tutorial/header-files/
<br>[4] Programiz. (2023). C++ Pointers. [Online]. Tersedia di: https://www.programiz.com/cpp-programming/pointers
<br>[5] W3Schools. (2023). C++ Functions. [Online]. Tersedia di: https://www.w3schools.com/cpp/cpp_functions.asp
<br>[6] GeeksforGeeks. (2023). C++ Arrays. [Online]. Tersedia di: https://www.geeksforgeeks.org/cpp-arrays/
<br>[7] CPlusPlus.com. (2023). Pointers - C++ Tutorials. [Online]. Tersedia di: https://cplusplus.com/doc/tutorial/pointers/
<br>[8] Stack Overflow. (2012). Why should I use a header file? [Online]. Tersedia di: https://stackoverflow.com/questions/333831/why-should-i-use-a-header-file
<br>[9] GeeksforGeeks. (2023). Pass by Reference in C++. [Online]. Tersedia di: https://www.geeksforgeeks.org/pass-by-reference-in-cpp/
<br>[10] Programiz. (2023). C++ Arrays Passed to a Function. [Online]. Tersedia di: https://www.programiz.com/cpp-programming/passing-arrays-function
<br>[11] Learn C++. (2023). 1.5 — Introduction to structs, members, and member selection. [Online]. Tersedia di: https://www.learncpp.com/cpp-tutorial/introduction-to-structs-members-and-member-selection/
<br>[12] CPlusPlus.com. (2023). Multidimensional arrays - C++ Tutorials. [Online]. Tersedia di: https://cplusplus.com/doc/tutorial/arrays/
<br>[13] Educative. (2023). What Is Encapsulation in C++? [Online]. Tersedia di: https://www.educative.io/blog/what-is-encapsulation-in-cpp
<br>[14] GeeksforGeeks. (2023). Header Files in C/C++. [Online]. Tersedia di: https://www.geeksforgeeks.org/header-files-in-c-cpp/
