#ifndef GRAPH_H
#define GRAPH_H

// DATA STRUCTURES:
typedef struct Vertex
{
    int vertex;
    int cost;
    struct Vertex* next;
} Vertex;

typedef struct Graph
{
    int numVertices;
    int numEdges;
    struct Vertex** adjLists;
} Graph;

// FUNCTIONS:
Vertex* createVertex(int v, Vertex* w);
Graph* createGraph(int numVertices);
void deleteGraph(Graph* graph);
void addEdge(Graph* graph, int src, int dest, int cost, int isDirected);
void printGraph(Graph* graph);

#endif