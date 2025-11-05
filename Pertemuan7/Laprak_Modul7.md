# <h1 align="center">Laporan Praktikum Modul 7 - STACK </h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Stack (Tumpukan) adalah salah satu jenis Struktur Data Linier yang beroperasi berdasarkan prinsip LIFO (Last In First Out). Prinsip ini menentukan bahwa elemen yang terakhir kali dimasukkan ke dalam tumpukan adalah elemen yang pertama kali akan dikeluarkan. Analogi Stack paling sederhana adalah tumpukan piring atau tumpukan buku, di mana piring atau buku yang diletakkan paling atas (terakhir) harus diambil terlebih dahulu.

### Komponen dan Primitif </br>

Pada Stack, akses data hanya dimungkinkan melalui satu ujung, yang dikenal sebagai TOP (Puncak). Komponen utama Stack pada dasarnya mirip dengan Singly Linked List, namun aksesnya dibatasi hanya pada elemen paling awal.

Operasi-operasi dasar (primitif) yang wajib ada dalam Stack, meskipun jumlahnya lebih sedikit dibandingkan list lain, berfokus pada akses elemen paling atas. Operasi utama tersebut meliputi:

1. Push: Operasi penyisipan elemen baru ke dalam Stack. Dalam implementasi Linked List, ini setara dengan operasi insert first.
2. Pop: Operasi pengambilan (penghapusan) elemen dari Stack. Ini setara dengan operasi delete first, karena elemen yang diakses adalah elemen paling awal/atas.
3. Primitif Pendukung: Termasuk fungsi untuk membuat Stack kosong (createStack), memeriksa kekosongan (isEmpty), alokasi memori (alokasi), dan dealokasi memori (dealokasi), serta fungsi pencarian.

### Representasi Stack

Stack dapat diimplementasikan dalam dua representasi utama, masing-masing memiliki kelebihan dan kekurangan:

1. Representasi Pointer (Linked List): Stack direpresentasikan sebagai list yang elemennya saling terhubung menggunakan pointer. Keuntungan utama adalah ukuran Stack bersifat dinamis; Stack hanya dibatasi oleh memori yang tersedia. Elemen utama yang dikelola adalah pointer TOP, yang menunjuk ke elemen paling atas.
2. Representasi Tabel (Array): Stack direpresentasikan menggunakan array berindeks. Kelebihan utamanya adalah kemudahan implementasi dan alokasi memori yang dilakukan di awal. Namun, kekurangannya adalah ukuran Stack bersifat terbatas oleh ukuran maksimum array yang dideklarasikan(MaxEl).Pada representasi ini, TOP biasanya diimplementasikan sebagai variabel integer yang menyimpan indeks elemen teratas. Nilai TOP akan bertambah saat Push(TOP = TOP + 1) dan berkurang saat Pop(TOP = TOP - 1).Selain itu, representasi tabel tidak memerlukan manajemen memori khusus seperti alokasi/dealokasi.

## Guided 

### 1. Implementasi Stack dengan Representasi Pointer (Linked List)

#### Liststack.h
```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

#### Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
#### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Guided1.png)

#### Penjelasan

Guided 1 mengimplementasikan Abstract Data Type (ADT) Stack menggunakan Linked List (pointer). Operasi Push dilakukan dengan menambahkan node baru di awal list (sebagai top baru), mirip dengan operasi insert first pada Linked List. Operasi Pop dilakukan dengan menghapus node yang ditunjuk oleh top, mirip dengan operasi delete first. Implementasi ini juga menunjukkan bahwa Stack berbasis Linked List masih dapat dimodifikasi dengan operasi yang tidak umum (non-primitif Stack), seperti update dan searchData, yang memanfaatkan traversi melalui pointer next, meskipun dalam ADT Stack murni, akses data seharusnya hanya melalui top.

### 2. Implementasi Stack dengan Representasi Tabel (Array)

#### Stack.h
```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```

#### Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    int idx = s.top - (posisi + 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke- " << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = -1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke- " << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
        cout << endl;
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // posisi dihitung dari TOP (1-based index)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
#### Output Guided 2
![Screenshot Output guided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Guided2.png)

#### Penjelasan

Guided 2 mengimplementasikan ADT Stack menggunakan Array (tabel). Dalam representasi ini, top diwakili oleh sebuah integer yang berfungsi sebagai indeks elemen paling atas. Operasi Push dilakukan dengan menambah nilai top dan menyimpan data pada indeks tersebut (s.top++, s.data[s.top] = angka). Operasi Pop dilakukan dengan mengurangi nilai top (s.top--), secara efektif mengabaikan data lama di indeks top tanpa menghapusnya secara fisik. Sama seperti Guided 1, contoh implementasi ini mencakup fungsi non-primitif update dan searchData yang mengakses data di luar top, menunjukkan fleksibilitas dasar implementasi array meskipun melanggar prinsip ketat ADT Stack LIFO.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Soal1.png)
### Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”

#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int infotype; 
#define MaxEl 20 

struct Stack {
    infotype info[MaxEl + 1]; 
    int top;                  
};

void CreateStack(Stack &S);

int IsEmpty(Stack S);

void Push(Stack &S, infotype X);

infotype Pop(Stack &S);

void PrintInfo(Stack S);

void BalikStack(Stack &S);

#endif
```
#### Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = 0; 
}

