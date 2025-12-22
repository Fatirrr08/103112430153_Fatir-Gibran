#include "graph.h"

void createGraph(GraphKota &G) {
    G.first = NULL;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->tujuan = tujuan;
    E->jarak = jarak;
    E->next = NULL;
    return E;
}

void insertNode(GraphKota &G, adrKota P) {
    P->next = G.first;
    G.first = P;
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        if (P->namaKota == nama) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(GraphKota &G, string A, string B, int jarak) {
    adrKota X = findNode(G,A);
    adrKota Y = findNode(G,B);
    if (X != NULL && Y != NULL) {
        adrEdge E1 = alokasiEdge(Y,jarak);
        E1->next = X->firstEdge;
        X->firstEdge = E1;
        adrEdge E2 = alokasiEdge(X,jarak);
        E2->next = Y->firstEdge;
        Y->firstEdge = E2;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        adrEdge *E = &P->firstEdge;
        while (*E != NULL) {
            if ((*E)->tujuan->namaKota == nama) {
                adrEdge temp = *E;
                *E = (*E)->next;
                delete temp;
                break;
            }
            E = &(*E)->next;
        }
        P = P->next;
    }
    adrKota *Q = &G.first;
    while (*Q != NULL) {
        if ((*Q)->namaKota == nama) {
            adrKota temp = *Q;
            *Q = (*Q)->next;
            delete temp;
            break;
        }
        Q = &(*Q)->next;
    }
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota P = G.first;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->tujuan->namaKota << " (" << E->jarak << " KM)";
            if (E->next != NULL) cout << ", ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota &G, string start) {
    resetVisited(G);
    queue<adrKota> Q;
    adrKota S = findNode(G,start);
    if (S != NULL) {
        S->visited = 1;
        Q.push(S);
        while (!Q.empty()) {
            adrKota P = Q.front();
            Q.pop();
            cout << P->namaKota << endl;
            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->tujuan->visited == 0) {
                    E->tujuan->visited = 1;
                    Q.push(E->tujuan);
                }
                E = E->next;
            }
        }
    }
}

void printDFS(GraphKota &G, string start) {
    resetVisited(G);
    stack<adrKota> S;
    S.push(findNode(G,start));
    while (!S.empty()) {
        adrKota P = S.top();
        S.pop();
        if (P != NULL && P->visited == 0) {
            P->visited = 1;
            cout << P->namaKota << endl;
            adrEdge E = P->firstEdge;
            while (E != NULL) {
                if (E->tujuan->visited == 0) {
                    S.push(E->tujuan);
                }
                E = E->next;
            }
        }
    }
}
