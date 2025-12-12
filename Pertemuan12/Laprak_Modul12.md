# <h1 align="center">Laporan Praktikum Modul 14 GRAPH</h1>
<p align="center">Fatir Gibran - 103112430153 </p>

## Dasar Teori

Graph merupakan himpunan tak kosong yang terdiri dari node (disebut juga vertec) dan garis penghubung (edge). Node berfungsi menyimpan informasi, sementara edge menghubungkan node-node tersebut. Dalam implementasi struktur data, graph dapat direpresentasikan menggunakan Matriks Ketetanggaan (Adjacency Matrices) atau Multi Linked List. Multi Linked List dipilih dalam praktikum ini karena sifatnya yang dinamis, memungkinkan penanganan data yang fleksibel. Node utama (list Leader) berisi informasi node, dan setiap node memiliki list turunan (list Trailer) yang berisi alamat ke node yang terhubung (successor). Graph tidak berarah (Undirected Graph) adalah graph di mana setiap edge tidak memiliki arah, sehingga koneksi dari Node A ke Node B secara otomatis berarti koneksi dari Node B ke Node A. Proses penelusuran (traversal) pada graph yang umum dilakukan adalah Breadth First Search (BFS), yang mengunjungi node berdasarkan level/kedalaman, dan Depth First Search (DFS), yang mengunjungi node dengan menelusuri secara rekursif ke dalam subtree hingga mencapai kedalaman maksimum.

## Guided 

### 1. Implementasi Graph Tidak Berarah (Undirected Graph) dengan Multi Linked List dan Traversal (BFS & DFS)

#### graph.h
```C++
#ifndef Graph_H
#define Graph_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrNode Next;
    adrEdge firstEdge;
};
struct ElmEdge{
    adrNode Node;
    adrEdge Next;
};

struct Graph{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode NodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```
#### main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;
int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');
    
    cout <<"=== REPRESENTASI ADJACENCY LIST ==="<< endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL BFS DAN DFS ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    cout <<"=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil terhapus." << endl;
    } else {
        cout << "Node E tidak berhasil terhapus." << endl;
    }
    cout << endl;
    
    cout <<"=== REPRESENTASI ADJACENCY LIST ==="<< endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    return 0;
}
```
#### Output Guided 1

![Screenshot Output guided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan12/OUTPUT/Guided1.png)

#### Penjelasan

Guided 1 mengimplementasikan Abstract Data Type (ADT) Graph Tidak Berarah menggunakan Multi Linked List di C++. Fungsi InsertNode digunakan untuk membuat node baru dan menambahkannya ke list utama graph secara insert last. ConnectNode membuat edge bolak-balik antara dua node (karena ini undirected graph), menggunakan prinsip insert first pada list edge (trailer) node sumber. Fungsi PrintInfoGraph menampilkan representasi graph dalam bentuk Adjacency List. Selanjutnya, PrintBFS mengimplementasikan Breadth First Search menggunakan Queue untuk menjamin penelusuran per level, dan PrintDFS mengimplementasikan Depth First Search menggunakan Stack untuk menjamin penelusuran mendalam. Terakhir, DeleteNode berhasil menghapus Node 'E' dengan terlebih dahulu menghapus semua edge yang masuk dan keluar (incoming dan outgoing edges) dari 'E' (yaitu edge B-E, C-E, F-E), sebelum menghapus Node 'E' itu sendiri dari list utama.

## Unguided 

### 1. Buatlah ADT Graph tidak berarah file “graph.h”
  
![Screenshot Soal Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan12/OUTPUT/Soal1.png)

#### graph.h
```C++
#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

typedef char infoGraph;
struct ElmNode;
struct ElmEdge;
typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge; 

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

adrNode AllocateNode(infoGraph X);
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode FindNode(Graph G, infoGraph X);

#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

adrNode AllocateNode(infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0; 
    N->firstEdge = nullptr;
    N->Next = nullptr;
    return N;
}

