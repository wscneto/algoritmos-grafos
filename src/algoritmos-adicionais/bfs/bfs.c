#include <stdio.h>
#include <stdlib.h>
#include "../../../include/graph.h"
#include "../../../include/queue.h"

void printBFSTree(int* parent, int numVertices, int startVertex)
{
    printf("\nÁrvore BFS:\n");
    printf("Raíz: %d\n", startVertex);
    
    int* depth = calloc(numVertices, sizeof(int));

    if(!depth)
    {
        printf("Erro na alocação de memória para depth.");
        exit(EXIT_FAILURE);
    }

    depth[startVertex] = 0;
    
    for(int i = 0; i < numVertices; i++)
    {
        if(i != startVertex && parent[i] != -1)
        {
            depth[i] = depth[parent[i]] + 1;
        }
    }
    
    int maxDepth = 0;
    for(int i = 0; i < numVertices; i++)
    {
        if(parent[i] != -1 && depth[i] > maxDepth)
        {
            maxDepth = depth[i];
        }
    }
    
    for(int d = 0; d <= maxDepth; d++)
    {
        printf("Nível %d: ", d);
        for(int i = 0; i < numVertices; i++)
        {
            if(depth[i] == d)
            {
                if(d == 0)
                {
                    printf("%d (raíz) ", i);
                }
                else
                {
                    printf("%d (filho de %d) ", i, parent[i]);
                }
            }
        }

        printf("\n");
    }
    
    free(depth);
}

void BFS(Graph* graph, int startVertex)
{
    if(startVertex < 0 || startVertex >= graph->numVertices)
    {
        printf("Vértice inicial inválido\n");
        exit(EXIT_FAILURE);
    }

    Queue* queue = createQueue(graph->numVertices);
    
    int* visited = calloc(graph->numVertices, sizeof(int));

    if(!visited)
    {
        printf("Erro na alocação de memória para visited.");
        exit(EXIT_FAILURE);
    }
    
    int* parent = malloc(graph->numVertices * sizeof(int));

    if(!parent)
    {
        printf("Erro na alocação de memória para parent.");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < graph->numVertices; i++)
    {
        parent[i] = -1;
    }
    
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    
    printf("Algoritmo BFS começando pelo vértice %d:\n", startVertex);
    
    while(!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        
        Vertex* temp = graph->adjLists[currentVertex];
        
        while(temp)
        {
            int adjVertex = temp->vertex;
            
            if(!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                parent[adjVertex] = currentVertex;
                enqueue(queue, adjVertex);
            }

            temp = temp->next;
        }
    }
    
    printf("\n");
    
    printBFSTree(parent, graph->numVertices, startVertex);
    
    free(queue->array);
    free(queue);
    free(visited);
    free(parent);
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

        addUnweightedEdge(graph, src, dest, 0); // isDireted set to 0 by default.
    }
    
    printGraph(graph);
    
    BFS(graph, 0);
    
    deleteGraph(graph);
    
    return 0;
}