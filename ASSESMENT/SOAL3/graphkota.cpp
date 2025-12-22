#include "graphKota.h"

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
    E->kotaTujuan = tujuan;
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

void disconnectNode(GraphKota &G, string A, string B) {
    adrKota X = findNode(G,A);
    adrKota Y = findNode(G,B);
    if (X != NULL && Y != NULL) {
        adrEdge *p = &X->firstEdge;
        while (*p != NULL) {
            if ((*p)->kotaTujuan == Y) {
                adrEdge temp = *p;
                *p = (*p)->next;
                delete temp;
                break;
            }
            p = &(*p)->next;
        }
        p = &Y->firstEdge;
        while (*p != NULL) {
            if ((*p)->kotaTujuan == X) {
                adrEdge temp = *p;
                *p = (*p)->next;
                delete temp;
                break;
            }
            p = &(*p)->next;
        }
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota P = G.first;
    while (P != NULL) {
        disconnectNode(G, P->namaKota, nama);
        P = P->next;
    }
    adrKota *q = &G.first;
    while (*q != NULL) {
        if ((*q)->namaKota == nama) {
            adrKota temp = *q;
            *q = (*q)->next;
            delete temp;
            break;
        }
        q = &(*q)->next;
    }
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota P = G.first;
    while (P != NULL) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->kotaTujuan->namaKota << " (" << E->jarak << " KM)";
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
                if (E->kotaTujuan->visited == 0) {
                    E->kotaTujuan->visited = 1;
                    Q.push(E->kotaTujuan);
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
                if (E->kotaTujuan->visited == 0) {
                    S.push(E->kotaTujuan);
                }
                E = E->next;
            }
        }
    }
}
