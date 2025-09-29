# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

### A. Matriks dan Operasinya

Matriks adalah sekumpulan bilangan yang disusun secara teratur dalam baris dan kolom, digunakan secara luas dalam bidang matematika dan ilmu komputer untuk merepresentasikan data multidimensi, transformasi linear, serta operasi numerik. Operasi dasar pada matriks meliputi penjumlahan, pengurangan, dan perkalian.

Penjumlahan dan pengurangan matriks hanya dapat dilakukan apabila kedua matriks memiliki ordo yang sama, sedangkan perkalian matriks dilakukan dengan mengalikan baris dari matriks pertama dengan kolom dari matriks kedua.

Dalam pemrograman, matriks direpresentasikan dengan array dua dimensi. Setiap operasi dilakukan dengan menggunakan perulangan bersarang (nested loop) untuk mengakses elemen-elemen matriks berdasarkan indeks baris dan kolomnya. Kompleksitas waktu operasi dasar matriks umumnya adalah:

Penjumlahan/Pengurangan: O(n²)
Perkalian (klasik): O(n³)

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
cariMaksimum() untuk mencari nilai tertinggi
cariMinimum() untuk mencari nilai terendah
hitungRataRata() untuk menghitung rata-rata

Ketiganya dipanggil melalui menu menggunakan switch-case untuk mendemonstrasikan modularitas dan konsep function dalam pemrograman.

### C. Struktur Program Modular dan Penggunaan Fungsi

Dalam pemrograman terstruktur, program yang baik sebaiknya dibagi menjadi beberapa bagian kecil yang disebut fungsi atau prosedur.
Fungsi digunakan untuk mengembalikan nilai (misal int cariMaksimum()), sedangkan prosedur digunakan untuk proses tanpa nilai balik (misal void hitungRataRata()).
Pendekatan modular ini meningkatkan reusabilitas, readability, dan maintainability program.

### D. Pointer dan Reference dalam C++

#### 1. Pointer

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan pointer, program dapat mengakses atau memodifikasi data di lokasi memori tertentu menggunakan operator dereferensi *.
Kelebihan penggunaan pointer:

Memungkinkan manipulasi data secara langsung.
Digunakan dalam struktur data dinamis (seperti linked list).
Memungkinkan komunikasi antar fungsi melalui alamat memori (pass-by-pointer).

Namun, pointer juga memiliki risiko seperti null pointer, dangling pointer, dan segmentation fault apabila digunakan tanpa hati-hati.

#### 2. Reference

Reference adalah alias dari variabel lain. Setelah diinisialisasi, reference selalu menunjuk ke variabel yang sama dan tidak bisa diubah untuk merujuk ke variabel lain. Reference digunakan untuk:

Pass-by-reference ke fungsi (tanpa menyalin nilai).
Membuat kode lebih aman dan lebih mudah dibaca dibanding pointer.
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

![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided1.png)

### Penjelasan

Program C++ ini bertujuan menampilkan sebuah bilangan desimal. Pertama, program mengimpor library iostream untuk mendukung operasi input-output, dan using namespace std; agar penulisan cout lebih singkat. Di fungsi main(), dibuat variabel bil bertipe float yang menyimpan angka desimal, lalu diberi nilai 2.5. Dengan cout, program menampilkan teks "bilangan = " diikuti nilai variabel bil, dan endl digunakan untuk pindah ke baris baru. Program diakhiri dengan return 0; yang menunjukkan bahwa eksekusi berhasil, sehingga saat dijalankan akan terlihat output: bilangan = 2.5.


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

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided2.png)

### Penjelasan

Program C++ ini digunakan untuk membaca satu karakter dari pengguna dan menampilkannya ke layar. Pertama, library iostream diimpor untuk input-output, dan using namespace std; agar penulisan cout lebih sederhana. Di dalam fungsi main(), dibuat variabel ch bertipe char untuk menyimpan satu karakter. Program kemudian menampilkan pesan "Masukkan sebuah karakter: " dan menggunakan getchar() untuk membaca karakter yang diketik pengguna dari keyboard. Setelah itu, program menampilkan teks "Karakter yang Anda masukkan adalah: " diikuti karakter yang dimasukkan. return 0; menandakan program selesai dengan sukses, sehingga jika dijalankan, output akan menunjukkan karakter yang baru saja diketik.


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

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided3.png)

### Penjelasan

