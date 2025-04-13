#include <stdio.h>
#include <stdlib.h>

#define INF 999999

int menorDistancia(int dist[], int visitado[], int V)
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!visitado[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int **grafo, int V, FILE *saida, int origem)
{
    int dist[V];     // dist[i] será a menor distância de origem até i
    int visitado[V]; // visitado[i] será verdadeiro se o vértice i já foi processado

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = menorDistancia(dist, visitado, V);
        visitado[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visitado[v] && grafo[u][v] && dist[u] != INF && dist[u] + grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
    }

    printf("Vértice \t Distância a partir da origem\n");
    for (int i = 0; i < V; i++) fprintf(saida, "%d:%d ", i+1, dist[i]);
    fprintf(saida, "\n");
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

    int numVertices, numArestas;
    fscanf(entrada, "%d %d", &numVertices, &numArestas);

    int **matriz = malloc((numVertices) * sizeof(int *));
    for (int i = 0; i < numVertices; i++)
    {
        matriz[i] = malloc((numVertices) * sizeof(int));
        for (int j = 0; j < numVertices; j++) matriz[i][j] = INF;
    }

    // Lê as arestas
    for (int i = 0; i < numArestas; i++)
    {
        int v, w, cost;
        fscanf(entrada, "%d %d %d", &v, &w, &cost);
        matriz[v - 1][w - 1] = cost;
        matriz[w - 1][v - 1] = cost; // Se for grafo não-direcionado
    }

    dijkstra(matriz, numVertices, saida, origem - 1);

    // Libera a matriz
    for (int i = 0; i < numVertices; i++) free(matriz[i]);
    free(matriz);

    fclose(entrada);
    if (saida != stdout) fclose(saida);

    return 0;
}
