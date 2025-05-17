#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int src;
    int dest;
    int weight;
} Edge;

typedef struct
{
    int parent;
    int rank;
} Subset;

int compareEdges(const void* a, const void* b)
{
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

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
    fscanf(inputFile, "%d %d", &V, &E);
    Edge* edges = malloc(E * sizeof(Edge));

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        fscanf(inputFile, "%d %d %d", &u, &v, &w);
        u--; v--;
        edges[i].src = u;
        edges[i].dest = v;
        edges[i].weight = w;
    }

    kruskalMST(V, E, edges, outputFile, printSolution);

    free(edges);
    fclose(inputFile);
    if (outputFile != stdout) fclose(outputFile);

    return 0;
}