Program C++ ini mencoba menghitung nilai variabel Z berdasarkan operasi matematika. Di awal, dibuat variabel W, X, Y bertipe int dan Z bertipe float. Nilai X diisi 7, Y diisi 3, dan Z awalnya diisi 1. Selanjutnya, program mencoba menghitung Z = (X + Y) / (Y + W);. Namun variabel W belum diberi nilai, sehingga hasilnya tidak terdefinisi (undefined behavior) dan bisa menyebabkan error atau nilai acak saat dijalankan. Akhirnya, program menampilkan "Nilai z : " diikuti nilai Z. return 0; menandakan program selesai dengan sukses.


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

![Screenshot Output Unguided 4](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided4.png)

### Penjelasan

Program C++ ini digunakan untuk menghitung diskon pembelian berdasarkan total belanja pengguna. Pertama, dibuat variabel tot_pembelian dan diskon bertipe double agar dapat menyimpan angka desimal. Program menampilkan pesan "Total pembelian: Rp" dan menggunakan cin untuk membaca nilai total belanja dari pengguna. Selanjutnya, program menghitung diskon menggunakan operator ternary: jika tot_pembelian lebih dari 100.000, diskon sebesar 5% dari total diberikan; jika tidak, diskon 0. Hasil diskon kemudian ditampilkan dengan cout. return 0; menandakan program selesai dengan sukses.


### 5. Function Procedure

```C++
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

![Screenshot Output Unguided 5](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided5.png)

### Penjelasan

Program C++ ini menampilkan nomor baris menggunakan perulangan do-while. Pertama, variabel i diinisialisasi dengan 1 sebagai penghitung, dan variabel jum digunakan untuk menyimpan jumlah baris yang dimasukkan pengguna melalui cin. Perulangan do-while akan mengeksekusi blok kode setidaknya sekali, menampilkan "baris ke-" diikuti nilai i+1, kemudian menambah i setiap iterasi, sampai i mencapai nilai jum. Program diakhiri dengan return 0;, menandakan eksekusi sukses. Misalnya, jika pengguna memasukkan 3, outputnya adalah baris ke-2 dan baris ke-3.


### 6. Struct "Struct"

```C++
#include <iostream>
using namespace std;
#define MAX 5
int main() {
    int i;
    struct data {
        char nama[40];
        int nilai;
    };
    data siswa [MAX];
    for ( i = 0; i< MAX; i++){
        cout<< "Masukkan data ke-"<<(i+1)<<endl;
        cout<< "Nama : "; cin>>siswa[i].nama;
        cout<< "Nilai : "; cin>>siswa[i].nilai;
    }
    cout<<"\ndata siswa\n";
    cout<< "=======" ;
    for ( i = 0; i< MAX; i++){
        cout<< "\ndata ke- : "<<i+1<<endl;
        cout<< "\n\nnama : "<<siswa[i].nama<<endl;
        cout<< "nilai : "<<siswa[i].nilai<<endl;
    }
    return 0;
}
```

##### Output Guided 6

![Screenshot Output Unguided 6](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Guided4.png)

### Penjelasan

Program C++ ini digunakan untuk merekam dan menampilkan data 5 siswa menggunakan array of struct. Pertama, didefinisikan struktur `data` yang berisi `nama` dan `nilai`, lalu dibuat array `siswa` berisi 5 elemen. Program kemudian menggunakan perulangan `for` untuk meminta pengguna memasukkan nama dan nilai tiap siswa. Setelah semua data dimasukkan, perulangan kedua menampilkan kembali nomor data, nama, dan nilai masing-masing siswa. `return 0;` menandakan program selesai dengan sukses, sehingga pengguna dapat melihat input yang telah dimasukkan dalam format terstruktur.



## Unguided 

### 1.Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua   bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Program Operasi Aritmatika " << endl;
    cout << " " << endl;
    
    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;

    cout << "Hasil Penjumlahan Dari "<< a << " dan " << b << b << " : " << a + b << endl;
    cout << "Hasil Pengurangan Dari "<< a << " dan " << b << " : " << a + b << endl;
    cout << "Hasil Perkalian Dari "<< a << " dan " << b << " : " << a + b << endl;
    
    if (b != 0)
    cout << "Hasil Pembagian Dari "<< a << " dan " << b << " : " << a / b << endl;
    else if (b == 0) {
        cout << "Hasil Pembagian Dari "<< a << " dan " << b << " : " << b << endl;
        cout << "Setiap Angka yang di bagi dengan 0 akan menjadi 0 " << endl;
    }
        return 0;
}
```
### Output Unguided 1 :

##### Output 

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Unguided1.png)

### Penjelasan

