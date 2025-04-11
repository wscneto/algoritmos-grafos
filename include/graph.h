#ifndef GRAPH_H
#define GRAPH_H

// DATA STRUCTURES:
typedef struct Vertex
{
    int vertex;
    struct Vertex* next;
} Vertex;

typedef struct Graph
{
    int numVertices;
    int numEdges;
    struct Vertex** adjLists;
} Graph;

// FUNCTIONS:
Vertex* createVertex(int v);
Graph* createGraph(int numVertices, int numEdges);
void deleteGraph(Graph* graph);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);

#endif