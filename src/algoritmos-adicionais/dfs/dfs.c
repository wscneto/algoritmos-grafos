#include <stdio.h>
#include <stdlib.h>
#include "../../../include/graph.h"

void DFSHelper(Graph* graph, int vertex, int* visited)
{
    // Marca o vértice atual como visitado
    visited[vertex] = 1;
    printf("Vértice visitado: %d\n", vertex);

    // Visita todos os vértices adjacentes recursivamente
    Vertex* adjVertex = graph->adjLists[vertex];
    while(adjVertex != NULL)
    {
        int connectedVertex = adjVertex->vertex;
        
        // Se um vértice adjacente não foi visitado, chama DFSHelper recursivamente para esse vértice.
        if(!visited[connectedVertex])
        {
            DFSHelper(graph, connectedVertex, visited);
        }

        adjVertex = adjVertex->next;
    }
}

void DFS(Graph* graph, int startVertex)
{
    // Cria array para guardar vértices visitados.
    int* visited = calloc(graph->numVertices, sizeof(int));
    if(!visited)
    {
        printf("Erro na alocação de memória para visited.");
        exit(EXIT_FAILURE);
    }

    DFSHelper(graph, startVertex, visited);

    // Verifica se sobraram vértices não visitados.
    // Útil para descobrir componentes conexas de um grafo desconexo.
    for(int i = 0; i < graph->numVertices; i++)
    {
        if(!visited[i])
        {
            DFSHelper(graph, i, visited);
        }
    }

    free(visited);
}

int main()
{
    // Cria grafo não direcionado com 5 vértices.
    Graph* graph = createGraph(5, 0);
    
    addEdge(graph, 0, 1);
    //addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    //addEdge(graph, 3, 4);
    
    printGraph(graph);
    
    // Realiza DFS começando pelo vértice 0.
    DFS(graph, 0);
    
    deleteGraph(graph);

    return 0;
}