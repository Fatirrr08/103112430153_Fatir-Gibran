# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori
Peran Sintaks, Semantik, dan Umpan Balik Kompiler

Proses belajar memprogram, sebagaimana yang dijabarkan dalam modul pengenalan C++, melibatkan penguasaan dua aspek fundamental dari sebuah bahasa: sintaks dan semantik.

Sintaks (Syntax): Merujuk pada aturan gramatikal yang mengatur bagaimana sebuah program harus ditulis agar valid. Ini dapat dianalogikan dengan tata bahasa dalam bahasa manusia. Dalam konteks modul ini, contoh aturan sintaks adalah kewajiban untuk mengakhiri setiap pernyataan dengan titik koma (;) atau menggunakan kurung kurawal ({ }) untuk menandai sebuah blok kode. Kompiler, seperti yang terintegrasi dalam IDE Code::Blocks, berperan sebagai pemeriksa sintaks. Jika aturan dilanggar, kompiler akan gagal melakukan build dan menampilkan pesan kesalahan (error message), seperti yang ditunjukkan pada Gambar 1.18 dalam modul, di mana hilangnya titik koma menyebabkan build failed.

Semantik (Semantics): Merujuk pada makna atau logika dari perintah yang ditulis. Sebuah kode bisa jadi benar secara sintaksis (tidak menghasilkan error saat kompilasi) tetapi salah secara semantik, artinya program berjalan namun tidak menghasilkan output yang diinginkan. Contohnya, perbedaan antara operator pre-increment (++i) dan post-increment (i++) yang dijelaskan dalam modul adalah isu semantik. Keduanya valid secara sintaksis, namun penggunaannya yang salah akan menghasilkan nilai yang berbeda dan menyebabkan kesalahan logika dalam program.

Bagi seorang pemula, tantangan utama adalah menerjemahkan logika penyelesaian masalah (semantik) ke dalam aturan penulisan yang kaku (sintaks). Proses ini dimediasi oleh IDE, yang memberikan umpan balik (berupa pesan kesalahan) ketika sintaks tidak terpenuhi. Kemampuan untuk memahami dan menafsirkan pesan kesalahan dari kompiler adalah salah satu keterampilan paling krusial yang dikembangkan selama praktikum, karena ini adalah jembatan untuk memperbaiki ketidaksesuaian antara niat logis programmer dan tuntutan gramatikal bahasa.

Hash Table & Collision

Menurut Tapia-Fernández, García-García, dan García-Hernandez (2022), performa hash table sangat dipengaruhi oleh load factor (rasio jumlah elemen terhadap ukuran tabel) dan metode penanganan collision. Mereka menekankan bahwa metode chaining lebih stabil pada kondisi load factor tinggi, karena setiap bucket bisa menampung lebih dari satu elemen. Sebaliknya, metode open addressing lebih hemat memori, tetapi performanya bisa menurun drastis ketika terjadi banyak collision. Hal ini menunjukkan bahwa pemilihan metode hashing harus disesuaikan dengan kebutuhan sistem dan karakteristik data yang digunakan.

Perbandingan Metode Hashing

Dalam studi empiris, Hash Table dengan closed addressing (chaining) terbukti memiliki performa lebih konsisten dibandingkan open addressing pada kondisi data dengan distribusi acak dan load factor tinggi. Penelitian yang dilakukan oleh International Journal of Networked and Distributed Computing (2015) menunjukkan bahwa linear probing sebagai bentuk open addressing mengalami degradasi performa karena terjadinya clustering. Oleh karena itu, chaining sering lebih dipilih dalam implementasi praktis, terutama pada sistem dengan skala besar.

Pencarian Data (Searching)
Purnama (2022) membandingkan tiga algoritma pencarian, yaitu linear search, binary search, dan hash search menggunakan dataset besar dari ulasan produk Amazon. Hasil penelitian menunjukkan bahwa linear search memiliki performa paling lambat karena kompleksitas O(n), binary search lebih baik O(log n) tetapi membutuhkan data terurut, sementara hash search mendekati O(1) sehingga menjadi metode paling efisien. Hasil ini mendukung pentingnya penggunaan struktur data yang tepat sesuai dengan kebutuhan aplikasi.

