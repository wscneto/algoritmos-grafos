#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Vertex* createVertex(int v)
{
    Vertex* newVertex = malloc(sizeof(Vertex));
    if(!newVertex)
    {
        printf("Erro na alocação de memória para o vértice.\n");
        exit(EXIT_FAILURE);
    }
    newVertex->vertex = v;
    newVertex->next = NULL;

    return newVertex;
}

void deleteGraph(Graph* graph)
{
    if(!graph) return;

    for(int i = 0; i < graph->numVertices; i++)
    {
        Vertex* curr = graph->adjLists[i];
        
        while(curr)
        {
            Vertex* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(graph->adjLists);
    free(graph);
}

Graph* createGraph(int numVertices, int isDirected)
{
    Graph* graph = malloc(sizeof(Graph));
    if(!graph)
    {
        printf("Erro na alocação de memória para grafo.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;
    graph->adjLists = malloc(numVertices * sizeof(Vertex*));
    if(!graph->adjLists)
    {
        printf("Erro na alocação de memória para listas de adjacência.");
        free(graph);
        exit(EXIT_FAILURE);
    }

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
    printf("Vértice: Lista de adjacência\n");
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