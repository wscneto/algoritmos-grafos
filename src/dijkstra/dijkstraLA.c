#include <stdio.h>
#include <stdlib.h>
#include "../../include/graph.h"
#define INFINITY 999999

typedef struct Dijkstra
{
    int pai;
    int custo;
} Dijkstra;

void dijkstra(Graph *G, Dijkstra custos[], int origem)
{
    int processados[G->numVertices];

    // Inicialização
    for (int i = 0; i < G->numVertices; i++)
    {
        custos[i].custo = INFINITY;
        custos[i].pai = -1;
        processados[i] = 0;
    }

    custos[origem].custo = 0;

    for (int count = 0; count < G->numVertices; count++)
    {
        // Encontra o vértice com menor custo não processado
        int min = INFINITY;
        int u = -1;

        for (int v = 0; v < G->numVertices; v++)
        {
            if (!processados[v] && custos[v].custo < min)
            {
                min = custos[v].custo;
                u = v;
            }
        }

        // Se não encontrou nenhum vértice, termina
        if (u == -1) continue;

        processados[u] = 1;
        printf("%d ", u);

        /* Caso queria visualizar cada iteração

        for (int v = 0; v < G->numVertices; v++) printf("%d ", custos[v].custo);
        printf("\n");
        */

        // Atualiza os custos dos vizinhos de u
        Vertex *w = G->adjLists[u];
        while (w != NULL)
        {
            int v = w->vertex;
            if (!processados[v])
            {
                int novo_custo = custos[u].custo + w->cost;
                if (novo_custo < custos[v].custo)
                {
                    custos[v].custo = novo_custo;
                    custos[v].pai = u;
                }
            }
            w = w->next;
        }
    }
}

void printHelp()
{
    printf("Uso: ./dijkstra -f <arquivo_entrada> -o <arquivo_saida> -i <vertice_inicial>\n");
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

    // Parse de argumentos
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
        fprintf(stderr, "Erro: você deve fornecer o arquivo de entrada (-f) e o vértice inicial (-i).\n");
        return 1;
    }

    FILE *entrada = fopen(inputFile, "r");
    if (!entrada)
    {
        perror("Erro ao abrir arquivo de entrada");
        return 1;
    }

    FILE *saida = stdout;
    if (outputFile != NULL)
    {
        saida = fopen(outputFile, "w");
        if (!saida)
        {
            perror("Erro ao abrir arquivo de saída");
            fclose(entrada);
            return 1;
        }
    }

    int numVertices, numArestas, v, w, cost;
    fscanf(entrada, "%d %d", &numVertices, &numArestas);
    Dijkstra custos[numVertices];

    Graph *G = createGraph(numVertices);
    for (int count = 0; count < numArestas; count++)
    {
        fscanf(entrada, "%d%d%d", &v, &w, &cost);
        addEdge(G, v-1, w-1, cost);
    }

    dijkstra(G, custos, origem - 1);

    for (int i = 0; i < numVertices; i++) fprintf(saida, "%d:%d ", i+1, custos[i].custo);

    fclose(entrada);
    if (saida != stdout) fclose(saida);

    deleteGraph(G); 

    return 0;
}
