#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/graph.h"
#define INFINITY 999999

void bellman(Graph *G, int origem, FILE *saida)
{
    int V = G->numVertices;
    int *dist = malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
        dist[i] = INFINITY;

    dist[origem] = 0;
    
    for(int v = 0; v < V - 1; v++)
    {
        for (int v = 0; v < V; v++)
        {
            Vertex* w = G->adjLists[v];

            while (w) 
            {
                if (dist[v] != INFINITY && dist[v] + w->cost < dist[w->vertex]) 
                    dist[w->vertex] = dist[v] + w->cost;
                w = w->next;
            }
        }
    }

    for (int v = 0; v < V; v++)
    {
        Vertex* w = G->adjLists[v];

        while (w) 
        {
            if (dist[v] != INFINITY && dist[v] + w->cost < dist[w->vertex]) 
            {
                if(!saida) printf("FALSE\n");
                else fprintf(saida, "FALSE\n");
                
                free(dist);
                return;
            }

            w = w->next;
        }
    }

    if(!saida) printf("TRUE\n");
    else fprintf(saida, "TRUE\n");
        
    for (int i = 0; i < V; i++)
    {
        if(!saida) printf("%d:%d ", i + 1, dist[i] != INFINITY ? dist[i] : -1);
        else fprintf(saida, "%d:%d ", i + 1, dist[i] != INFINITY ? dist[i] : -1);
    }
    free(dist);
}

void printHelp()
{
    printf("Uso: ./bellman -f <arquivo_entrada> -o <arquivo_saida> -i <vertice_inicial>\n");
    printf("Parâmetros:\n");
    printf("  -h               Mostra essa mensagem de ajuda\n");
    printf("  -f <arquivo>     Arquivo de entrada com o grafo\n");
    printf("  -o <arquivo>     Arquivo de saída para os resultados\n");
    printf("  -i <vértice>     Vértice inicial para o algoritmo de Dijkstra\n");
}

int main(int argc, char *argv[])
{
    char *inputFile = NULL;
    char *outputFile = NULL;
    int origem = -1;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            printHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) inputFile = argv[++i];
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) outputFile = argv[++i];
        else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) origem = atoi(argv[++i]);
    }

    if (inputFile == NULL || origem == -1)
    {
        printf("Erro: você deve fornecer o arquivo de entrada (-f) e o vértice inicial (-i).\n");
        exit(EXIT_FAILURE);
    }

    FILE *entrada = fopen(inputFile, "r");
    if (!entrada)
    {
        printf("Erro ao abrir arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }

    FILE *saida = stdout;
    if (outputFile != NULL)
    {
        saida = fopen(outputFile, "w");
        if (!saida)
        {
            printf("Erro ao abrir arquivo de saída\n");
            fclose(entrada);
            exit(EXIT_FAILURE);
        }
    }

    int numVertices, numArestas, v, w, cost;
    fscanf(entrada, "%d %d", &numVertices, &numArestas);

    Graph *G = createGraph(numVertices);
    
    for (int count = 0; count < numArestas; count++)
    {
        fscanf(entrada, "%d%d%d", &v, &w, &cost);
        addEdge(G, v-1, w-1, cost);
    }

    /* CHAMANDO O ALGORITMO */
    bellman(G, origem - 1, saida);

    deleteGraph(G);
    fclose(entrada);
    if (saida != stdout) fclose(saida);

    return 0;
}