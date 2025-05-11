#include <stdio.h>
#include <stdlib.h>
#include "../../../include/graph.h"

typedef struct 
{
    int father;
    int born;
    int dead;
} DFS;

void DFSrec(int v, Graph* G, int* born, int* dead, DFS* dfs)
{
    dfs[v].born = (*born)++;

    Vertex* w = G->adjLists[v];

    while(w)
    {
        if(dfs[w->vertex].born == -1)
        {
            dfs[w->vertex].father = v;
            DFSrec(w->vertex, G, born, dead, dfs);
        }

        w = w->next;
    }

    dfs[v].dead = (*dead)++;
}

void printDFS(Graph* G, DFS* dfs) 
{
    int V = G->numVertices;
    printf("Vértice | Born | Dead | Father\n");
    printf("-------------------------------\n");

    for(int v = 0; v < V; v++) {
        printf("   %2d   |  %2d  |  %2d  |   %2d\n", 
            v + 1, 
            dfs[v].born + 1, 
            dfs[v].dead + 1, 
            dfs[v].father + 1);
    }
}

DFS* DFSAlgorithm(Graph* G, DFS* dfs)
{
    int cont1 = 0, cont2 = 0, V = G->numVertices;

    for(int v = 0; v < V; v++)
    {
        dfs[v].father = -1;
        dfs[v].dead = -1;
        dfs[v].born = -1;
    }

    for(int v = 0; v < V; v++) 
    {
        if(dfs[v].born == -1)
        {
            dfs[v].father = v;
            DFSrec(v, G, &cont1, &cont2, dfs);
        }
    }

    return dfs;
}