void CreateGraph(Graph &G) {
    G.First = nullptr;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != nullptr) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return nullptr;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = AllocateNode(X);
    if (G.First == nullptr) {
        G.First = newNode;
    } else {
        adrNode Last = G.First;
        while (Last->Next != nullptr) {
            Last = Last->Next;
        }
        Last->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    auto createEdge = [](adrNode source, adrNode dest) {
        adrEdge newEdge = new ElmEdge;
        newEdge->Node = dest;
        newEdge->Next = source->firstEdge; 
        source->firstEdge = newEdge;
    };
    
    createEdge(N1, N2);
    
    createEdge(N2, N1);
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    if (P == nullptr) {
        cout << "Graph kosong." << endl;
        return;
    }
    cout << "--- Struktur Graph (ADT Dasar) ---" << endl;
    while (P != nullptr) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        if (E == nullptr) {
            cout << "(Tidak ada koneksi)";
        }
        while (E != nullptr) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
    cout << "------------------------------------" << endl;
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

void buildGraph(Graph &G) {
    InsertNode(G, 'A'); InsertNode(G, 'B'); InsertNode(G, 'C'); InsertNode(G, 'D');
    InsertNode(G, 'E'); InsertNode(G, 'F'); InsertNode(G, 'G'); InsertNode(G, 'H');

    adrNode N_A = FindNode(G, 'A'); adrNode N_B = FindNode(G, 'B');
    adrNode N_C = FindNode(G, 'C'); adrNode N_D = FindNode(G, 'D');
    adrNode N_E = FindNode(G, 'E'); adrNode N_F = FindNode(G, 'F');
    adrNode N_G = FindNode(G, 'G'); adrNode N_H = FindNode(G, 'H');

    ConnectNode(N_A, N_B); ConnectNode(N_A, N_C);
    ConnectNode(N_B, N_D); ConnectNode(N_B, N_E);
    ConnectNode(N_C, N_F); ConnectNode(N_C, N_G);
    ConnectNode(N_D, N_H); ConnectNode(N_E, N_H);
    ConnectNode(N_F, N_H); ConnectNode(N_G, N_H);
}

int main() {
    Graph G;
    CreateGraph(G);

    cout << "--- Soal 1: Implementasi ADT Graph Dasar (Multilist) ---" << endl;
    
    buildGraph(G);
    
    PrintInfoGraph(G);

    cout << "\nVerifikasi Keterhubungan (Graph Tidak Berarah):" << endl;
    if (FindNode(G, 'A') != nullptr && FindNode(G, 'B') != nullptr) {
        cout << "Node A ditemukan. Node B ditemukan." << endl;
    }
    
    return 0;
}
```

#### Output Unguided 1

![Screenshot Output Unguided 1](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan12/OUTPUT/Unguided1.png)

#### Penjelasan

Soal Unguided 1 bertujuan untuk mengimplementasikan ADT dasar Graph Tidak Berarah menggunakan Multi Linked List, mengikuti struktur yang didefinisikan pada modul. Implementasi ini mencakup definisi struktur ElmNode (list Leader) dan ElmEdge (list Trailer), serta fungsi primitif AllocateNode, CreateGraph, FindNode, InsertNode, ConnectNode, dan PrintInfoGraph. Pada main.cpp, fungsi buildGraph digunakan untuk membuat node A hingga H dan menghubungkannya sesuai ilustrasi graph yang diberikan pada modul. ConnectNode memastikan koneksi dua arah (misalnya A-B dan B-A), dan PrintInfoGraph menampilkan representasi daftar ketetanggaan (Adjacency List) dari graph yang berhasil dibangun.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran, DFS prosedur PrintDFS (Graph G, adrNode N);

#### graph.h
```C++
#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

typedef char infoGraph;
struct ElmNode;
struct ElmEdge;
typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge; 

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};
struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};
struct Graph {
    adrNode First;
};

adrNode AllocateNode(infoGraph X);
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode FindNode(Graph G, infoGraph X);

void ResetVisited(Graph &G);
void PrintDFS(Graph G, infoGraph startInfo);

#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <stack> 

using namespace std;

adrNode AllocateNode(infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0; 
    N->firstEdge = nullptr;
    N->Next = nullptr;
    return N;
}