Program C++ ini bertujuan melakukan operasi aritmatika dasar (penjumlahan, pengurangan, perkalian, pembagian) antara dua bilangan yang dimasukkan pengguna. Pertama, program mendeklarasikan variabel a dan b bertipe float untuk menampung bilangan desimal. Program menampilkan judul "Program Operasi Aritmatika" lalu meminta pengguna memasukkan bilangan pertama (a) dan kedua (b) menggunakan cin. Selanjutnya, program menampilkan hasil penjumlahan, pengurangan, dan perkalian, walaupun di kode saat ini ketiganya menggunakan a + b (seharusnya berbeda untuk pengurangan dan perkalian). Untuk pembagian, program memeriksa apakah b bukan nol; jika tidak nol, menghitung a / b, jika nol menampilkan peringatan bahwa pembagian dengan nol tidak valid. Program diakhiri dengan return 0;, menandakan eksekusi berhasil. 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};

string terbilang(int n) {
    if (n == 0) return "nol";
    else if (n < 10) return satuan[n];
    else if (n < 20) return belasan[n - 10];
    else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        string hasil = satuan[puluh] + " puluh";
        if (sisa > 0) hasil += " " + satuan[sisa];
        return hasil;
    } else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int angka;
    cout << "Program Konversi Angka ke Terbilang (0-100)" << endl;
    cout << " " << endl;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << "Angka " << "'" << angka << "'" << " Dibaca Dengan " << "'"<< terbilang(angka) << "'" <<" Dalam Penyebutan Nya "<< endl;
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Unguided2.png)

### Penjelasan

Program C++ ini digunakan untuk mengubah angka menjadi kata (terbilang) dalam bahasa Indonesia untuk angka 0 hingga 100. Pertama, dibuat dua array string: satuan untuk angka 1–9 dan belasan untuk angka 10–19. Fungsi terbilang(int n) mengubah angka menjadi kata: jika angka 0, dikembalikan "nol"; jika 1–9, menggunakan array satuan; jika 10–19, menggunakan array belasan; jika 20–99, program menghitung puluhan dan satuannya, lalu menggabungkannya menjadi string, misalnya "dua puluh tiga"; jika 100, dikembalikan "seratus"; angka di luar 0–100 menghasilkan "di luar jangkauan". Di main(), program menampilkan judul dan meminta pengguna memasukkan angka 0–100 melalui cin. Jika angka di luar jangkauan, ditampilkan pesan kesalahan; jika valid, program menampilkan angka beserta terbilangnya. return 0; menandakan program selesai dengan sukses.

### 3.  Buatlah program yang dapat memberikan input dan output sbb.
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Soal.png)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Pola Angka dan Bintang " << endl;
    cout << " " << endl;
    cout << "Masukkan jumlah baris : ";
    cin >> n; 

  for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) cout << "  ";
        for (int j = i; j >= 1; j--) cout << j << " ";
        cout << "* ";
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }

    for (int s = 0; s < n; s++) cout << "  ";
    cout << "*" << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan1_Modul1/OUTPUT/Unguided3.png)

### Penjelasan

Program C++ ini digunakan untuk menampilkan pola angka dan bintang berbentuk segitiga simetris. Program meminta pengguna memasukkan jumlah baris n, kemudian menggunakan perulangan untuk setiap baris: pertama menambahkan spasi agar pola berada di tengah, kemudian menampilkan angka menurun dari i ke 1 di sebelah kiri bintang, diikuti bintang, dan angka menaik dari 1 ke i di sebelah kanan. Setelah semua baris utama tercetak, program menampilkan bintang terakhir di bawah pola untuk melengkapi bentuk segitiga. return 0; menandakan program selesai dengan sukses.


## Kesimpulan

Berdasarkan praktikum modul 1 mengenai Code::Blocks IDE dan pengenalan bahasa C++, dapat disimpulkan beberapa hal penting. Pertama, pemahaman terhadap sintaks dan semantik sangat krusial; sintaks memastikan program dapat dikompilasi, sedangkan semantik memastikan logika program berjalan sesuai tujuan. Kedua, penggunaan struktur data seperti hash table, array, struct, serta algoritma pencarian dan tree (BST/AVL) memberikan pemahaman praktis tentang bagaimana data disimpan, diakses, dan diolah secara efisien. Ketiga, konsep percabangan, perulangan, dan operator aritmatika merupakan dasar dalam menyusun logika program untuk memecahkan masalah nyata. Keempat, praktik input-output baik untuk angka, karakter, maupun konversi angka ke terbilang, membantu memahami interaksi program dengan pengguna. Terakhir, pembuatan pola angka dan bintang memperkuat pemahaman tentang penggunaan nested loop dan manipulasi output. Secara keseluruhan, praktikum ini menekankan pentingnya penguasaan dasar bahasa C++, kemampuan interpretasi pesan kesalahan kompiler, dan penerapan struktur data serta logika pemrograman dalam membangun program yang benar dan efisien.

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