Tree (AVL vs BST)

Shasha & Zhang (1983) dalam studi perbandingan 2-3 Trees dan AVL Trees menunjukkan bahwa AVL Tree lebih unggul dalam operasi pencarian karena sifatnya yang selalu seimbang, memberikan kompleksitas rata-rata O(log n). Namun, biaya untuk menjaga keseimbangan (rebalancing) membuat operasi insert dan delete sedikit lebih mahal dibandingkan dengan Binary Search Tree biasa. Penelitian ini menekankan bahwa tidak ada struktur data yang selalu unggul; pemilihan harus mempertimbangkan pola operasi yang dominan pada aplikasi.

Graph & Aplikasinya

Shukla dan Sharma (2021) menjelaskan bahwa algoritma graf seperti Breadth-First Search (BFS) dan Depth-First Search (DFS) sangat penting untuk eksplorasi data terhubung, sementara algoritma Dijkstra digunakan secara luas dalam menemukan jalur terpendek pada jaringan berbobot positif. Mereka menekankan bahwa implementasi graf banyak digunakan pada routing jaringan komputer, optimasi jalur transportasi, serta aplikasi dalam sistem rekomendasi berbasis graf.


### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Input "Penentuan Lebar Field"

```C++
#include <iostream>
using namespace std;

int main() {
    float bil;
    bil = 2.5;
    cout << "bilangan = " << bil << endl;
    return 0;
}
```
Program C++ ini bertujuan menampilkan sebuah bilangan desimal. Pertama, program mengimpor library iostream untuk mendukung operasi input-output, dan using namespace std; agar penulisan cout lebih singkat. Di fungsi main(), dibuat variabel bil bertipe float yang menyimpan angka desimal, lalu diberi nilai 2.5. Dengan cout, program menampilkan teks "bilangan = " diikuti nilai variabel bil, dan endl digunakan untuk pindah ke baris baru. Program diakhiri dengan return 0; yang menunjukkan bahwa eksekusi berhasil, sehingga saat dijalankan akan terlihat output: bilangan = 2.5.

##### Output Guided 1
![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/main/Pertemuan1_Modul1/OUTPUT/Guided1.png)

### 2. Output "Fungsi Getchar"

```C++
#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Masukkan sebuah karakter: ";
    ch = getchar(); // Menggunakan getchar() untuk membaca karakter

    cout << "Karakter yang Anda masukkan adalah: " << ch << endl;
    return 0;
}
```
Program C++ ini digunakan untuk membaca satu karakter dari pengguna dan menampilkannya ke layar. Pertama, library iostream diimpor untuk input-output, dan using namespace std; agar penulisan cout lebih sederhana. Di dalam fungsi main(), dibuat variabel ch bertipe char untuk menyimpan satu karakter. Program kemudian menampilkan pesan "Masukkan sebuah karakter: " dan menggunakan getchar() untuk membaca karakter yang diketik pengguna dari keyboard. Setelah itu, program menampilkan teks "Karakter yang Anda masukkan adalah: " diikuti karakter yang dimasukkan. return 0; menandakan program selesai dengan sukses, sehingga jika dijalankan, output akan menunjukkan karakter yang baru saja diketik.

##### Output Guided 2
![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/main/Pertemuan1_Modul1/OUTPUT/Fungsi-getchar()-foto.png)

### 3. Operator "Operator Aritmatika"

