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