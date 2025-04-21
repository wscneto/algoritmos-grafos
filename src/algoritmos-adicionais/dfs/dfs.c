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
    int numVertices, numEdges;

    printf("Digite o número de vértices: ");
    scanf("%d", &numVertices);
    
    printf("Digite o número de arestas: ");
    scanf("%d", &numEdges);

    // Cria grafo com 'numVertices' vértices e 'numEdges' arestas.
    Graph* graph = createGraph(numVertices);
    
    for(int i = 0; i < numEdges; i++)
    {
        int src, dest;
        printf("Digite os vértices que compõem a %dª aresta: ", i + 1);
        scanf("%d %d", &src, &dest);

        addUnweightedEdge(graph, src, dest, 0); // isDirected set to 0 by default.
    }
    
    printGraph(graph);
    
    // Realiza DFS começando pelo vértice 0.
    DFS(graph, 0);
    
    deleteGraph(graph);

    return 0;
}