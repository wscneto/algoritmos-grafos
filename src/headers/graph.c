#include <stdio.h>
#include <stdlib.h>
#include "../../include/graph.h"

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

void addEdge(Graph* graph, int src, int dest, int cost, int isDirected) {
    Vertex* newNode = malloc(sizeof(Vertex));
    if (newNode == NULL) 
    {
        fprintf(stderr, "Erro: malloc falhou em addEdge.\n");
        exit(EXIT_FAILURE);
    }

    /* GRAFO DIRECIONADO */
    newNode->vertex = dest;
    newNode->cost = cost;
    newNode->next = NULL;

    if (graph->adjLists[src] == NULL) graph->adjLists[src] = newNode; 
    else
    {
        Vertex* temp = graph->adjLists[src];
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    
    if(!isDirected)
    {
        Vertex* newNodeReverse = malloc(sizeof(Vertex));
        if (newNodeReverse == NULL) 
        {
            fprintf(stderr, "Erro: malloc falhou em addEdge.\n");
            exit(EXIT_FAILURE);
        }

        newNodeReverse->vertex = src;
        newNodeReverse->cost = cost;
        newNodeReverse->next = NULL;

        if (graph->adjLists[dest] == NULL) graph->adjLists[dest] = newNodeReverse;
        else
        {
            Vertex* temp = graph->adjLists[dest];
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNodeReverse;
        }
    }
}

void printGraph(Graph* graph)
{
    printf("Vértice: Lista de adjacência\n");
    for(int v = 0; v < graph->numVertices; v++)
    {
        Vertex* temp = graph->adjLists[v];
        printf("%d --->", v+1);
        while(temp)
        {
            printf("(%d) %d -->", temp->cost, temp->vertex+1);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}
