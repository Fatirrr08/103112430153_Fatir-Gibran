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