void CreateGraph(Graph &G) {
    G.First = nullptr;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != nullptr) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return nullptr;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = AllocateNode(X);
    if (G.First == nullptr) {
        G.First = newNode;
    } else {
        adrNode Last = G.First;
        while (Last->Next != nullptr) {
            Last = Last->Next;
        }
        Last->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    auto createEdge = [](adrNode source, adrNode dest) {
        adrEdge newEdge = new ElmEdge;
        newEdge->Node = dest;
        newEdge->Next = source->firstEdge; 
        source->firstEdge = newEdge;
    };
    
    createEdge(N1, N2);
    
    createEdge(N2, N1);
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    if (P == nullptr) {
        cout << "Graph kosong." << endl;
        return;
    }
    cout << "--- Struktur Graph (ADT Dasar) ---" << endl;
    while (P != nullptr) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        if (E == nullptr) {
            cout << "(Tidak ada koneksi)";
        }
        while (E != nullptr) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
    cout << "------------------------------------" << endl;
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != nullptr) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(Graph G, infoGraph startInfo) {
    adrNode startNode = FindNode(G, startInfo);
    if (startNode == nullptr) {
        cout << "Node awal '" << startInfo << "' tidak ditemukan." << endl;
        return;
    }

    ResetVisited(G); 
    cout << "\nHasil Penelusuran DFS (Mulai dari " << startInfo << "): ";
    
    stack<adrNode> S;
    S.push(startNode);

    while (!S.empty()) {
        adrNode X = S.top(); 
        S.pop();

        if (X->visited == 0) {
            X->visited = 1; 
            cout << X->info << " "; 

            adrEdge E = X->firstEdge;
            stack<adrNode> neighbors;
            while (E != nullptr) {
                if (E->Node->visited == 0) {
                    neighbors.push(E->Node); 
                }
                E = E->Next;
            }
            while (!neighbors.empty()) {
                S.push(neighbors.top()); 
                neighbors.pop();
            }
        }
    }
    cout << endl;
}
```

#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

void buildGraph(Graph &G) {
    InsertNode(G, 'A'); InsertNode(G, 'B'); InsertNode(G, 'C'); InsertNode(G, 'D');
    InsertNode(G, 'E'); InsertNode(G, 'F'); InsertNode(G, 'G'); InsertNode(G, 'H');

    adrNode N_A = FindNode(G, 'A'); adrNode N_B = FindNode(G, 'B');
    adrNode N_C = FindNode(G, 'C'); adrNode N_D = FindNode(G, 'D');
    adrNode N_E = FindNode(G, 'E'); adrNode N_F = FindNode(G, 'F');
    adrNode N_G = FindNode(G, 'G'); adrNode N_H = FindNode(G, 'H');

    ConnectNode(N_A, N_B); ConnectNode(N_A, N_C);
    ConnectNode(N_B, N_D); ConnectNode(N_B, N_E);
    ConnectNode(N_C, N_F); ConnectNode(N_C, N_G);
    ConnectNode(N_D, N_H); ConnectNode(N_E, N_H);
    ConnectNode(N_F, N_H); ConnectNode(N_G, N_H);
}

int main() {
    Graph G;
    CreateGraph(G);

    cout << "--- Soal 2: Uji Coba Depth First Search (DFS) ---" << endl;
    
    buildGraph(G);
    
    PrintDFS(G, 'A'); 
    
    return 0;
}
```

#### Output Unguided 2

![Screenshot Output Unguided 2](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan12/OUTPUT/Unguided2.png)

#### Penjelasan

Soal Unguided 2 mengimplementasikan prosedur Depth First Search (DFS), yaitu PrintDFS, untuk menelusuri graph dimulai dari Node 'A'. Sesuai algoritma DFS, implementasi ini menggunakan struktur data Stack. Node awal dimasukkan ke stack, dan selama stack tidak kosong, node dikeluarkan (pop), ditandai sebagai dikunjungi, dan dicetak. Tetangganya yang belum dikunjungi kemudian dimasukkan kembali ke stack. Karena Multi Linked List menyimpan edge secara InsertFirst, urutan penelusuran yang dihasilkan menunjukkan prioritas DFS: A, kemudian masuk ke cabang B (D, H, E), lalu kembali ke C (F, G).

### 3.  Buatlah prosedur untuk menampilkanhasil penelusuran DFS.Prosedur PrintBFS (Graph G, adrNode N);

#### graph.h
```C++
#ifndef GRAPH_H_INCLUDE
#define GRAPH_H_INCLUDE

typedef char infoGraph;
struct ElmNode;
struct ElmEdge;
typedef ElmNode* adrNode;
typedef ElmEdge* adrEdge; 

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};
struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};
struct Graph {
    adrNode First;
};

adrNode AllocateNode(infoGraph X);
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode FindNode(Graph G, infoGraph X);

void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph startInfo);

#endif
```

#### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> 

using namespace std;

adrNode AllocateNode(infoGraph X) {
    adrNode N = new ElmNode;
    N->info = X;
    N->visited = 0; 
    N->firstEdge = nullptr;
    N->Next = nullptr;
    return N;
}