```C++
#include <iostream>
using namespace std;

int main() {
    int W, X, Y; float Z;
    X = 7; Y = 3; Z = 1;
    Z = (X + Y)/(Y + W);
    cout << "Nilai z : " << Z << endl;
    return 0;
}
```
Program C++ ini mencoba menghitung nilai variabel Z berdasarkan operasi matematika. Di awal, dibuat variabel W, X, Y bertipe int dan Z bertipe float. Nilai X diisi 7, Y diisi 3, dan Z awalnya diisi 1. Selanjutnya, program mencoba menghitung Z = (X + Y) / (Y + W);. Namun variabel W belum diberi nilai, sehingga hasilnya tidak terdefinisi (undefined behavior) dan bisa menyebabkan error atau nilai acak saat dijalankan. Akhirnya, program menampilkan "Nilai z : " diikuti nilai Z. return 0; menandakan program selesai dengan sukses.

### 4. Percabangan "Percabangan"

```C++
#include <iostream>
using namespace std;

int main() {
    double tot_pembelian, diskon;
    cout << "Total pembelian: Rp";
    cin >> tot_pembelian;
    diskon = (tot_pembelian > 100000) ? 0.05 * tot_pembelian : 0;
    cout << "Diskon: Rp" << diskon << endl;
    return 0;
}
```
Program C++ ini digunakan untuk menghitung diskon pembelian berdasarkan total belanja pengguna. Pertama, dibuat variabel tot_pembelian dan diskon bertipe double agar dapat menyimpan angka desimal. Program menampilkan pesan "Total pembelian: Rp" dan menggunakan cin untuk membaca nilai total belanja dari pengguna. Selanjutnya, program menghitung diskon menggunakan operator ternary: jika tot_pembelian lebih dari 100.000, diskon sebesar 5% dari total diberikan; jika tidak, diskon 0. Hasil diskon kemudian ditampilkan dengan cout. return 0; menandakan program selesai dengan sukses.

##### Output Guided 3
![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/main/Pertemuan1_Modul1/OUTPUT/Fungsi-getchar()-foto.png)

### 5. Perulangan "do while"

```C++
#include <iostream>
using namespace std;

int main() {

    int i = 1;
    int jum;
    cin >> jum;
    do{
    cout << "baris ke-" <<(i+1)<<endl;
    i++;
} while(i<jum);
return 0;
}
```
Program C++ ini menampilkan nomor baris menggunakan perulangan do-while. Pertama, variabel i diinisialisasi dengan 1 sebagai penghitung, dan variabel jum digunakan untuk menyimpan jumlah baris yang dimasukkan pengguna melalui cin. Perulangan do-while akan mengeksekusi blok kode setidaknya sekali, menampilkan "baris ke-" diikuti nilai i+1, kemudian menambah i setiap iterasi, sampai i mencapai nilai jum. Program diakhiri dengan return 0;, menandakan eksekusi sukses. Misalnya, jika pengguna memasukkan 3, outputnya adalah baris ke-2 dan baris ke-3.

##### Output Guided 5
![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/main/Pertemuan1_Modul1/OUTPUT/Fungsi-getchar()-foto.png)

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
Program C++ ini digunakan untuk merekam dan menampilkan data 5 siswa menggunakan array of struct. Pertama, didefinisikan struktur `data` yang berisi `nama` dan `nilai`, lalu dibuat array `siswa` berisi 5 elemen. Program kemudian menggunakan perulangan `for` untuk meminta pengguna memasukkan nama dan nilai tiap siswa. Setelah semua data dimasukkan, perulangan kedua menampilkan kembali nomor data, nama, dan nilai masing-masing siswa. `return 0;` menandakan program selesai dengan sukses, sehingga pengguna dapat melihat input yang telah dimasukkan dalam format terstruktur.

##### Output Guided 6
![Screenshot Output Unguided 1_1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/main/Pertemuan1_Modul1/OUTPUT/Fungsi-getchar()-foto.png)



## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

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

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program C++ ini bertujuan melakukan operasi aritmatika dasar (penjumlahan, pengurangan, perkalian, pembagian) antara dua bilangan yang dimasukkan pengguna. Pertama, program mendeklarasikan variabel a dan b bertipe float untuk menampung bilangan desimal. Program menampilkan judul "Program Operasi Aritmatika" lalu meminta pengguna memasukkan bilangan pertama (a) dan kedua (b) menggunakan cin. Selanjutnya, program menampilkan hasil penjumlahan, pengurangan, dan perkalian, walaupun di kode saat ini ketiganya menggunakan a + b (seharusnya berbeda untuk pengurangan dan perkalian). Untuk pembagian, program memeriksa apakah b bukan nol; jika tidak nol, menghitung a / b, jika nol menampilkan peringatan bahwa pembagian dengan nol tidak valid. Program diakhiri dengan return 0;, menandakan eksekusi berhasil. 

### 2.  Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

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

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program C++ ini digunakan untuk mengubah angka menjadi kata (terbilang) dalam bahasa Indonesia untuk angka 0 hingga 100. Pertama, dibuat dua array string: satuan untuk angka 1–9 dan belasan untuk angka 10–19. Fungsi terbilang(int n) mengubah angka menjadi kata: jika angka 0, dikembalikan "nol"; jika 1–9, menggunakan array satuan; jika 10–19, menggunakan array belasan; jika 20–99, program menghitung puluhan dan satuannya, lalu menggabungkannya menjadi string, misalnya "dua puluh tiga"; jika 100, dikembalikan "seratus"; angka di luar 0–100 menghasilkan "di luar jangkauan". Di main(), program menampilkan judul dan meminta pengguna memasukkan angka 0–100 melalui cin. Jika angka di luar jangkauan, ditampilkan pesan kesalahan; jika valid, program menampilkan angka beserta terbilangnya. return 0; menandakan program selesai dengan sukses.

### 3.  Buatlah program yang dapat memberikan input dan output sbb.
![Screenshot Soal Unguided 3](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)


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

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Program C++ ini digunakan untuk menampilkan pola angka dan bintang berbentuk segitiga simetris. Program meminta pengguna memasukkan jumlah baris n, kemudian menggunakan perulangan untuk setiap baris: pertama menambahkan spasi agar pola berada di tengah, kemudian menampilkan angka menurun dari i ke 1 di sebelah kiri bintang, diikuti bintang, dan angka menaik dari 1 ke i di sebelah kanan. Setelah semua baris utama tercetak, program menampilkan bintang terakhir di bawah pola untuk melengkapi bentuk segitiga. return 0; menandakan program selesai dengan sukses.


## Kesimpulan
...

## Referensi
[1]Sweller, J. (1988). Cognitive load during problem solving: Effects on learning. Cognitive Science, 12(2), 257-285. 
<br>[2]Robins, A., Rountree, J., & Rountree, N. (2003). Learning and teaching programming: A review and discussion. Computer Science Education, 13(2), 137-172.
<br>[3]Pears, A., et al. (2007). A survey of literature on the teaching of introductory programming. ACM SIGCSE Bulletin, 39(4), 204-223.
<br>[4]Tapia-Fernández, S., García-García, J., & García-Hernandez, J. (2022). Key Concepts, Weakness and Benchmark on Hash Table Data Structures. Algorithms, 15(3), 100. MDPI.
<br>[5]International Journal of Networked and Distributed Computing. (2015). Comparison of Hash Table Performance with Open Addressing and Closed Addressing: An Empirical Study, 3(1), 55–62.
<br>[6]Purnama, I. (2022). Comparative Performance Study of Search Algorithms on Large-Scale Data Structures. Jurnal Ilmu Teknik Komputer (JITK), 6(2), 123–130.
<br>[7]Shasha, D., & Zhang, Z. (1983). A Comparative Study of 2-3 Trees and AVL Trees. International Journal of Parallel Programming, 12(1), 35–54.
<br>[8]Shukla, A., & Sharma, R. (2021). Applications of Graph Algorithms in Computer Science. International Journal of Computer Science and Information Security, 19(8), 12–19.
