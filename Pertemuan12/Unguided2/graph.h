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