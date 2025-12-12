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