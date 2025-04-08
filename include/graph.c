#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Vertex* createVertex(int v)
{
    Vertex* newVertex = malloc(sizeof(Vertex));
    newVertex->vertex = v;
    newVertex->next = NULL;

    return newVertex;
}

void deleteGraph(Graph* graph)
{
    free(graph);
}

Graph* createGraph(int numVertices, int isDirected)
{
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;
    graph->adjLists = malloc(numVertices * sizeof(Vertex*));

    for(int i = 0; i < numVertices; i++)
    {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest)
{
    Vertex* newVertex = createVertex(dest);
    newVertex->next = graph->adjLists[src];
    graph->adjLists[src] = newVertex;

    if(!graph->isDirected)
    {
        newVertex = createVertex(src);
        newVertex->next = graph->adjLists[dest];
        graph->adjLists[dest] = newVertex;
    }
}

void printGraph(Graph* graph)
{
    printf("Vertex: Adjacency List\n");
    for(int v = 0; v < graph->numVertices; v++)
    {
        Vertex* temp = graph->adjLists[v];
        printf("%d --->", v);
        while(temp)
        {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}