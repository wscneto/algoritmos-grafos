#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Vertex* createVertex(int v, Vertex* w)
{
    Vertex* newVertex = malloc(sizeof(Vertex));
    if(!newVertex)
    {
        printf("\nErro na alocação de memória para o vértice.\n");
        exit(EXIT_FAILURE);
    }
    newVertex->vertex = v;
    newVertex->cost = 0;
    newVertex->next = w;

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

Graph* createGraph(int numVertices)
{
    Graph* graph = malloc(sizeof(Graph));
    if(!graph)
    {
        printf("Erro na alocação de memória para grafo.\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;
    graph->numEdges = 0;
    graph->adjLists = malloc(numVertices * sizeof(Vertex*));

    if(!graph->adjLists)
    {
        printf("Erro na alocação de memória para listas de adjacência.");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < numVertices; i++) graph->adjLists[i] = NULL;

    return graph;
}

// Handles weighted graphs.
void addWeightedEdge(Graph* graph, int src, int dest, int cost, int isDirected)
{
    for(Vertex* a = graph->adjLists[src]; a != NULL; a = a->next) 
        if(a->vertex == dest) return;

    graph->adjLists[src] = createVertex(dest, graph->adjLists[src]);
    graph->adjLists[src]->cost = cost;

    // Handles undirected graphs.
    if(!isDirected)
    {
        graph->adjLists[dest] = createVertex(src, graph->adjLists[dest]);
        graph->adjLists[dest]->cost = cost;
    }
    
    graph->numEdges++;
}

// Handles unweighted graphs.
void addUnweightedEdge(Graph* graph, int src, int dest, int isDirected)
{
    for(Vertex* a = graph->adjLists[src]; a != NULL; a = a->next) 
        if(a->vertex == dest) return;

    graph->adjLists[src] = createVertex(dest, graph->adjLists[src]);

    // Handles undirected graphs.
    if(!isDirected)
    {
        graph->adjLists[dest] = createVertex(src, graph->adjLists[dest]);
    }

    graph->numEdges++;
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
            printf("(%d) %d -->", temp->cost, temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}