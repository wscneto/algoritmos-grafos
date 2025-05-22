#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/edge.h"
#include "../../include/subset.h"

void kruskalMST(int V, int E, Edge* edges, FILE* output, int printSolution)
{
    qsort(edges, E, sizeof(Edge), compareEdges);

    Subset* subsets = malloc(V * sizeof(Subset));
    for(int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int totalCost = 0;
    int edgeCount = 0;

    for(int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(subsets, u);
        int setV = find(subsets, v);

        if(setU != setV)
        {
            totalCost += edges[i].weight;
            if(printSolution)
                fprintf(output, "(%d,%d) ", u + 1, v + 1);
            unionSets(subsets, setU, setV);
            edgeCount++;
        }
    }

    if(printSolution)
        fprintf(output, "\n");
    else
        fprintf(output, "%d\n", totalCost);

    free(subsets);
}

void printHelp()
{
    printf("Uso: ./kruskal -f <arquivo_entrada> -o <arquivo_saida>\n");
    printf("Parâmetros:\n");
    printf("  -h               Mostra essa mensagem de ajuda\n");
    printf("  -o <arquivo>     Arquivo de saída para os resultados\n");
    printf("  -f <arquivo>     Arquivo de entrada com o grafo\n");
    printf("  -s               Mostra a solução (arestas da AGM)\n");
}

int main(int argc, char* argv[])
{
    char* inputArg = NULL;
    char* outputArg = NULL;
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
        else if (strcmp(argv[i], "-s") == 0) printSolution = 1;
    }

    if(inputArg == NULL)
    {
        printf("Erro: você deve fornecer o arquivo de entrada (-f).\n");
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

    // Verifica se fscanf() funcionou corretamente
    if(fscanf(inputFile, "%d %d", &V, &E) == 2)
    {
        Edge* edges = malloc(E * sizeof(Edge));

        for(int i = 0; i < E; i++)
        {
            int u, v, w;
            if(fscanf(inputFile, "%d %d %d", &u, &v, &w) == 3)
            {
                u--; v--;
                edges[i].src = u;
                edges[i].dest = v;
                edges[i].weight = w;
            }
            else
            {
                printf("Erro: fscanf() falhou ao receber instâncias de arestas e pesos.\n");
                fclose(inputFile);
                exit(EXIT_FAILURE);
            }
        }

        kruskalMST(V, E, edges, outputFile, printSolution);

        free(edges);
        fclose(inputFile);
        if (outputFile != stdout) fclose(outputFile);
    }
    else
    {
        printf("Erro: fscanf() falhou ao receber número de vértices e número de arestas.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    return 0;
}