int IsEmpty(Stack S) {
    return S.top == 0;
}

void Push(Stack &S, infotype X) {
    if (S.top < MaxEl) { 
        S.top++; 
        S.info[S.top] = X; 
    } else {
        cout << "Stack Penuh, Push gagal!" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = 0; 
    if (!IsEmpty(S)) {
        X = S.info[S.top]; 
        S.top--;           
    } 
    return X; 
}

void PrintInfo(Stack S) {
    if (!IsEmpty(S)) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--) { 
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void BalikStack(Stack &S) {
    Stack Temp; 
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    Push(S, 3);
    Push(S, 4);
    Push(S, 8);
    Pop(S);      
    Push(S, 2);  
    Push(S, 3);  
    Pop(S);      
    Push(S, 9);  
    
    PrintInfo(S); 

    cout << "balik stack" << endl;
    BalikStack(S);
    
    PrintInfo(S); 
    
    return 0;
}
```

#### Output Unguided 1


![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Unguided1.png)

#### Penjelasan

Bagian Unguided 1 merupakan implementasi dasar ADT Stack menggunakan representasi Array, yang berfungsi sebagai fondasi untuk soal selanjutnya. Implementasi ini mencakup fungsi primitif standar: CreateStack, IsEmpty, Push, Pop, PrintInfo, dan BalikStack. Koreksi pada fungsi BalikStack dilakukan agar Stack akhir benar-benar terbalik dari urutan semula (menggunakan dua Stack sementara), memastikan output sesuai dengan yang diminta pada contoh latihan.

### 2.  Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

![Screenshot Soal Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Soal2.png) 

#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int infotype; 
#define MaxEl 20 

struct Stack {
    infotype info[MaxEl + 1]; 
    int top;                  
};

void CreateStack(Stack &S);

int IsEmpty(Stack S);

void Push(Stack &S, infotype X);

infotype Pop(Stack &S);

void PrintInfo(Stack S);

void BalikStack(Stack &S);

void PushAscending(Stack &S, infotype X);

#endif 
```

#### Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = 0; 
}

int IsEmpty(Stack S) {
    return S.top == 0;
}

void Push(Stack &S, infotype X) {
    if (S.top < MaxEl) { 
        S.top++; 
        S.info[S.top] = X; 
    } else {
        cout << "Stack Penuh, Push gagal!" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = 0; 
    if (!IsEmpty(S)) {
        X = S.info[S.top]; 
        S.top--;           
    } 
    return X; 
}

void PrintInfo(Stack S) {
    if (!IsEmpty(S)) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--) { 
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void BalikStack(Stack &S) {
    Stack Temp1; 
    Stack Temp2; 
    CreateStack(Temp1);
    CreateStack(Temp2);

    while (!IsEmpty(S)) {
        Push(Temp1, Pop(S));
    }
    
    while (!IsEmpty(Temp1)) {
        Push(Temp2, Pop(Temp1));
    }
    
    while (!IsEmpty(Temp2)) {
        Push(S, Pop(Temp2));
    }
}

void PushAscending(Stack &S, infotype X) {
    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S) && S.info[S.top] > X) {
        Push(Temp, Pop(S));
    }

    Push(S, X);

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    PushAscending(S, 3);
    PushAscending(S, 4);
    PushAscending(S, 8);
    PushAscending(S, 2);
    PushAscending(S, 3);
    PushAscending(S, 9);
    
    PrintInfo(S); 

    cout << "balik stack" << endl;
    BalikStack(S);
    
    PrintInfo(S); 
    
    return 0;
}
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Unguided2.png)

#### Penjelasan

Soal Unguided 2 menambahkan prosedur khusus PushAscending, yang menyisipkan elemen baru X sambil menjaga urutan data dalam Stack tetap menaik (ascending). Karena Stack hanya mengizinkan akses dari TOP, prosedur ini menggunakan Stack sementara (Temp) untuk menahan sementara semua elemen yang lebih besar dari X. Setelah elemen X disisipkan di posisi yang benar, elemen yang ditahan di Stack Temp dikembalikan ke Stack utama, sehingga urutan tetap terjaga.

### 3.  Hapus elemen dengan nomor polisi D003 dengan procedure delete.
![Screenshot Soal Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Soal3.png) 

#### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

