#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "../../include/graph.h"
#include "../../include/heap.h"
#define INFINITY INT_MAX

void primMST(Graph* graph, int start, FILE* output, int printSolution)
{
    int V = graph->numVertices;
    int* parent = malloc(V * sizeof(int));
    int* key = malloc(V * sizeof(int));
    MinHeap* heap = createHeap(V);

    for(int v = 0; v < V; v++)
    {
        parent[v] = -1;
        key[v] = INFINITY;
        heap->nodes[v].vertex = v;
        heap->nodes[v].dist = INFINITY;
        heap->pos[v] = v;
    }

    key[start] = 0;
    heap->nodes[start].dist = 0;
    heap->size = V;

    while(!isEmpty(heap))
    {
        HeapNode minNode = extractMin(heap);
        int u = minNode.vertex;

        Vertex* temp = graph->adjLists[u];
        while(temp)
        {
            int v = temp->vertex;
            if(isInMinHeap(heap, v) && temp->cost < key[v])
            {
                key[v] = temp->cost;
                parent[v] = u;
                decreaseKey(heap, v, key[v]);
            }
            temp = temp->next;
        }
    }

    int totalCost = 0;
    for(int i = 0; i < V; i++)
    {
        if(parent[i] != -1)
        {
            totalCost += key[i];
            if(printSolution)
                fprintf(output, "(%d,%d) ", parent[i]+1, i+1);
        }
    }

    if(printSolution) fprintf(output, "\n");
    else fprintf(output, "%d\n", totalCost);

    freeHeap(heap);
    free(parent);
    free(key);
}

void printHelp()
{
    printf("Uso: ./prim -f <arquivo_entrada> -o <arquivo_saida> -i <vertice_inicial>\n");
    printf("Parâmetros:\n");
    printf("  -h               Mostra essa mensagem de ajuda\n");
    printf("  -o <arquivo>     Arquivo de saída para os resultados\n");
    printf("  -f <arquivo>     Arquivo de entrada com o grafo\n");
    printf("  -s               Mostra a solução (arestas da árvore)\n");
    printf("  -i <vértice>     Vértice inicial para o algoritmo de Prim\n");
}

int main(int argc, char* argv[])
{
    char* inputArg = NULL;
    char* outputArg = NULL;
    int origin = -1;
    int printSolution = 0;

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-h") == 0)
        {
            printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) inputArg = argv[++i];
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) outputArg = argv[++i];
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) origin = atoi(argv[++i]) - 1;
        else if (strcmp(argv[i], "-s") == 0) printSolution = 1;
    }

    if(inputArg == NULL || origin < 0)
    {
        printf("Erro: você deve fornecer o arquivo de entrada (-f) e o vértice inicial (-i).\n");
        exit(EXIT_FAILURE);
    }

    FILE *inputFile = fopen(inputArg, "r");
    if(!inputFile)
    {
        printf("Erro ao abrir arquivo de entrada.\n");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = stdout;
    if(outputArg != NULL)
    {
        outputFile = fopen(outputArg, "w");
        if(!outputFile)
        {
            printf("Erro ao abrir arquivo de saída.\n");
            fclose(inputFile);
            exit(EXIT_FAILURE);
        }
    }

    int V, E;
    fscanf(inputFile, "%d %d", &V, &E);

    Graph* graph = createGraph(V);

    for(int i = 0; i < E; i++)
    {
        int src, dest, cost;
        fscanf(inputFile, "%d %d %d", &src, &dest, &cost);
        addEdge(graph, src - 1, dest - 1, cost, 0);
        //addEdge(graph, dest - 1, src - 1, cost);
    }

    primMST(graph, origin, outputFile, printSolution);

    deleteGraph(graph);
    fclose(inputFile);
    if(outputFile != stdout) fclose(outputFile);

    return 0;
}