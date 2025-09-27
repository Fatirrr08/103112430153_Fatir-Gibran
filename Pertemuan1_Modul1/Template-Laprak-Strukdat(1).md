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

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

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