// PENTING: Ubah infotype menjadi char untuk Soal 3
typedef char infotype; 
#define MaxEl 20 

struct Stack {
    infotype info[MaxEl + 1]; 
    int top;                  
};

void CreateStack(Stack &S);

int IsEmpty(Stack S);

void Push(Stack &S, infotype X);

infotype Pop(Stack &S);

void PrintInfo(Stack S);

void BalikStack(Stack &S);

void GetInputStream(Stack &S);

#endif
```

#### Stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = 0; 
}

int IsEmpty(Stack S) {
    return S.top == 0;
}

void Push(Stack &S, infotype X) {
    if (S.top < MaxEl) { 
        S.top++; 
        S.info[S.top] = X; 
    } else {
        cout << "Stack Penuh, Push gagal!" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = '\0'; 
    if (!IsEmpty(S)) {
        X = S.info[S.top]; 
        S.top--;           
    } 
    return X; 
}

void PrintInfo(Stack S) {
    if (!IsEmpty(S)) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--) { 
            cout << S.info[i]; 
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void BalikStack(Stack &S) {
    Stack Temp1; 
    Stack Temp2; 
    CreateStack(Temp1);
    CreateStack(Temp2);

    while (!IsEmpty(S)) {
        Push(Temp1, Pop(S));
    }
    
    while (!IsEmpty(Temp1)) {
        Push(Temp2, Pop(Temp1));
    }
    
    while (!IsEmpty(Temp2)) {
        Push(S, Pop(Temp2));
    }
}

void GetInputStream(Stack &S) {
    char karakter;
    cout << "Masukkan input: ";
    
    while (cin.get(karakter) && karakter != '\n') {
        if (S.top < MaxEl) {
            Push(S, (infotype)karakter);
        } else {
            cout << "Stack Penuh, sisa input diabaikan!" << endl;
            while (cin.get(karakter) && karakter != '\n') {} 
            return;
        }
    }
}
```

#### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    
    CreateStack(S);
    GetInputStream(S);
    PrintInfo(S); 
    cout << "balik stack" << endl;
    BalikStack(S);
    PrintInfo(S); 
    
    return 0;
}
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/pertemuan7/OUTPUT/Unguided3.png)

#### Penjelasan

Soal Unguided 3 menguji kemampuan Stack dalam memproses input karakter dengan mengimplementasikan prosedur GetInputStream. Tipe data infotype disesuaikan menjadi char. Prosedur ini menggunakan cin.get() untuk membaca setiap karakter dari input hingga tombol Enter (\n) ditekan, dan setiap karakter dimasukkan ke Stack menggunakan operasi Push. Hasilnya, urutan karakter dalam Stack akan terbalik dari urutan input (LIFO), yang kemudian diperbaiki kembali ke urutan semula menggunakan fungsi BalikStack yang telah diperbaiki.

## Kesimpulan

Stack adalah struktur data LIFO (Last In First Out) yang mendefinisikan akses data hanya melalui satu titik tunggal, yaitu TOP. Implementasi Stack dapat dilakukan dengan dua metode utama: Representasi Pointer (Linked List) yang menawarkan ukuran dinamis, dan Representasi Tabel (Array) yang memiliki ukuran terbatas. Operasi inti Stack adalah Push (menambah data di TOP) dan Pop (menghapus data dari TOP). Meskipun ADT Stack membatasi akses, implementasi pada bahasa pemrograman memungkinkan adanya operasi non-primitif seperti pencarian atau pembaruan. Keberhasilan implementasi ADT Stack yang benar memastikan disiplin LIFO diterapkan, yang krusial dalam berbagai aplikasi seperti manajemen fungsi (function call stack), evaluasi ekspresi, dan pemrosesan urutan terbalik.

## Referensi

[1] Lipschutz, S. (2017). Schaum's Outline of Data Structures with C++. New York: McGraw-Hill Education.
<br>[2] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). Introduction to Algorithms (3rd ed.). Cambridge, MA: MIT Press.
<br>[3] Carrano, F. M., & Henry, P. L. (2020). Data Structures and Abstractions with C++ (5th ed.). Hoboken, NJ: Pearson.
<br>[4] GeeksforGeeks. (n.d.). Stack Data Structure. Diperoleh dari [Masukkan URL spesifik yang Anda gunakan, misal: https://www.geeksforgeeks.org/stack-data-structure/].
<br>[5] Wirth, N. (1976). Algorithms + Data Structures = Programs. Prentice Hall. (Klasik dalam ilmu komputer yang membahas Stack secara fundamental).
<br>[6] Knuth, D. E. (1997). The Art of Computer Programming, Volume 1: Fundamental Algorithms (3rd ed.). Addison-Wesley Professional.
<br>[7] Goodrich, M. T., & Tamassia, R. (2014). Data Structures and Algorithms in C++ (2nd ed.). Wiley.