void CreateGraph(Graph &G) {
    G.First = nullptr;
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != nullptr) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return nullptr;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode newNode = AllocateNode(X);
    if (G.First == nullptr) {
        G.First = newNode;
    } else {
        adrNode Last = G.First;
        while (Last->Next != nullptr) {
            Last = Last->Next;
        }
        Last->Next = newNode;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    auto createEdge = [](adrNode source, adrNode dest) {
        adrEdge newEdge = new ElmEdge;
        newEdge->Node = dest;
        newEdge->Next = source->firstEdge; 
        source->firstEdge = newEdge;
    };
    
    createEdge(N1, N2);
    
    createEdge(N2, N1);
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    if (P == nullptr) {
        cout << "Graph kosong." << endl;
        return;
    }
    cout << "--- Struktur Graph (ADT Dasar) ---" << endl;
    while (P != nullptr) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        if (E == nullptr) {
            cout << "(Tidak ada koneksi)";
        }
        while (E != nullptr) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
    cout << "------------------------------------" << endl;
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != nullptr) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintBFS(Graph G, infoGraph startInfo) {
    adrNode startNode = FindNode(G, startInfo);
    if (startNode == nullptr) {
        cout << "Node awal '" << startInfo << "' tidak ditemukan." << endl;
        return;
    }

    ResetVisited(G); 
    cout << "\nHasil Penelusuran BFS (Mulai dari " << startInfo << "): ";
    
    queue<adrNode> Q;
    Q.push(startNode); 
    startNode->visited = 1; 

    while (!Q.empty()) { 
        adrNode X = Q.front(); 
        Q.pop();

        cout << X->info << " "; 

        adrEdge E = X->firstEdge;
        while (E != nullptr) {
            adrNode W = E->Node;
            if (W->visited == 0) { 
                W->visited = 1; 
                Q.push(W); 
            }
            E = E->Next;
        }
    }
    cout << endl;
}
```
#### main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

void buildGraph(Graph &G) {
    InsertNode(G, 'A'); InsertNode(G, 'B'); InsertNode(G, 'C'); InsertNode(G, 'D');
    InsertNode(G, 'E'); InsertNode(G, 'F'); InsertNode(G, 'G'); InsertNode(G, 'H');

    adrNode N_A = FindNode(G, 'A'); adrNode N_B = FindNode(G, 'B');
    adrNode N_C = FindNode(G, 'C'); adrNode N_D = FindNode(G, 'D');
    adrNode N_E = FindNode(G, 'E'); adrNode N_F = FindNode(G, 'F');
    adrNode N_G = FindNode(G, 'G'); adrNode N_H = FindNode(G, 'H');

    ConnectNode(N_A, N_B); ConnectNode(N_A, N_C);
    ConnectNode(N_B, N_D); ConnectNode(N_B, N_E);
    ConnectNode(N_C, N_F); ConnectNode(N_C, N_G);
    ConnectNode(N_D, N_H); ConnectNode(N_E, N_H);
    ConnectNode(N_F, N_H); ConnectNode(N_G, N_H);
}

int main() {
    Graph G;
    CreateGraph(G);

    cout << "--- Soal 3: Uji Coba Breadth First Search (BFS) ---" << endl;
    
    buildGraph(G);
    
    PrintBFS(G, 'A'); 
    
    return 0;
}
```

#### Output Unguided 3

![Screenshot Output Unguided 3](https://github.com/Fatirrr08/103112430153_Fatir-Gibran/blob/master/Pertemuan12/OUTPUT/Unguided3.png)

#### Penjelasan

Soal Unguided 3 mengimplementasikan prosedur Breadth First Search (BFS), yaitu PrintBFS, untuk menelusuri graph, juga dimulai dari Node 'A'. Sesuai algoritma BFS, implementasi ini menggunakan struktur data Queue. Node awal dimasukkan ke queue dan ditandai dikunjungi. Selama queue tidak kosong, node dikeluarkan (dequeue), dicetak, dan semua tetangganya yang belum dikunjungi dimasukkan ke queue. Hasil penelusuran (A B C D E F G H) secara jelas menunjukkan prinsip BFS: penelusuran dilakukan per level kedalaman (Level 1: A, Level 2: B dan C, Level 3: D, E, F, G, Level 4: H).

## Kesimpulan

Implementasi ADT Graph menggunakan Multi Linked List merupakan metode yang efektif untuk merepresentasikan struktur data dinamis. Struktur ini berhasil memisahkan node utama (list Leader) dari koneksi (list Trailer/edge), memungkinkan operasi dasar seperti penambahan node dan koneksi dua arah (ConnectNode untuk undirected graph). Dua metode penelusuran utama, Depth First Search (DFS), yang memanfaatkan Stack, dan Breadth First Search (BFS), yang memanfaatkan Queue, berhasil diimplementasikan untuk memberikan urutan kunjungan node yang berbeda, sesuai dengan fungsinya masing-masing: DFS menelusuri kedalaman terlebih dahulu, sementara BFS menelusuri per level.

## Referensi

[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms, Fourth Edition. The MIT Press.
<br>[2] Tarjan, R. E. (1972). Depth-First Search and Linear Graph Algorithms. SIAM Journal on Computing, 1(2), 146–160.
<br>[3] Knuth, D. E. (1997). The Art of Computer Programming, Volume 1: Fundamental Algorithms, Third Edition. Addison-Wesley Professional.
<br>[4] Sedgewick, R., & Wayne, K. (2011). Algorithms, Fourth Edition. Addison-Wesley Professional.
<br>[5] Brandes, U., & Erlebach, T. (Eds.). (2005). Graph Drawing: 12th International Symposium, GD 2004, New York, NY, USA, September 29–October 2, 2004, Revised Selected Papers. Springer-Verlag.